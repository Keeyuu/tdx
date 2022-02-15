#pragma once
#include<algorithm>
#ifndef ANALYSER_H
#define ANALYSER_H

typedef enum :int { NORMAL, TOP, LOW }FxType;
const float SPECIAL = 0.7;

class KLine
{
	float close;
	float specialLow;
	float specialHigh;
	int specialInterval = 3;
	bool isSpecialHigh(KLine**, int, int);
	bool isSpecialLow(KLine**, int, int);
public:
	KLine(float inA, float inB, float inC) { close = inA, specialLow = inB, specialHigh = inC; };
	void reset(float inA, float inB, float inC) { close = inA, specialLow = inB, specialHigh = inC; };
	FxType checkFx(KLine**, int, int);
	bool vaildFx(KLine*, FxType);
	float getHighValue() { return close * (1 - SPECIAL) + specialHigh * SPECIAL; }
	float getLowValue() { return close * (1 - SPECIAL) + specialLow * SPECIAL; }
};

class PriceAnalyser
{
	KLine** kLines;
	FxType* kTypes;
	int dataLen;
	void findFx();
	void checkFx();
public:
	void show();
	PriceAnalyser(int, float*, float*, float*);
	~PriceAnalyser();
};

#endif
