#include"pch.h"
#include<iostream>
#include<cmath>
#include<vector>

typedef enum :int { NORMAL, TOP, LOW }FxType;
typedef  std::vector<KLine>::iterator KIter;
typedef std::vector<KLine> SequenceK;
typedef std::vector<int> SequenceT;
class KLine
{
    float close;
    float specialLow;
    float specialHigh;
    bool isSpecialHigh(KIter, KIter);
    bool isSpecialLow(KIter, KIter);
public:
    void reset(float inA, float inB, float inC) { close = inA, specialLow = inB, specialHigh = inC; };
    FxType checkFx(KIter, KIter);
    bool vaildFx(KIter);
};

class PriceAnalyser
{
    SequenceK* KLines;
    SequenceT* types;
    PriceAnalyser(int, float*, float*, float*);
    void findFx();
public:
};