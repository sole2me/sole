#include "Schedule.h"
#include "ComShare.h"
#include "Engine.h"
#include "util/tc_file.h"
#include "parse.h"
#include "SoleTools.h"
using namespace std;

namespace sole
{
    void Schedule::doTest()
    {
        if(1)
        {
            Engine eng;
            sole::Data v;
            sole::Data d;
            g_parse->_flow.v.push_back(sole::SoleTools::newObject());
            g_parse->_flow.v[0].m["flow"] = sole::SoleTools::newObject();
            g_parse->_statment.type = "Statement";
        
            g_parse->parse("../file.txt");

            tars::TC_File::save2file("../statment.json",g_parse->_statment.writeToJsonString());
            tars::TC_File::save2file("../flow.json",g_parse->_flow.writeToJsonString());

            d.readFromJsonString(tars::TC_File::load2str("../statment.json"));
            v.readFromJsonString(tars::TC_File::load2str("../flow.json"));

            eng.init(1);
            eng.start();
            eng.exec(d,v);
            eng.waitForAllDone();
        }
    }
}