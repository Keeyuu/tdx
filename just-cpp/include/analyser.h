#pragma once
#include<algorithm>
#include<tuple>
#ifndef ANALYSER_H
#define ANALYSER_H

typedef enum :int { NORMAL, TOP, LOW = -1 }FxType;

class KLine
{
	float open;
	float close;
	float diffMa;
	int specialInterval = 3;
	bool isSpecialHigh(KLine**, int, int);
	bool isSpecialLow(KLine**, int, int);
public:
	KLine(float inA, float inB, float inC) { open = inA, close = inB, diffMa = inC; };
	void reset(float inA, float inB, float inC) { open = inA, close = inB, diffMa = inC; };
	FxType checkFx(KLine**, int, int);
	bool vaildFx(KLine*, FxType, FxType);
	float getClose() { return close; }
};

class PriceAnalyser
{
	KLine** kLines;
	FxType* kTypes;
	int dataLen;
	void findFx();
	void checkFx();
public:
	float calcDiff(int, int);
	std::tuple<int, bool> getFx(FxType, int);
	void show();
	PriceAnalyser(int, float*, float*, float*);
	~PriceAnalyser();
};

#endif
