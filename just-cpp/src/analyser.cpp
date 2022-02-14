#include"analyser.h"

FxType KLine::checkFx(KIter InLast, KIter InNext)
{
    KLine& last = *InLast;KLine& next = *InNext;
    int type = NORMAL;
    if (this->specialHigh > last.specialHigh && this->specialHigh > next.specialHigh) { type = TOP; };
    if (this->specialLow < last.specialLow && this->specialLow < next.specialLow) { type += LOW; };
    if (type >= 3) { type = fabs(this->specialLow - this->close) > fabs(this->specialHigh - this->close) ? LOW : TOP; }
    return FxType(type);
}

bool  KLine::vaildFx(KIter last)
{

}

bool KLine::isSpecialHigh(KIter, KIter)
{

}

bool KLine::isSpecialLow(KIter, KIter)
{

}

PriceAnalyser::PriceAnalyser(int dataLen, float* inA, float* inB, float* inC)
{
    this->KLines = new SequenceK, this->KLines->resize(dataLen);
    for (int i = 0;i < dataLen;i++)
    {
        auto x = *(this->KLines->at(i));
    }
}