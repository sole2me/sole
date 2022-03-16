#ifndef _SoleBase_H_
#define _SoleBase_H_
#include <unordered_map>

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
            tars::Int64 m_eventorId;
            Data m_eventor;
    };

    typedef tars::TC_AutoPtr<SoleEventor> SoleEventorPtr;

    class SoleApplication : public SoleBase
    {
        public:
            SoleApplication() { }
            tars::Int64 m_applicationId;
    };

    typedef tars::TC_AutoPtr<SoleApplication> SoleApplicationPtr;

    class SoleServant : public SoleBase
    {
        public:
            SoleServant() { }
            tars::Int64 m_servantId;
    };

    typedef tars::TC_AutoPtr<SoleServant> SoleServantPtr;

    class SoleHandle : public SoleBase
    {
        public:
            SoleHandle() { }
            void addHand(string hName,SoleBasePtr p);
            SoleBasePtr getHand(string hName);
        private:
            unordered_map<string,tars::Int64> m_hMapping;
            vector<SoleBasePtr> m_v;
    };

    typedef tars::TC_AutoPtr<SoleHandle> SoleHandlePtr;
};

#endif