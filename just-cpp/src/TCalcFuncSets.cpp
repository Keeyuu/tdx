#include "pch.h"
#include "TCalcFuncSets.h"


void SingleStarPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
}

void DoubleStarsPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
}


void ThreeStarsPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
}


void FindFxPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
}


PluginTCalcFuncInfo g_CalcFuncSets[] =
{
	{1, (pPluginFUNC)&SingleStarPatter},
	{2, (pPluginFUNC)&DoubleStarsPatter},
	{3, (pPluginFUNC)&ThreeStarsPatter},
	{5, (pPluginFUNC)&FindFxPatter},
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


#include"analyser.h"
#include<iostream>
void Debug()
{
	int max = 13;
	std::cout << "start debug" << std::endl;
	float* p = new float[max] { 1, 1, 3, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2 };
	auto x = PriceAnalyser(max, p, p, p);
	x.show();

	std::cout << "end debug" << std::endl;
}
