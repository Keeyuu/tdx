// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "OutStruct.h"
#include "Plugin.h"


#define PLUGIN_EXPORTS
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


const	BYTE	g_nAvoidMask[] = { 0xF8,0xF8,0xF8,0xF8 };	// 无效数据标志(系统定义)


WORD   AfxRightData(float* pData, WORD nMaxData)	//获取有效数据位置
{
	for (WORD nIndex = 0; nIndex < nMaxData && !memcmp(&pData[nIndex], g_nAvoidMask, 4); nIndex++)return nIndex;
}

BOOL InputInfoThenCalc1(char* Code, short nSetCode, int Value[4], short DataType, short nDataNum, BYTE nTQ, unsigned long unused) //按最近数据计算
{
	BOOL nRet = FALSE;
	NTime tmpTime = { 0 };

	LPHISDAT pHisDat = new HISDAT[nDataNum];  //数据缓冲区
	long readnum = g_pFuncCallBack(Code, nSetCode, PER_DAY, pHisDat, nDataNum, tmpTime, tmpTime, nTQ, 0);  //利用回调函数申请数据，返回得到的数据个数
	if (readnum > max(Value[0], Value[1])) //只有数据个数大于Value[0]和Value[1]中的最大值才有意义
	{
		/*	float* pMa1 = new float[readnum];
			float* pMa2 = new float[readnum];
			for (int i = 0; i < readnum; i++)
			{
				pMa1[i] = pHisDat[i].Close;
				pMa2[i] = pHisDat[i].Close;
			}*/
			//auto x = AfxRightData(pMa1, readnum);
		if (pHisDat[readnum - 1].Close > 100 && pHisDat[readnum - 1].Close < 200) {
			nRet = TRUE;
		}
	}

	delete[]pHisDat; pHisDat = NULL;
	return nRet;
}

BOOL InputInfoThenCalc2(char* Code, short nSetCode, int Value[4], short DataType, NTime time1, NTime time2, BYTE nTQ, unsigned long unused)  //选取区段
{
	return true;
}








