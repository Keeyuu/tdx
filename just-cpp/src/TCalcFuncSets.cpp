#include "pch.h"
#include "TCalcFuncSets.h"

// a: diff ma5 b: open c: close
void OverfulfilPatter(int dataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
	//if (dataLen < 1)return;
	//int days = 15;
	//float flag = -9;
	//float sumDiffMa = 0.0, firstMa = 0.0, maxLimit = 0.01 * 10;
	//for (int i = 0; i < dataLen; i++) sumDiffMa += pfINa[i];
	//if (sumDiffMa / firstMa >= maxLimit) flag = 1;//最大均线差异幅度
	//if (isSpecialHigh(dataLen, pfINc, dataLen, days)) {
	//	//todo 跳空
	//	//todo 扎空棒
	//}
	//if (true);//todo 强轧空
	//if (true);//todo 一星
	//if (true);//todo 二星
	//if (true);//todo 三星
	//for (int i = 0; i < dataLen; i++) pfOUT[i] = flag;
}


bool isSpecialHigh(int dataLen, float* close, int cursor, int specialInterval)
{
	int left = 0;
	if (cursor - specialInterval > 0)left = cursor - specialInterval;
	for (int i = left; i < cursor && i < dataLen; i++) {
		if (close[i] > close[cursor]) return false;
	}
	//todo 寻找底分型 
	//todo 找到周期内第一根最高点
	return true;
}


void FindFxPatter(int dataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{

}


PluginTCalcFuncInfo g_CalcFuncSets[] =
{
	{1, (pPluginFUNC)&OverfulfilPatter},
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
