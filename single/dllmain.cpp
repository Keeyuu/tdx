// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "OutStruct.h"
#include "Plugin.h"


#define PLUGIN_EXPORTS
#define INIT -1
#pragma warning(disable:4996)


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}




PDATAIOFUNC	 g_pFuncCallBack;

//获取回调函数
void RegisterDataInterface(PDATAIOFUNC pfn)
{
	g_pFuncCallBack = pfn;
}

//注册插件信息
void GetCopyRightInfo(LPPLUGIN info)
{
	//填写基本信息
	strcpy(info->Name, "日线突破");
	strcpy(info->Dy, "广州");
	strcpy(info->Author, "keeyu");
	strcpy(info->Period, "短线");
	strcpy(info->Descript, "日线突破次级别3买");
	strcpy(info->OtherInfo, "自定义参数待完善");
	//填写参数信息
	info->ParamNum = 2;
	strcpy(info->ParamInfo[0].acParaName, "待完善1");
	info->ParamInfo[0].nMax = 1;
	info->ParamInfo[0].nMax = 1000;
	info->ParamInfo[0].nDefault = 51;
	strcpy(info->ParamInfo[1].acParaName, "待完善2");
	info->ParamInfo[1].nMax = 1;
	info->ParamInfo[1].nMax = 1000;
	info->ParamInfo[1].nDefault = 10;
}

const	BYTE	g_nAvoidMask[] = { 0xF8, 0xF8, 0xF8, 0xF8 };	// 无效数据标志(系统定义)

WORD   AfxRightData(LPHISDAT pData, WORD nMaxData)	//获取有效数据位置
{
	for (WORD nIndex = 0; nIndex < nMaxData && !memcmp(&pData[nIndex].Close, g_nAvoidMask, 4); nIndex++)return nIndex;
}

int findUltra(LPHISDAT in, int times, int left, int index)
{
	//允许调整三日 
	//0 1 2 3 4 5 
	int len = 10;//10日最高
	if (times > 3 || index <= left)return INIT;
	int start = index - len > left ? index - len : left;
	for (int i = start; i < index; i++)
	{
		if (in[i].Close > in[index].Close)return findUltra(in, times + 1, left, index - 1);
	}
	return index;
}


int FindUltra(LPHISDAT in, int left, int right)
{
	return findUltra(in, 0, 0, right);
}

float CalcMa(LPHISDAT in, int left, int right, int len)
{
	float value = 0, times = 0;
	int start = right - len > left ? right - len : left;
	for (int i = start; i < right; i++)
	{
		value += in[i].Close;
		times++;
	}
	return value / times;
}


bool CheckDayLevel(char* Code, short nSetCode, int Value[4], short DataType, short nDataNum, BYTE nTQ, unsigned long unused)
{
	BOOL nRet = false;
	NTime tmpTime = { 0 };

	LPHISDAT pHisDat = new HISDAT[nDataNum];  //数据缓冲区
	long readnum = g_pFuncCallBack(Code, nSetCode, PER_DAY, pHisDat, nDataNum, tmpTime, tmpTime, nTQ, 0);  //利用回调函数申请数据，返回得到的数据个数
	if (readnum > max(Value[0], Value[1])) //只有数据个数大于Value[0]和Value[1]中的最大值才有意义
	{
		int left = AfxRightData(pHisDat, readnum);
		int flag = FindUltra(pHisDat, left, readnum);
		if (flag != INIT)
		{
			//ma5过滤
			if (pHisDat[flag].Close >= CalcMa(pHisDat, 0, flag, 5))nRet = true;
			//至少拉出10日平均区间一半

		}
	}

	delete[]pHisDat; pHisDat = NULL;
	return nRet;
}


bool CheckBreakthrough(LPHISDAT in, int len, int right)
{
	int start = right - len < 0 ? 0 : right - len;
	for (int i = start; i < right; i++)
	{
		if (in[i].Close > in[right].Close)return false;
	}
	return true;
}



BOOL InputInfoThenCalc1(char* Code, short nSetCode, int Value[4], short DataType, short nDataNum, BYTE nTQ, unsigned long unused) //按最近数据计算
{
	return CheckDayLevel(Code, nSetCode, Value, DataType, nDataNum, nTQ, unused);
}

BOOL InputInfoThenCalc2(char* Code, short nSetCode, int Value[4], short DataType, NTime time1, NTime time2, BYTE nTQ, unsigned long unused)  //选取区段
{
	return false;
}







