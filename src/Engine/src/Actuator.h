#ifndef _Actuator_H_
#define _Actuator_H_
#include "ComShare.h"

namespace sole
{
    class Actuator
    {
    public:

        virtual ~Actuator() {}
        void doContext(sole::Data & d,sole::Data & v);
        static void doExpression(sole::Data & d,sole::Data & v,sole::Data & t);
        static sole::Data& getVar(sole::Data & v,sole::Data & vn);
        static sole::Data& getVar4Assign(sole::Data & v,sole::Data & vn);
    private:
        void doStatment(sole::Data & d,sole::Data & v);
        void doIf(sole::Data & d,sole::Data & v);
        void doVar(sole::Data & d,sole::Data & v);
        bool doIfBranch(sole::Data & d,sole::Data & v);
        
    };
}
#endif