#include"pch.h"
#include"analyser.h"
#include<iostream>

FxType KLine::checkFx(KLine** items, int cursor, int dataLen)
{
	auto last = items[cursor - 1], now = items[cursor], next = items[cursor + 1];
	int type = NORMAL;
	if (this->specialHigh > last->specialHigh && this->specialHigh > next->specialHigh && this->isSpecialHigh(items, cursor, dataLen))  type = TOP;
	if (this->specialLow < last->specialLow && this->specialLow < next->specialLow && this->isSpecialLow(items, cursor, dataLen)) type += LOW;
	if (type >= FxType::LOW + FxType::TOP) type = fabs(this->specialLow - this->close) > fabs(this->specialHigh - this->close) ? LOW : TOP;
	return FxType(type);
}

bool  KLine::vaildFx(KLine* last, FxType lastType)
{
	//todo
	return true;
}

bool KLine::isSpecialHigh(KLine** items, int cursor, int dataLen)
{
	int left = 0, right = dataLen;
	if (cursor + this->specialInterval < dataLen)right = cursor + this->specialInterval;
	if (cursor - this->specialInterval > 0)left = cursor - this->specialInterval;
	for (int i = left; i <= right; i++) {
		if (items[i]->getHighValue() > items[cursor]->getHighValue())return false;
	}
	return true;
}

bool KLine::isSpecialLow(KLine** items, int cursor, int dataLen)
{
	int left = 0, right = dataLen;
	if (cursor + this->specialInterval < dataLen)right = cursor + this->specialInterval;
	if (cursor - this->specialInterval > 0)left = cursor - this->specialInterval;
	for (int i = left; i <= right; i++) {
		if (items[i]->getLowValue() < items[cursor]->getLowValue())return false;
	}
	return true;
}

PriceAnalyser::PriceAnalyser(int dataLen, float* inA, float* inB, float* inC)
{
	if (dataLen < 6)return;
	this->kLines = new KLine * [dataLen];
	this->kTypes = new FxType[dataLen]; this->kTypes[0] = FxType::NORMAL; this->kTypes[dataLen - 1] = FxType::NORMAL;
	this->dataLen = dataLen;
	for (int i = 0; i < dataLen; i++)
	{
		this->kLines[i] = new KLine(inA[i], inB[i], inC[i]);
	}
	this->findFx();
	this->checkFx();
}

PriceAnalyser::~PriceAnalyser()
{
	if (this->kLines != nullptr) {
		for (int i = 0; i < dataLen; i++) if (this->kLines[i] != nullptr)delete this->kLines[i];
		delete[]this->kLines;
	}
	if (this->kTypes != nullptr) delete[]this->kTypes;

}

void PriceAnalyser::findFx()
{
	if (this->dataLen <= 0) return;
	for (int i = 1; i < this->dataLen - 1; i++) {
		this->kTypes[i] = this->kLines[i]->checkFx(this->kLines, i, this->dataLen);
	}
}

void PriceAnalyser::checkFx()
{
	FxType lastType = FxType::NORMAL;
	int lastIndex = 0;
	for (int i = 0; i < this->dataLen; i++) {
		if (this->kTypes[i] != FxType::NORMAL) {
			if (lastType == FxType::NORMAL) {
				lastType = this->kTypes[i];
				lastIndex = i;
			}
			else {
				if (this->kLines[i]->vaildFx(this->kLines[lastIndex], lastType)) {
					lastType = this->kTypes[i];
					lastIndex = i;
				}
				else {
					this->kTypes[i] = FxType::NORMAL;
				}
			}
		}
	}
}

void PriceAnalyser::show()
{
	if (this->dataLen <= 0)return;
	std::cout << "kTypes: [";
	for (int i = 0; i < this->dataLen; i++) {
		std::cout << this->kTypes[i];
		if (i < dataLen - 1)std::cout << ",";
	}
	std::cout << "]" << std::endl;
}
