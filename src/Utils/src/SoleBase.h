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
            void addHand(string hName,Data d);
            Data getHand(string hName);
        private:
            unordered_map<string,tars::Int64> m_hMapping;
            vector<Data> m_v;
    };
    typedef tars::TC_AutoPtr<SoleEventor> SoleEventorPtr;

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