
#ifndef __SOLE_PARSE_H_
#define __SOLE_PARSE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <stack>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include "element.h"
#include "util/tc_common.h"
#include "util/tc_autoptr.h"
#include "ComShare.h"

using namespace std;

/**
 * Sole文件解析类
 *
 */
class SoleParse : public tars::TC_HandleBase
{
public:
    /**
     * 构造函数
     */
    SoleParse();

    /**
     * 解析某一个文件
     * @param sFileName
     */
    void parse(const string &sFileName);

    /**
     * 错误提示
     * @param msg
     */
    void error(const string &msg);

    /**
     * 检查关键字
     * @param s
     *
     * @return int
     */
    int  checkKeyword(const string &s);

    /**
     * 下一行
     */
    void nextLine();

    bool checkVar(string vName);
    bool checkAlias(string vName);
    sole::Data getAlias(string vName);

    bool checkLocalVar(string vName);
    void addLocalVar(string vName);
    void addLocalVar(string vName,sole::Data& d);
    void pushVarTranslate();
    void popVarTranslate();

    void addVar(string n);
    void defVar(sole::Data& e,sole::Data& s);
    void json2Data(tars::JsonValuePtr p,sole::Data& d);
    void json2Data(string str,sole::Data& d);

    sole::Data unitIf(sole::Data& e,sole::Data& s);
    sole::Data unitIf(sole::Data& s);

    void stateIf(sole::Data& ifS,sole::Data& ifU);

    void checkExpression(sole::Data& e);

    void defAlias(sole::Data& e,sole::Data& s);

protected:
    /**
     * 初始化
     */
    void initScanner();

    /**
     * 清除
     */
    void clear();

protected:
    std::stack<ContextPtr>          _contexts;
    std::map<std::string, int>      _keywordMap;
    std::vector< map<string,sole::Data> >  _varVec;
public:
    sole::Data                       _statment;
    sole::Data                       _flow;
};

extern int yyparse();
extern int yylex();
extern FILE *yyin, *yyout;

typedef tars::TC_AutoPtr<SoleParse> SoleParsePtr;

extern SoleParsePtr g_parse;

#endif
