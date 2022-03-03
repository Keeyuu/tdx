#include "pch.h"
#include "TCalcFuncSets.h"

// a: diff ma5 b: open c: close
void OverfulfilPatter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
	if (DataLen < 1)return;
	int days = 15;
	float flag = -9;
	float sumDiffMa = 0.0; float firstMa = 0.0; float maxLimit = 0.01 * 10;
	for (int i = 0; i < DataLen; i++) sumDiffMa += pfINa[i];
	if (sumDiffMa / firstMa >= maxLimit) flag = 1;//最大均线差异幅度
	if (true);//todo 正突破 子类型 跳空 扎空棒
	if (true);//todo 强轧空
	if (true);//todo 一星
	if (true);//todo 二星
	if (true);//todo 三星
	for (int i = 0; i < DataLen; i++) pfOUT[i] = flag;
}

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
	//{2, (pPluginFUNC)&DoubleStarsPatter},
	//{3, (pPluginFUNC)&ThreeStarsPatter},
	//{5, (pPluginFUNC)&FindFxPatter},
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
