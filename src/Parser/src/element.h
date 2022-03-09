#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <stack>
#include <sstream>
#include "errno.h"
#include "util/tc_autoptr.h"
#include "util/tc_json.h"
#include "ComShare.h"

using namespace std;


void yyerror(char const *msg);

/**
 * 语法元素基类
 */
class GrammarBase : virtual public tars::TC_HandleBase
{
public:
    virtual ~GrammarBase(){};
};

typedef tars::TC_AutoPtr<GrammarBase> GrammarBasePtr;

/**
 * 解析过程中的字符串
 */
class StringGrammar : public GrammarBase
{
public:

    StringGrammar() { }
    string v;
};

typedef tars::TC_AutoPtr<StringGrammar> StringGrammarPtr;

/**
 * 解析过程中的运算符
 */
class OperGrammar : public GrammarBase
{
public:

    OperGrammar() { }
    string v;
};

typedef tars::TC_AutoPtr<OperGrammar> OperGrammarPtr;

/**
 * 解析过程中的整形数
 */
class IntergerGrammar : public GrammarBase
{
public:

    IntergerGrammar():v(0) { }
    long long v;
};

typedef tars::TC_AutoPtr<IntergerGrammar> IntergerGrammarPtr;

/**
 * 解析过程中的浮点数
 */
class FloatGrammar : public GrammarBase
{
public:

    FloatGrammar():v(0.0f) { }
    double v;
};

typedef tars::TC_AutoPtr<FloatGrammar> FloatGrammarPtr;

/**
 * 解析过程中的bool类型
 */
class BoolGrammar : public GrammarBase
{
public:

    BoolGrammar():v(false) { }
    bool v;
};

typedef tars::TC_AutoPtr<BoolGrammar> BoolGrammarPtr;

/**
 * 解析过程中的数组类型
 */
class ArrayGrammar : public GrammarBase
{
public:

    ArrayGrammar() { }
    tars::JsonValueArrayPtr v;
};

typedef tars::TC_AutoPtr<ArrayGrammar> ArrayGrammarPtr;

/**
 * 解析过程中的对象类型
 */
class ObjectGrammar : public GrammarBase
{
public:

    ObjectGrammar() { }
    tars::JsonValueObjPtr v;
};

typedef tars::TC_AutoPtr<ObjectGrammar> ObjectGrammarPtr;

/**
 * 解析过程中的变量类型
 */
class VarGrammar : public GrammarBase
{
public:

    VarGrammar():t(LONG) { }

    enum
    {
        LONG,
        DOUBLE,
        STRING,
        BOOL,
        ARRAY,
        OBJECT
    };

    int    t;
    GrammarBasePtr v;
    string n;
};

typedef tars::TC_AutoPtr<VarGrammar> VarGrammarPtr;

/**
 * 解析过程中的常类型
 */
class ConstGrammar : public GrammarBase
{
public:

    ConstGrammar():t(LONG) { }

    enum
    {
        LONG,
        DOUBLE,
        STRING,
        BOOL,
        ARRAY,
        OBJECT
    };

    int    t;
    GrammarBasePtr v;
    string n;
};

typedef tars::TC_AutoPtr<ConstGrammar> ConstGrammarPtr;

/**
 * 解析过程中的表达式
 */

class ExpGrammar;
typedef tars::TC_AutoPtr<ExpGrammar> ExpGrammarPtr;

class ExpGrammar : public GrammarBase
{
public:

    ExpGrammar():t(LONG) { }

    enum
    {
        LONG,
        DOUBLE,
        STRING,
        BOOL,
        ARRAY,
        OBJECT,
        VAR,
        OPER,
        EXP
    };

    int    t;
    string ident;
    GrammarBasePtr v;
    vector<ExpGrammarPtr> eV;
};

class DataGrammar : public GrammarBase
{
public:
    DataGrammar() { }
    sole::Data v;
};
typedef tars::TC_AutoPtr<DataGrammar> DataGrammarPtr;


/**
 * 上下文
 */
class Context : public tars::TC_HandleBase
{
public:
    /**
     * 构造函数
     */
    Context(const string &file) : _currline(1), _filename(file)
    {
    }

    /**
     * 下一行
     */
    void nextLine() { _currline++; }

    /**
     * 目前的行
     * 
     * @return size_t
     */
    size_t getCurrLine() { return _currline; }

    /**
     * 当前文件名
     * 
     * @return string
     */
    string getFileName() { return _filename; }

    /**
     * 添加include的文件
     * @param incl
     */
    void addInclude(const string &incl);

    /**
     * 获取includes的文件
     * 
     * @return vector<string>
     */
    vector<string> getIncludes() { return _includes; }

protected:
    size_t                  _currline;
    string                  _filename;
    vector<string>          _includes;
};

typedef tars::TC_AutoPtr<Context> ContextPtr;

#endif