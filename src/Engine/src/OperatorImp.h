#ifndef _OperatorImp_H_
#define _OperatorImp_H_
#include "Operator.h"
#include "SoleTools.h"
#include "ComShare.h"

namespace sole
{
    //1
    void doAdd(sole::Data & v,sole::Data & t,size_t i);
    void doSub(sole::Data & v,sole::Data & t,size_t i);
    void doMul(sole::Data & v,sole::Data & t,size_t i);
    void doDiv(sole::Data & v,sole::Data & t,size_t i);
    void doSur(sole::Data & v,sole::Data & t,size_t i);

    //2
    void doEqual(sole::Data & v,sole::Data & t,size_t i);
    void doGreater(sole::Data & v,sole::Data & t,size_t i);
    void doLess(sole::Data & v,sole::Data & t,size_t i);
    void doNEqual(sole::Data & v,sole::Data & t,size_t i);
    void doEGreater(sole::Data & v,sole::Data & t,size_t i);
    void doELess(sole::Data & v,sole::Data & t,size_t i);
    

    //3
    void doAnd(sole::Data & v,sole::Data & t,size_t i);
    void doOr(sole::Data & v,sole::Data & t,size_t i);
    void doNon(sole::Data & v,sole::Data & t,size_t i);

    //5
    
    void doAssign(sole::Data & v,sole::Data & t,size_t i);

    //7
    void doComma(sole::Data & v,sole::Data & t,size_t i);
    
};

#endif