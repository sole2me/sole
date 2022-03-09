%{
#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

#define YYSTYPE GrammarBasePtr

#include "parse.h"
#include "SoleTools.h"
#include "SolePublic.h"
#define YYDEBUG 1
#define YYINITDEPTH 10000

%}

%defines
%debug

//keyword token

%token SOLE_IDENTIFIER
%token SOLE_CONST_INTEGER
%token SOLE_CONST_FLOAT
%token SOLE_CONST_ARRAY
%token SOLE_CONST_OBJECT
%token SOLE_FALSE
%token SOLE_TRUE
%token SOLE_STRING_LITERAL
%token SOLE_CONST
%token BAD_CHAR
%token SOLE_VAR
%token SOLE_ALIAS
%token SOLE_FLOW

%token SOLE_IF
%token SOLE_ELSE
%token SOLE_FOR
%token SOLE_EVENT
%token SOLE_END
%token SOLE_THEN
%token SOLE_ELSE_IF

%token LE_OP GE_OP EQ_OP NE_OP OR_OP AND_OP

%left ',' 
%left '=' 
%left OR_OP 
%left AND_OP 
%left EQ_OP NE_OP
%left '<' '>' LE_OP GE_OP
%left '-' '+' 
%left '*' '/' '%'
%left '!'
%left '['

%nonassoc UMINUS

%start context;
%%

context:
    statments
    {
        if($1)
        {
            DataGrammarPtr s1 = DataGrammarPtr::dynamicCast($1);
            g_parse->_statment = s1->v;
        }
    };
statments:
    {
        DataGrammarPtr s0 = new DataGrammar();
        
        $$ = s0;
    }
    |
    statments statment ';'
    {
        DataGrammarPtr s1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr s2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s0 = DataGrammarPtr::dynamicCast($$);
        s0->v.type = "Statement";
        s0->v.v.push_back(s2->v);
    }
    | statments error ';'
    {
        yyerrok;
    }
    | statments ';'
    {
    }
    ;

statment:
    definition
    {
        $$ = $1;
    }
    |
    expression
    {
        $$ = $1;
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        g_parse->checkExpression(e1->v);

        if(_TYPE_EXPRESSION_ != e1->v.type)
        {
            e1->v = sole::SoleTools::newExpression(e1->v);
        }
    }
    |
    if_statment
    {
        $$ = $1;
    }
    ;

if_statment:
    SOLE_IF expression SOLE_THEN statments SOLE_END SOLE_IF
    {
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s4 = DataGrammarPtr::dynamicCast($4);
        DataGrammarPtr s0 = new DataGrammar();

        sole::Data ifU = g_parse->unitIf(e2->v,s4->v);
        s0->v.type = "Statement";
        s0->v.sV = "if";
        g_parse->stateIf(s0->v,ifU);
        //g_parse->popVarTranslate();
        $$ = s0;
    }
    |
    SOLE_IF expression SOLE_THEN statments else_statment
    {
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s4 = DataGrammarPtr::dynamicCast($4);
        DataGrammarPtr s5 = DataGrammarPtr::dynamicCast($5);
        DataGrammarPtr s0 = new DataGrammar();

        sole::Data ifU = g_parse->unitIf(e2->v,s4->v);
        g_parse->stateIf(s0->v,ifU);

        for(size_t i=0;i<s5->v.v.size();i++)
        {
            g_parse->stateIf(s0->v,s5->v.v[i]);
        }

        s0->v.type = "Statement";
        s0->v.sV = "if";
        //g_parse->popVarTranslate();
        $$ = s0;
    }
    |
    SOLE_IF expression SOLE_THEN statments else_if_statment
    {
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s4 = DataGrammarPtr::dynamicCast($4);
        DataGrammarPtr s5 = DataGrammarPtr::dynamicCast($5);
        DataGrammarPtr s0 = new DataGrammar();
        
        sole::Data ifU = g_parse->unitIf(e2->v,s4->v);
        g_parse->stateIf(s0->v,ifU);
        for(size_t i=0;i<s5->v.v.size();i++)
        {
            g_parse->stateIf(s0->v,s5->v.v[i]);
        }
        s0->v.type = "Statement";
        s0->v.sV = "if";
        //g_parse->popVarTranslate();
        $$ = s0;
    }
    ;

else_statment
    : SOLE_ELSE statments SOLE_END SOLE_IF
    {
        DataGrammarPtr s2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s0 = new DataGrammar();

        sole::Data ifU = g_parse->unitIf(s2->v);

        g_parse->stateIf(s0->v,ifU);
        //g_parse->popVarTranslate();
        $$ = s0;
    }
    ;

else_if_statment
    : SOLE_ELSE_IF expression SOLE_THEN statments SOLE_END SOLE_IF
    {
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s4 = DataGrammarPtr::dynamicCast($4);
        DataGrammarPtr s0 = new DataGrammar();

        sole::Data ifU = g_parse->unitIf(e2->v,s4->v);

        g_parse->stateIf(s0->v,ifU);
        //g_parse->popVarTranslate();
        $$ = s0;
    }
    |
    SOLE_ELSE_IF expression SOLE_THEN statments else_if_statment
    {
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s4 = DataGrammarPtr::dynamicCast($4);
        DataGrammarPtr s5 = DataGrammarPtr::dynamicCast($5);
        DataGrammarPtr s0 = new DataGrammar();

        sole::Data ifU = g_parse->unitIf(e2->v,s4->v);
        g_parse->stateIf(s0->v,ifU);

        for(size_t i=0;i<s5->v.v.size();i++)
        {
            g_parse->stateIf(s0->v,s5->v.v[i]);
        }
        //g_parse->popVarTranslate();
        $$ = s0;
    }
    |
    SOLE_ELSE_IF expression SOLE_THEN statments else_statment
    {
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s4 = DataGrammarPtr::dynamicCast($4);
        DataGrammarPtr s5 = DataGrammarPtr::dynamicCast($5);
        DataGrammarPtr s0 = new DataGrammar();

        sole::Data ifU = g_parse->unitIf(e2->v,s4->v);
        g_parse->stateIf(s0->v,ifU);

        for(size_t i=0;i<s5->v.v.size();i++)
        {
            g_parse->stateIf(s0->v,s5->v.v[i]);
        }

        //g_parse->popVarTranslate();
        $$ = s0;
    }
    ;

definition
    : SOLE_VAR expression
    {
        DataGrammarPtr s2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s0 = new DataGrammar();
       // 
        g_parse->defVar(s2->v,s0->v);
        g_parse->checkExpression(s2->v);
       // 
        $$ = s0;
    }
    | SOLE_ALIAS expression
    {
        DataGrammarPtr s2 = DataGrammarPtr::dynamicCast($2);
        DataGrammarPtr s0 = new DataGrammar();

        g_parse->defAlias(s2->v,s0->v);
        g_parse->checkExpression(s2->v);
        $$ = s0;
    }
    ;

expression
    : SOLE_CONST_INTEGER
    {
        $$ = $1;
    }
    | SOLE_CONST_FLOAT
    {
        $$ = $1;
    }
    | SOLE_FLOW
    {
        DataGrammarPtr d = DataGrammarPtr::dynamicCast($1);
        d->v.type = _TYPE_VAR_;
        $$ = d;
    }
    | SOLE_STRING_LITERAL
    {
        $$ = $1;
    }
    | SOLE_FALSE
    {
        DataGrammarPtr b = new DataGrammar();
        b->v = sole::SoleTools::newBool(false);
        $$ = b;
    }
    | SOLE_TRUE
    {
        DataGrammarPtr b = new DataGrammar();
        b->v = sole::SoleTools::newBool(true);
        $$ = b;
    }
    | SOLE_IDENTIFIER
    {
        DataGrammarPtr d = DataGrammarPtr::dynamicCast($1);
        d->v.type = _TYPE_VAR_;
        // 
        $$ = d;
    }
    | SOLE_CONST_ARRAY
    {
        $$ = $1;
    }
    | SOLE_CONST_OBJECT
    {
        $$ = $1;
    }
    |
    expression '+' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"+",e3->v);
        $$ = e0;
    }
    | expression '-' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"-",e3->v);
        $$ = e0;
    }
    | expression '*' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"*",e3->v);
        $$ = e0;
    }
    | expression '/' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"/",e3->v);
        $$ = e0;
    } 
    | expression '%' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"%",e3->v);
        $$ = e0;
    } 
    | expression '=' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"=",e3->v);
        $$ = e0;
    } 
    | expression ',' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,",",e3->v);
        $$ = e0;
    } 
    | '!' expression
    {
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        e0->v = sole::SoleTools::newExpression("!",e2->v);
        $$ = e0;
    } 
    | '-' expression %prec UMINUS
    { 
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        e0->v = sole::SoleTools::newExpression("-",e2->v);
        $$ = e0;
    }
    | '(' expression ')'
    {
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e2 = DataGrammarPtr::dynamicCast($2);
        e0->v = sole::SoleTools::newExpression(e2->v);
        $$ = e0;
    }
    | expression OR_OP expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"||",e3->v);
        $$ = e0;
    } 
    | expression AND_OP expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"&&",e3->v);
        $$ = e0;
    } 
    | expression EQ_OP expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"==",e3->v);
        $$ = e0;
    } 
    | expression NE_OP expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"!=",e3->v);
        $$ = e0;
    } 
    | expression '<' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"<",e3->v);
        $$ = e0;
    } 
    | expression '>' expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,">",e3->v);
        $$ = e0;
    } 
    | expression LE_OP expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,"<=",e3->v);
        $$ = e0;
    } 
    | expression GE_OP expression
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e0 = new DataGrammar();
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        e0->v = sole::SoleTools::newExpression(e1->v,">=",e3->v);
        $$ = e0;
    }  
    | expression '[' expression ']'
    {
        DataGrammarPtr e1 = DataGrammarPtr::dynamicCast($1);
        DataGrammarPtr e3 = DataGrammarPtr::dynamicCast($3);
        
        $$ = e1;

        if( e1->v.type == _TYPE_VAR_)
        {
            e1->v.v.push_back(e3->v);
        }
    } 
    ;
%%