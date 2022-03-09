#ifndef _Operator_H_
#define _Operator_H_
#include "ComShare.h"

namespace sole{
    using FuncType = void (sole::Data &, sole::Data &,size_t i);

    class Operator
    {
    public:
        virtual ~Operator() {}
        Operator(const string str);
        void doOperation(sole::Data & v,sole::Data & t,size_t i);
    private:
        FuncType *m_pf;
    };
}
#endif