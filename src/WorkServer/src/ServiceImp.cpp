/**
 * @file ServiceImp.cpp
 * @author sule (sole2me@vip.sina.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022, le su, All rights reserved.
 * 
 */

#include "ServiceImp.h"
#include "servant/Application.h"
#include "Schedule.h"
using namespace std;

//////////////////////////////////////////////////////
void ServiceImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void ServiceImp::destroy()
{
    //destroy servant here:
    //...
}

tars::Int32 ServiceImp::wakeup(const std::string & id,tars::Int64 eventId,sole::Data &data,tars::TarsCurrentPtr current)
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
	return 0;
}
