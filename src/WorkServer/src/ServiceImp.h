/**
 * @file ServiceImp.h
 * @author sule (sole2me@vip.sina.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022, le su, All rights reserved.
 * 
 */

#ifndef _ServiceImp_H_
#define _ServiceImp_H_

#include "servant/Application.h"
#include "Service.h"
#include "ComShare.h"
/**
 *
 *
 */
class ServiceImp : public sole::Service
{
public:
    /**
     *
     */
    virtual ~ServiceImp() {}

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
};
/////////////////////////////////////////////////////
#endif
