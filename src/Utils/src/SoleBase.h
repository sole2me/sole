#ifndef _SoleBase_H_
#define _SoleBase_H_
#include "ComShare.h"

namespace sole
{
    class SoleBase : virtual public tars::TC_HandleBase
    {
        public:
            virtual ~SoleBase(){};
    };

    typedef tars::TC_AutoPtr<SoleBase> SoleBasePtr;

    class SoleEventor : public SoleBase
    {
        public:
            SoleEventor() { }
            void test();
            tars::Int64 m_eventor_id;
            Data m_eventor;
    };

    typedef tars::TC_AutoPtr<SoleEventor> SoleEventorPtr;

    class SoleHandle : public SoleBase
    {
        public:
            SoleHandle() { }
            vector<SoleBase> a;
    };

    typedef tars::TC_AutoPtr<SoleHandle> SoleHandlePtr;
};

#endif