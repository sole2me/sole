#ifndef _WorkServer_H_
#define _WorkServer_H_

#include <iostream>
#include "servant/Application.h"
#include "SoleBase.h"

using namespace tars;


/**
 *
 **/
class WorkServer : public Application
{
public:
    /**
     *
     **/
    virtual ~WorkServer() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern WorkServer g_app;

////////////////////////////////////////////
#endif
