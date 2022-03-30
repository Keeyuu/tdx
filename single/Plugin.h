/**************************************************/
/*		PLUGIN动态连接库导出头文件				  */
/**************************************************/

#ifndef PLUGIN_H_
#define PLUGIN_H_

#ifdef PLUGIN_EXPORTS
#define PLUGIN_API extern "C"  __declspec(dllexport)
#else
#define PLUGIN_API extern "C" __declspec(dllimport)
#endif

#include "OutStruct.h"

#pragma pack(push,1)

typedef struct tag_PluginPara	//参数信息的结构定义
{
	char  acParaName[14];		//参数的中文名称
	int   nMin;					//参数最小取值范围
	int   nMax;					//参数最大取值范围
	int   nDefault;				//系统推荐的缺省值
	int   nValue;				//用户定义的值
}PLUGINPARAM;

typedef struct tag_PlugInfo
{
	char  Name[50];				//名称与版本
	char  Dy[30];				//产地
	char  Author[30];			//设计人
	char  Descript[100];		//选股描述
	char  Period[30];			//适应周期
	char  OtherInfo[300];
	short ParamNum;				//0<=参数个数<=4
	PLUGINPARAM ParamInfo[4];	//参数信息，见上
}PLUGIN, * LPPLUGIN;

//回调函数,取数据接口
typedef long(CALLBACK* PDATAIOFUNC)(char* Code, short nSetCode, short DataType, void* pData, short nDataNum, NTime, NTime, BYTE nTQ, unsigned long);
//注册回调函数
PLUGIN_API void  RegisterDataInterface(PDATAIOFUNC pfn);
//得到版权信息
PLUGIN_API void	 GetCopyRightInfo(LPPLUGIN info);
//按最近数据计算(nDataNum为ASK_ALL表示所有数据)
PLUGIN_API BOOL	 InputInfoThenCalc1(char* Code, short nSetCode, int Value[4], short DataType, short nDataNum, BYTE nTQ, unsigned long unused);
//选取区段计算
PLUGIN_API BOOL	 InputInfoThenCalc2(char* Code, short nSetCode, int Value[4], short DataType, NTime time1, NTime time2, BYTE nTQ, unsigned long unused);


#pragma pack(pop)
#endif
