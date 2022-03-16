#include "util/tc_common.h"
#include "SoleBase.h"

namespace sole
{
    void SoleEventor::test()
    {
        ;
    }

    void SoleHandle::addHand(string hName,SoleBasePtr p)
    {
        tars::Int64 hIndex = m_v.size();
        unordered_map<string,tars::Int64>::iterator it = m_hMapping.find(hName);
        
        if(it == m_hMapping.end())
        {
            m_hMapping[hName] = hIndex;
            m_v.push_back(p);
        }
        else
        {
            throw ;
        }
    }

    SoleBasePtr SoleHandle::getHand(string hName)
    {
        unordered_map<string,tars::Int64>::iterator it = m_hMapping.find(hName);
        if(it != m_hMapping.end())
        {
            return m_v[it->second];
        }
        else
        {
            throw ;
        }
    }
};
