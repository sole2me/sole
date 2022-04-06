#include "WorkServer.h"
#include "WorkImp.h"
#include "Schedule.h"
using namespace std;


WorkServer g_app;

/////////////////////////////////////////////////////////////////
void
WorkServer::initialize()
{
    //initialize application here:
    //

    addServant<WorkImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".WorkObj");

    g_soleApp = new sole::SoleHandle();

    g_soleEventor = new sole::SoleEventor();
}
/////////////////////////////////////////////////////////////////
void
WorkServer::destroyApp()
{
    //destroy application here:
    //...
}


/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
    sole::Schedule::doTest();
    return 0;
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (std::exception& e)
    {
        cerr << "std::exception:" << e.what() << std::endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << std::endl;
    }
    return -1;
}

/////////////////////////////////////////////////////////////////
