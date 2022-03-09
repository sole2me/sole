#ifndef _SoleTools_H_
#define _SoleTools_H_
#include "ComShare.h"

namespace sole
{
    class SoleTools
    {
    public:
        static const long _EPSILON_INT64;

        static sole::Data newObject();
        static sole::Data newData(sole::Data & d);
        static sole::Data newBool(bool flag);
        static sole::Data newString(string str);
        static sole::Data newLong(long val);
        static sole::Data newDouble(double val,long el);
        static sole::Data newOperator(string o);
        static sole::Data newExpression(sole::Data & l,string o,sole::Data & r);
        static sole::Data newExpression(string o,sole::Data & r);
        static sole::Data newExpression(sole::Data & e);
        static bool dataEqual(sole::Data & l,sole::Data & r);
        static bool dataGreater(sole::Data & l,sole::Data & r);
        static bool dataLess(sole::Data & l,sole::Data & r);
        static bool dataEGreater(sole::Data & l,sole::Data & r);
        static bool dataELess(sole::Data & l,sole::Data & r);
        static bool equalZero(sole::Data & val);
        static sole::Data addData(sole::Data & l,sole::Data & r);
        static sole::Data subData(sole::Data & l,sole::Data & r);
        static sole::Data mulData(sole::Data & l,sole::Data & r);
        static sole::Data divData(sole::Data & l,sole::Data & r);
        static sole::Data surData(sole::Data & l,sole::Data & r);
        static sole::Data addDouble(sole::Data & l,sole::Data & r);
        static sole::Data subDouble(sole::Data & l,sole::Data & r);
        static sole::Data mulDouble(sole::Data & l,sole::Data & r);
        static sole::Data divDouble(sole::Data & l,sole::Data & r);
        static sole::Data& getVar(sole::Data & v,sole::Data & vn);
        static sole::Data& getVar4Assign(sole::Data & v,sole::Data & vn);
        static sole::Data& getElement4Assign(sole::Data & v,sole::Data & vn,size_t i,string& varName,string& traceVar);
        static sole::Data& getElement(sole::Data & v,sole::Data & vn,size_t i,string& varName,string& traceVar);
        static void putVar(sole::Data & v,string& varName);
    };
};
#endif