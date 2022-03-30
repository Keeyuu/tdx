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
	strcpy(info->Name, "两MA线穿越");
	strcpy(info->Dy, "武汉");
	strcpy(info->Author, "系统");
	strcpy(info->Period, "短线");
	strcpy(info->Descript, "两MA线穿越");
	strcpy(info->OtherInfo, "自定义天数两MA线金叉穿越");
	//填写参数信息
	info->ParamNum = 2;
	strcpy(info->ParamInfo[0].acParaName, "MA天数1");
	info->ParamInfo[0].nMax = 1;
	info->ParamInfo[0].nMax = 1000;
	info->ParamInfo[0].nDefault = 13;
	strcpy(info->ParamInfo[1].acParaName, "MA天数2");
	info->ParamInfo[1].nMax = 1;
	info->ParamInfo[1].nMax = 1000;
	info->ParamInfo[1].nDefault = 30;
}

////////////////////////////////////////////////////////////////////////////////
//自定义实现细节函数(可根据选股需要添加)

const	BYTE	g_nAvoidMask[] = { 0xF8,0xF8,0xF8,0xF8 };	// 无效数据标志(系统定义)

//WORD   AfxRightData(float* pData, WORD nMaxData)	//获取有效数据位置
//{
//	for (WORD nIndex = 0; nIndex < nMaxData && !memcmp(&pData[nIndex], g_nAvoidMask, 4); nIndex++);
//	return(0);
//}
//
//void   AfxCalcMa(float* pData, long nData, WORD nParam)
//{
//	if (pData == NULL || nData == 0 || nParam == 1) return;
//	long i = nData - nParam + 1, nMinEx = AfxRightData(pData, nData);
//	if (nParam == 0 || nParam + nMinEx > nData) nMinEx = nData;
//	else
//	{
//		float	nDataEx = 0, nDataSave = 0;
//		float* MaPtr = pData + nData - 1, * DataPtr = pData + nData - nParam;
//		for (nMinEx += nParam - 1; i < nData; nDataEx += pData[i++]);
//		for (i = nData - 1; i >= nMinEx; i--, MaPtr--, DataPtr--)
//		{
//			nDataEx += (*DataPtr);
//			nDataSave = (*MaPtr);
//			*MaPtr = nDataEx / nParam;
//			nDataEx -= nDataSave;
//		}
//	}
//}
//
//WORD   AfxCross(float* psData, float* plData, WORD nIndex, float& nCross)
//{
//	if (psData == NULL || plData == NULL || nIndex == 0) return(0);
//	float  nDif = psData[nIndex - 1] - plData[nIndex - 1];
//	float  nDifEx = plData[nIndex] - psData[nIndex];
//	float  nRatio = (nDif + nDifEx) ? nDif / (nDif + nDifEx) : 0;
//	nCross = psData[nIndex - 1] + (psData[nIndex] - psData[nIndex - 1]) * nRatio;
//	if (nDif < 0 && nDifEx < 0)	return(1);
//	if (nDif > 0 && nDifEx > 0)	return(2);
//	return(0);
//}

BOOL InputInfoThenCalc1(char* Code, short nSetCode, int Value[4], short DataType, short nDataNum, BYTE nTQ, unsigned long unused) //按最近数据计算
{
	//BOOL nRet = FALSE;
	//NTime tmpTime = { 0 };

	//LPHISDAT pHisDat = new HISDAT[nDataNum];  //数据缓冲区
	//long readnum = g_pFuncCallBack(Code, nSetCode, DataType, pHisDat, nDataNum, tmpTime, tmpTime, nTQ, 0);  //利用回调函数申请数据，返回得到的数据个数
	//if (readnum > max(Value[0], Value[1])) //只有数据个数大于Value[0]和Value[1]中的最大值才有意义
	//{
	//	float* pMa1 = new float[readnum];
	//	float* pMa2 = new float[readnum];
	//	for (int i = 0; i < readnum; i++)
	//	{
	//		pMa1[i] = pHisDat[i].Close;
	//		pMa2[i] = pHisDat[i].Close;
	//	}
	//	AfxCalcMa(pMa1, readnum, Value[0]);	//计算MA
	//	AfxCalcMa(pMa2, readnum, Value[1]);
	//	float nCross;
	//	if (AfxCross(pMa1, pMa2, readnum - 1, nCross) == 1)	//判断是不是在readnum-1(最后一个数据)处交叉 1:上穿 2:下穿
	//		nRet = TRUE;  //返回为真，符合选股条件
	//	delete[]pMa1; pMa1 = NULL;
	//	delete[]pMa2; pMa2 = NULL;
	//}

	//delete[]pHisDat; pHisDat = NULL;
	//return nRet;
	return true;
}

BOOL InputInfoThenCalc2(char* Code, short nSetCode, int Value[4], short DataType, NTime time1, NTime time2, BYTE nTQ, unsigned long unused)  //选取区段
{
	//BOOL nRet = FALSE;
	//NTime tmpTime = { 0 };

	////窥视数据个数
	//long datanum = g_pFuncCallBack(Code, nSetCode, DataType, NULL, -1, time1, time2, nTQ, 0);
	//if (datanum < max(Value[0], Value[1]))
	//	return FALSE;

	////读取数据
	//LPHISDAT pHisDat = new HISDAT[datanum];
	//long readnum = g_pFuncCallBack(Code, nSetCode, DataType, pHisDat, datanum, time1, time2, nTQ, 0);
	//if (readnum > max(Value[0], Value[1])) //只有将数据个数大于Value[0]和Value[1]中的最大值才有意义
	//{
	//	float* pMa1 = new float[readnum];
	//	float* pMa2 = new float[readnum];
	//	for (int i = 0; i < readnum; i++)
	//	{
	//		pMa1[i] = pHisDat[i].Close;
	//		pMa2[i] = pHisDat[i].Close;
	//	}
	//	AfxCalcMa(pMa1, readnum, Value[0]);	//计算MA
	//	AfxCalcMa(pMa2, readnum, Value[1]);
	//	float nCross;
	//	if (AfxCross(pMa1, pMa2, readnum - 1, nCross) == 1)	//判断是不是在readnum-1(最后一个数据)处交叉 1:上穿 2:下穿
	//		nRet = TRUE;
	//	delete[]pMa1; pMa1 = NULL;
	//	delete[]pMa2; pMa2 = NULL;
	//}

	//delete[]pHisDat; pHisDat = NULL;
	//return nRet;
	return true;
}








