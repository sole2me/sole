/**
 * @file WorkImp.h
 * @author sule (sole2me@vip.sina.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022, le su, All rights reserved.
 * 
 */

#ifndef _WorkImp_H_
#define _WorkImp_H_

#include "servant/Application.h"
#include "Work.h"
#include "ComShare.h"
#include "SoleBase.h"

extern sole::SoleHandlePtr g_soleApp;
extern sole::SoleEventorPtr g_soleEventor;

/**
 *
 *
 */
class WorkImp : public sole::Work
{
public:
    /**
     *
     */
    virtual ~WorkImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
    virtual tars::Int32 wakeup(const std::string & id,tars::Int64 eventId,sole::Data &data,tars::TarsCurrentPtr current);
    
    /**
     *
     */
    virtual tars::Int32 doCustomMessage(bool bExpectIdle);
private:
    sole::SoleHandlePtr  m_handle;
};
/////////////////////////////////////////////////////
#endif
