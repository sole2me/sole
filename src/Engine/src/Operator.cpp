#include "Operator.h"
#include "SoleTools.h"
#include "OperatorImp.h"

using namespace std;

namespace sole{
    Operator::Operator(const string str)
    {
        //1  算数运算符号
        if("+" == str)
        {
            m_pf = sole::doAdd;
        }
        else if("-" == str)
        {
            m_pf = sole::doSub;
        }
        else if("*" == str)
        {
            m_pf = sole::doMul;
        }
        else if("/" == str)
        {
            m_pf = sole::doDiv;
        }
        else if("%" == str)
        {
            m_pf = sole::doSur;
        }
        //2 关系运算符号
        else if("==" == str)
        {
            m_pf = sole::doEqual;
        }
        else if("!=" == str)
        {
            m_pf = sole::doNEqual;
        }
        else if(">" == str)
        {
            m_pf = sole::doGreater;
        }
        else if("<" == str)
        {
            m_pf = sole::doLess;
        }
        else if(">=" == str)
        {
            m_pf = sole::doEGreater;
        }
        else if("<=" == str)
        {
            m_pf = sole::doELess;
        }
        //3  逻辑运算符
        else if("&&" == str)
        {
            m_pf = sole::doAnd;
        }
        else if("||" == str)
        {
            m_pf = sole::doOr;
        }
        else if("!" == str)
        {
            m_pf = sole::doNon;
        }
        //5  赋值运算符
        else if("=" == str)
        {
            m_pf = sole::doAssign;
        }
        //7 逗号运算符
        else if("," == str)
        {
            m_pf = sole::doComma;
        }
        else
        {
            throw;
        }
    }

    void Operator::doOperation(sole::Data & v,sole::Data & t,size_t i)
    {
    // try
    //  {
            m_pf(v,t,i);
    //   }
    //   catch(...)
    //   {
    //       cout <<"exception:"<< t.writeToJsonString() <<endl;
    //   }
    }
}