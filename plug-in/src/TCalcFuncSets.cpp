#include "pch.h"
#include "TCalcFuncSets.h"
#include "plug.h"
#include<iostream>
//生成的dll及相关依赖dll请拷贝到通达信安装目录的T0002/dlls/下面,再在公式管理器进行绑定




//双星模式
void SingleStar(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
    auto a = new GoSlice;
    a->len = DataLen;
    a->cap = DataLen;
    a->data = pfINa;
    auto b = new GoSlice;
    b->len = DataLen;
    b->cap = DataLen;
    b->data = pfINb;
    auto c = new GoSlice;
    c->len = DataLen;
    c->cap = DataLen;
    c->data = pfINc;
    auto flag = SingleStar(DataLen, *a, *b, *c);
    for (int i = 0; i < DataLen; i++)
    {
        pfOUT[i] = flag.r0;
        if (i == DataLen - 1)
        {
            pfOUT[i] = flag.r1;
        }
    }
}

void DoubleStars(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
    auto a = new GoSlice;
    a->len = DataLen;
    a->cap = DataLen;
    a->data = pfINa;
    auto b = new GoSlice;
    b->len = DataLen;
    b->cap = DataLen;
    b->data = pfINb;
    auto c = new GoSlice;
    c->len = DataLen;
    c->cap = DataLen;
    c->data = pfINc;
    auto flag = DoubleStars(DataLen, *a, *b, *c);
    for (int i = 0; i < DataLen; i++)
    {
        pfOUT[i] = flag.r0;
        if (i == DataLen - 1)
        {
            pfOUT[i] = flag.r1;
        }
    }
}


// 三星模式

void ThreeStars(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc)
{
    auto a = new GoSlice;
    a->len = DataLen;
    a->cap = DataLen;
    a->data = pfINa;
    auto b = new GoSlice;
    b->len = DataLen;
    b->cap = DataLen;
    b->data = pfINb;
    auto c = new GoSlice;
    c->len = DataLen;
    c->cap = DataLen;
    c->data = pfINc;
    auto flag = ThreeStars(DataLen, *a, *b, *c);
    for (int i = 0; i < DataLen; i++)
    {
        pfOUT[i] = flag.r0;
        if (i == DataLen - 1)
        {
            pfOUT[i] = flag.r1;
        }
    }
}



//加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] =
{
    {1, (pPluginFUNC) &SingleStar},
    {2, (pPluginFUNC) &DoubleStars},
    {3, (pPluginFUNC) &ThreeStars},
    {0, NULL},
};

//导出给TCalc的注册函数
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
    if (*pFun == NULL)
    {
        (*pFun) = g_CalcFuncSets;
        return TRUE;
    }
    return FALSE;
}


void test()
{
    std::cout << "yes" << std::endl;
}
