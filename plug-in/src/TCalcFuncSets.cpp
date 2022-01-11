#include "pch.h"
#include "TCalcFuncSets.h"
#include "plug.h"
#include<iostream>


GoSlice BuildGoSlice(int len, void* data)
{
    auto item = new GoSlice;
    item->len = len;
    item->cap = len;
    item->data = data;
    return *item;
}



void SingleStarPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
    auto flag = SingleStar(DataLen, BuildGoSlice(DataLen, pfINa), BuildGoSlice(DataLen, pfINb), BuildGoSlice(DataLen, pfINc));
    for (int i = 0; i < DataLen; i++)
    {
        pfOUT[i] = flag.r0;
        if (i == DataLen - 1)
        {
            pfOUT[i] = flag.r1;
        }
    }
}

void DoubleStarsPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
    auto flag = DoubleStars(DataLen, BuildGoSlice(DataLen, pfINa), BuildGoSlice(DataLen, pfINb), BuildGoSlice(DataLen, pfINc));
    for (int i = 0; i < DataLen; i++)
    {
        pfOUT[i] = flag.r0;
        if (i == DataLen - 1)
        {
            pfOUT[i] = flag.r1;
        }
    }
}


void ThreeStarsPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
    auto flag = ThreeStars(DataLen, BuildGoSlice(DataLen, pfINa), BuildGoSlice(DataLen, pfINb), BuildGoSlice(DataLen, pfINc));
    for (int i = 0; i < DataLen; i++)
    {
        pfOUT[i] = flag.r0;
        if (i == DataLen - 1)
        {
            pfOUT[i] = flag.r1;
        }
    }
}


void FindFxPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
    FindFx(DataLen, BuildGoSlice(DataLen, pfINa), BuildGoSlice(DataLen, pfINb), BuildGoSlice(DataLen, pfINc), BuildGoSlice(DataLen, pfOUT));
}


PluginTCalcFuncInfo g_CalcFuncSets[] =
{
    {1, (pPluginFUNC) &SingleStarPatter},
    {2, (pPluginFUNC) &DoubleStarsPatter},
    {3, (pPluginFUNC) &ThreeStarsPatter},
    {5, (pPluginFUNC) &FindFxPatter},
    {0, NULL},
};

BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
    if (*pFun == NULL)
    {
        (*pFun) = g_CalcFuncSets;
        return TRUE;
    }
    return FALSE;
}

