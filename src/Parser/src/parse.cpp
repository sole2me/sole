
#include "parse.h"
#include "sole.tab.hpp"
#include <errno.h>
#include <fstream>
#include <string.h>
#include "util/tc_common.h"
#include "util/tc_file.h"
#include "util/tc_json.h"
#include "SolePublic.h"
#include "SoleTools.h"


SoleParsePtr g_parse = new SoleParse();

void yyerror(char const *msg)
{
    g_parse->error(msg);
}

SoleParse::SoleParse()
{
    initScanner();
}

void SoleParse::nextLine()
{
   _contexts.top()->nextLine();
}

void SoleParse::clear()
{
}

void SoleParse::error(const string &msg)
{
    cerr <<  _contexts.top()->getFileName() << ": " << _contexts.top()->getCurrLine() << ": error: " << msg << endl;
    exit(-1);
}

void SoleParse::parse(const string& sFileName)
{
    std::string sTemp = sFileName;
    bool isExist = tars::TC_File::isFileExist(sFileName);

    if (!isExist)
    {
        sTemp = tars::TC_File::extractFileName(sFileName);
    }

    clear();

    if(!(yyin = fopen(sTemp.c_str(), "r")))
    {
        error("open file '" + sFileName + "(" + sTemp + ")" + "' error :" + string(strerror(errno)));
    }

    ContextPtr c = new Context(sFileName);
    _contexts.push(c);

    yyparse();
}

int SoleParse::checkKeyword(const string& s)
{
    std::map<std::string, int>::const_iterator it = _keywordMap.find(s);
    if(it != _keywordMap.end())
    {
        if(s == "then")
        {
            g_parse->pushVarTranslate();
        }
        else if(s == "else")
        {
            g_parse->popVarTranslate();
            g_parse->pushVarTranslate();
        }
        else if(s == "elsif")
        {
            g_parse->popVarTranslate();
        }
        else if(s == "end")
        {
            g_parse->popVarTranslate();
        }
        return it->second;
    }

    return SOLE_IDENTIFIER;
}

void SoleParse::initScanner()
{
    _keywordMap["false"]    = SOLE_FALSE;
    _keywordMap["true"]     = SOLE_TRUE;
    _keywordMap["const"]    = SOLE_CONST;
    _keywordMap["var"] = SOLE_VAR;
    _keywordMap["if"] = SOLE_IF;
    _keywordMap["else"] = SOLE_ELSE;
    _keywordMap["for"] = SOLE_FOR;
    _keywordMap["event"] = SOLE_EVENT;
    _keywordMap["end"] = SOLE_END;
    _keywordMap["then"] = SOLE_THEN;
    _keywordMap["elsif"] = SOLE_ELSE_IF;
    _keywordMap["alias"] = SOLE_ALIAS;
    _keywordMap["flow"] = SOLE_FLOW;
}

bool SoleParse::checkVar(string vName)
{
    for(size_t index=0;index < _varVec.size();index++)
    {
        map<string,sole::Data>& m = _varVec[index];

        map<string,sole::Data>::iterator it = m.find(vName);

        if(it != m.end())
        {
            return true;
        }
        
    }

    if(vName == "flow")
    {
        return true;
    }

    return false;
}

bool SoleParse::checkAlias(string vName)
{
    for(size_t index=0;index < _varVec.size();index++)
    {
        map<string,sole::Data>& m = _varVec[index];

        map<string,sole::Data>::iterator it = m.find(vName);

        if(it != m.end())
        {
            if("alias" == it->second.type)
            {
                return true;
            }
        }
    }

    return false;
}

sole::Data SoleParse::getAlias(string vName)
{
    sole::Data d;
    for(size_t index=0;index < _varVec.size();index++)
    {
        map<string,sole::Data>& m = _varVec[index];

        map<string,sole::Data>::iterator it = m.find(vName);

        if(it != m.end())
        {
            if("alias" == it->second.type)
            {
                d = it->second;
                d.type = _TYPE_VAR_;
                return d;
            }
        }
    }

    error(_ERROR_PARSER_1(vName));
    return d;
}

bool SoleParse::checkLocalVar(string vName)
{
    size_t index = 0;
    if(_varVec.size() == 0)
    {
        return false;
    }

    index = _varVec.size() - 1;

    map<string,sole::Data>& m = _varVec[index];

    map<string,sole::Data>::iterator it = m.find(vName);

    if(it != m.end())
    {
        return true;
    }

    if(vName == "flow")
    {
        return true;
    }
    
    return false;
}

void SoleParse::pushVarTranslate()
{
    map<string,sole::Data> m;
    _varVec.push_back(m);
}

void SoleParse::popVarTranslate()
{
    if(_varVec.size() > 0)
    {
        _varVec.pop_back();
    }
}

void SoleParse::checkExpression(sole::Data& e)
{
    if(e.type == _TYPE_EXPRESSION_)
    {
        for(size_t i=0;i < e.v.size();i++)
        {
            checkExpression(e.v[i]);
        }
    }
    else if(e.type == _TYPE_VAR_)
    {
        if(false == checkVar(e.sV))
        {
            error(_ERROR_PARSER_2(e.sV));
        }

        if(checkAlias(e.sV))
        {
            sole::Data ed = e;
            e = getAlias(e.sV);
            for(size_t i=0;i < ed.v.size();i++)
            {
                e.v.push_back(ed.v[i]);
            }
        }
    }
}

void SoleParse::addLocalVar(string sName,sole::Data& d)
{
    size_t index = 0;
    if(_varVec.size() == 0)
    {
        pushVarTranslate();
    }

    index = _varVec.size() - 1;

    map<string,sole::Data>& m = _varVec[index];

    m[sName] = d;
    m[sName].type = "alias";
}

void SoleParse::addLocalVar(string vName)
{
    size_t index = 0;
    if(_varVec.size() == 0)
    {
        pushVarTranslate();
    }

    index = _varVec.size() - 1;

    map<string,sole::Data>& m = _varVec[index];

    sole::Data d;
    d.sV = vName;
    d.type = _TYPE_VAR_;

    m[vName] = d;
}

void SoleParse::defAlias(sole::Data& e,sole::Data& s)
{
    if(_TYPE_EXPRESSION_ == e.type)
    {
        if(e.v.size()!=3)
        {
            error("Definition alias error.");
        }

        if(_TYPE_OPERATOR_ != e.v[1].type)
        {
            error("Definition alias error.");
        }

        if("=" == e.v[1].sV)
        {
            if("Var" != e.v[0].type)
            {
                error("Definition alias error.");
            }

            if(checkLocalVar(e.v[0].sV))
            {
                error("Definition alias error.");
            }

            s.type = "Statement";
            s.sV = "alias";
            //s.v.push_back(e.v[2]);

            addLocalVar(e.v[0].sV,e.v[2]);
        }
        else if("," == e.v[1].sV)
        {
            if(e.v[0].type == _TYPE_VAR_)
            {
                defAlias(e.v[0],s);
            }
            else if(e.v[0].type == _TYPE_EXPRESSION_ )
            {
                defAlias(e.v[0],s);
            }
            else
            {
                error("Definition alias error.");
            }

            if(e.v[2].type == _TYPE_VAR_)
            {
                defAlias(e.v[2],s);
            }
            else if(e.v[2].type == _TYPE_EXPRESSION_)
            {
                defAlias(e.v[2],s);
            }
            else
            {
                error("Definition alias error.");
            }
        }
        else
        {
            error("Definition alias error.");
        }
    }
    else
    {
        error("Definition alias error.");
    }
}

void SoleParse::defVar(sole::Data& e,sole::Data& s)
{
    if(_TYPE_EXPRESSION_ == e.type)
    {
        if(e.v.size()!=3)
        {
            error("Definition variable error.");
        }

        if(_TYPE_OPERATOR_ != e.v[1].type)
        {
            error("Definition variable error.");
        }

        if("=" == e.v[1].sV)
        {
            if("Var" != e.v[0].type)
            {
                error("Definition variable error.");
            }

            if(checkLocalVar(e.v[0].sV))
            {
                error("Definition variable error.");
            }

            s.type = "Statement";
            s.sV = "var";
            s.v.push_back(e);
            addLocalVar(e.v[0].sV);
        }
        else if("," == e.v[1].sV)
        {
            if(e.v[0].type == _TYPE_VAR_)
            {
                defVar(e.v[0],s);
            }
            else if(e.v[0].type == _TYPE_EXPRESSION_ )
            {
                defVar(e.v[0],s);
            }
            else
            {
                error("Definition variable error.");
            }

            if(e.v[2].type == _TYPE_VAR_)
            {
                defVar(e.v[2],s);
            }
            else if(e.v[2].type == _TYPE_EXPRESSION_)
            {
                defVar(e.v[2],s);
            }
            else
            {
                error("Definition variable error.");
            }
        }
        else
        {
            error("Definition variable error.");
        }
    }
    else if(_TYPE_VAR_ == e.type)
    {
        if(checkLocalVar(e.sV))
        {
            //
            error("Definition variable error.");
        }

        s.type = _TYPE_STATEMENT_;
        s.sV = "var";
        sole::Data ex;
        ex.type = _TYPE_EXPRESSION_;
        ex.v.push_back(sole::Data());
        ex.v.push_back(sole::Data());
        ex.v.push_back(sole::Data());
        ex.v[0].type = "Var";
        ex.v[0].sV = e.sV;
        ex.v[1].type = "Operator";
        ex.v[1].sV = "=";
        ex.v[2].type = "Long";
        ex.v[2].nV = 0;
        s.v.push_back(ex);
        addLocalVar(e.sV);
    }
    else
    {
        error("Definition variable error.");
    }
}

void SoleParse::json2Data(string str,sole::Data& d)
{
    try
    {
        json2Data(tars::TC_Json::getValue(str),d);
    }
    catch(tars::TC_Json_Exception& e)
    {
        string err = e.what();
        g_parse->error("Wrong use of object constant type," + err);
    }
    catch(tars::TC_Exception& e)
    {
        string err = e.what();
        g_parse->error("Wrong use of object constant type," + err);
    }
    catch(...)
    {
        g_parse->error("Wrong use of object constant type.");
    }
}

void SoleParse::json2Data(tars::JsonValuePtr p,sole::Data& d)
{
    if(p->getType() == tars::eJsonTypeString)
    {
        d.type = "String";
        tars::JsonValueStringPtr a = tars::JsonValueStringPtr::dynamicCast(p);
        d.sV = a->value;
    }
    else if(p->getType() == tars::eJsonTypeNum)
    {
        if(tars::JsonValueNumPtr::dynamicCast(p)->isInt)
        {
            d.type = "Long";
            tars::JsonValueNumPtr a = tars::JsonValueNumPtr::dynamicCast(p);
            d.nV = a->value;
        }
        else
        {
            d.type = "Double";
            tars::JsonValueNumPtr a = tars::JsonValueNumPtr::dynamicCast(p);
            d.dV = a->value;
        }
    }
    else if(p->getType() == tars::eJsonTypeObj)
    {
        d.type = "Obj";
        tars::JsonValueObjPtr a = tars::JsonValueObjPtr::dynamicCast(p);
        for(unordered_map<string,tars::JsonValuePtr>::iterator it = a->value.begin();it != a->value.end();it++)
        {
            d.m[it->first] = sole::Data();
            json2Data(it->second,d.m[it->first]);
        }
    }
    else if(p->getType() == tars::eJsonTypeArray)
    {
        d.type = "Arr";
        tars::JsonValueArrayPtr a = tars::JsonValueArrayPtr::dynamicCast(p);
        for(size_t i=0;i<a->value.size();i++)
        {
            d.v.push_back(sole::Data());
            json2Data(a->value[i],d.v[i]);
        }
    }
    else if(p->getType() == tars::eJsonTypeBoolean)
    {
        d.type = "Bool";
        tars::JsonValueBooleanPtr a = tars::JsonValueBooleanPtr::dynamicCast(p);
        d.nV = a->getValue();
    }
}

sole::Data SoleParse::unitIf(sole::Data& e,sole::Data& s)
{
    if(_TYPE_EXPRESSION_ == e.type)
    {
        sole::Data d;
        d.v.push_back(sole::Data());
        d.v[0] = e;
        for(size_t i=0 ;i < s.v.size();i++)
        {
            d.v.push_back(sole::Data());
            d.v[i+1] = s.v[i];
        }

        return d;
    }
    else
    {
        sole::Data d;
        sole::Data ee;
        ee.type = _TYPE_EXPRESSION_;
        ee.v.push_back(e);
        d.v.push_back(sole::Data());
        d.v[0] = ee;
        for(size_t i=0 ;i < s.v.size();i++)
        {
            d.v.push_back(sole::Data());
            d.v[i+1] = s.v[i];
        }

        return d;
    }

}

sole::Data SoleParse::unitIf(sole::Data& s)
{
    sole::Data d;
    sole::Data e;
    e.type = _TYPE_EXPRESSION_;
    e.v.push_back(sole::SoleTools::newBool(true));
    d.v.push_back(sole::Data());
    d.v[0] = e;
    for(size_t i=0 ;i < s.v.size();i++)
    {
        d.v.push_back(sole::Data());
        d.v[i+1] = s.v[i];
    }

    return d;
}

void SoleParse::stateIf(sole::Data& ifS,sole::Data& ifU)
{
    ifS.v.push_back(ifU);
}