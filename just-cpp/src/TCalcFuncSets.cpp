#include "pch.h"
#include "TCalcFuncSets.h"
#include"analyser.hpp"


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


#include<vector>
void Debug()
{
	std::cout << "start debug" << std::endl;
	auto p = new vectot<KLine>;
}
