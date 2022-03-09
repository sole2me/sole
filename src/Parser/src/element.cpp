#include "element.h"
#include <iostream>
#include <cassert>
#include "parse.h"
#include "util/tc_file.h"
#include "util/tc_common.h"

void Context::addInclude(const string &incl)
{
    if(incl == _filename)
    {
        g_parse->error("can't include self");
    }
    _includes.push_back(tars::TC_File::excludeFileExt(incl) + ".h");
}
