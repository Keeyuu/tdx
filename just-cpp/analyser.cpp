#include<iostream>
#include<cmath>
#include<array>

typedef enum :int { NORMAL, TOP, LOW }FxType;


class KLine
{
    float close;
    float specialLow;
    float specialHigh;
    bool isSpecialHigh();
    bool isSpecialLow();
public:
    FxType checkFx(KLine& last, KLine& next);
    bool vaildFx(KLine* last);
};

FxType KLine::checkFx(KLine& last, KLine& next)
{
    int type = NORMAL;
    if (this->specialHigh > last.specialHigh && this->specialHigh > next.specialHigh) { type = TOP; };
    if (this->specialLow < last.specialLow && this->specialLow < next.specialLow) { type += LOW; };
    if (type >= 3) { type = fabs(this->specialLow - this->close) > fabs(this->specialHigh - this->close) ? LOW : TOP; }
    return FxType(type);
}

bool KLine::vaildFx(KLine* last)
{

}