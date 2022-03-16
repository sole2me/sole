/**
 * @file WorkImp.cpp
 * @author sule (sole2me@vip.sina.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022, le su, All rights reserved.
 * 
 */

#include "WorkImp.h"
#include "servant/Application.h"
#include "Schedule.h"
using namespace std;

//////////////////////////////////////////////////////
void WorkImp::initialize()
{
    //initialize servant here:
    //... /
    //
    m_handle = new sole::SoleHandle();

    if(1)
    {
        ;
    }
}

//////////////////////////////////////////////////////
void WorkImp::destroy()
{
    //destroy servant here:
    ///...
}

tars::Int32 WorkImp::wakeup(const std::string & id,tars::Int64 eventId,sole::Data &data,tars::TarsCurrentPtr current)
{
    //   int j;
    // j = 0;
    // sole::WorkFlow wf;
    // wf.s;
    //跳栈怎么解决呢?
    //#event$0$0$0
    //递归怎么办
    //没有的变量怎么弄了呢？

   // sole::Event e;
   // sole::Data d;
   // e.id = eventId;
   // Schedule s;
    //data.c;
   // s.doWork(e,d);

   /*
   in
   deal
   out
   */

	return 0;
}

tars::Int32 WorkImp::doCustomMessage(bool bExpectIdle)
{
    //
    return 0;
}

