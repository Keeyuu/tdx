#ifndef __TCALC_FUNC_SETS
#define __TCALC_FUNC_SETS
#include "PluginTCalcFunc.h"





#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
	__declspec(dllexport) BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun);
	__declspec(dllexport) void Debug();
#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__TCALC_FUNC_SETS