%option outfile="sole.lex.cpp"
%option   yylineno
%{
#include <map>
#include <string>
#include <sstream>
#include <cassert>
#include <errno.h>
#include <math.h>

#define YYSTYPE GrammarBasePtr

#include "parse.h"
#include "sole.tab.hpp"
#include "util/tc_json.h"
#include "SoleTools.h"

using namespace std;

extern "C"
{
    int yywrap()
    {
        return 1;
    }
}

int isatty(int)
{
	return 0;
}

%}

sole_identifiers         [[:alpha:]_][[:alnum:]_]*
sole_anychar             .
sole_const_int           (-)?((0[0-7]+)|(0x[[:xdigit:]]+)|([[:digit:]]+))
sole_float_literal       (-)?(([[:digit:]]*\.[[:digit:]]+)|([[:digit:]]+\.))
sole_float_exp           (e|E)(\+|-)?[[:digit:]]+
sole_const_float         (({sole_float_literal}{sole_float_exp}?)|((\+|-)?[[:digit:]]+{sole_float_exp}))[fF]?

%x ARRAY
%x OBJECT
%%

"array"[ \t\n]*":"[ \t\n]*   {
    string text = yytext;
    
    for(size_t i=0;i < text.size();i++)
    {
        char c = text[i];
        if(c == '\n')
        {
            
            g_parse->nextLine();
        }
    }

    BEGIN(ARRAY); 
}

"object"[ \t\n]*":"[ \t\n]*   {
    string text = yytext;
    //
    for(size_t i=0;i < text.size();i++)
    {
        char c = text[i];
        if(c == '\n')
        {
            //
            g_parse->nextLine();
        }
    }
    BEGIN(OBJECT); 
}

<<EOF>> {
    yyterminate();
}

"//" {
    // C++ comment
    bool e = false;
    while(!e)
    {
        int input = yyinput();
        if(input == '\n')
    	{
    	    g_parse->nextLine();
    	}
    	
    	if(input == '\n' || input == EOF)
    	{
    	    e = true;
    	}
    }
}

"/*" {
    // C comment
    bool e = false;
    string comment = yytext + 2;
    while(!e)
    {
        int input = yyinput();
        switch(input)
        {
            case '*':
            {
                int nextInput = yyinput();
                if(nextInput == '/')
                {
                    e = true;
                }
                else
                {
                    comment += static_cast<char>(input);
                    unput(nextInput);
                }
                break;
            }
            case '\n':
            {
                comment += static_cast<char>(input);
                g_parse->nextLine();
                break;
            }
            case EOF:
            {
                g_parse->error("EOF in comment");
                e = true; 
                break;
            }
            default:
            {
                comment += static_cast<char>(input);
                break;
            }
        }
    }

    if(comment[0] == '*')
    {
        //
    }
}

{sole_identifiers}    {
    DataGrammarPtr ident  = new DataGrammar();
    ident->v.sV            = yytext;
    yylval              = ident;
    //
    return g_parse->checkKeyword(yytext);
}

"=="    { 
    return(EQ_OP); 
}

"!="    { 
    return(NE_OP); 
}

"<="    { 
    return(LE_OP); 
}

">="    { 
    return(GE_OP); 
}

"||"    { 
    return(OR_OP); 
}

"&&"    { 
    return(AND_OP); 
}

\"  {
    string str = "";
    bool e = false;
    while(!e)
    {
    	int input = yyinput();
    	switch(input)
    	{
    	    case '"':
    	    {
    	        e = true;
    	        break;
    	    }
    	    case '\n':
    	    {
    	        g_parse->error("newline in string");
    	        break;
    	    }
    	    case EOF:
    	    {
    	        g_parse->error("EOF in string");
    	        break;
    	    }
    	    case '\\':
    	    {
    	        static string specialChars = "nrtvfab?";
    	        static string octalChars = "0123";
    	        
    	        char nextInput = static_cast<char>(yyinput());
    	        if(nextInput == '\\' || nextInput == '"' || nextInput == '\'')
    	        {
    	            str += nextInput;
    	        }
    	        else if(specialChars.find(nextInput) != string::npos)
                {
                    str += '\\';
                    str += nextInput;
                }
                else if(octalChars.find(nextInput) != string::npos)
                {
                    static string octalDigits = "01234567";
                    
                    unsigned short us = nextInput - '0';
                    if(octalDigits.find_first_of(nextInput = static_cast<char>(yyinput())) != string::npos)
                    {
                        us = us * 8 + nextInput - '0';
                        if(octalDigits.find_first_of(nextInput = static_cast<char>(yyinput())) != string::npos)
                        {
                            us = us * 8 + nextInput - '0';
                        }
                        else
                        {
                            unput(nextInput);
                        }
                    }
                    else
                    {
                        unput(nextInput);
                    }

                    if(us == 0)
                    {
                        g_parse->error("illegal NUL character in string constant");
                    }
                    str += static_cast<char>(us);
                }
                else if(nextInput == 'x')
                {
                    long long ull = 0;
                    while(isxdigit(nextInput = static_cast<char>(yyinput())))
                    {
                        ull *= 16;
                        if(isdigit(nextInput))
                        {
                            ull += nextInput - '0';
                        }
                        else if(islower(nextInput))
                        {
                            ull += nextInput - 'a' + 10;
                        }
                        else
                        {
                            ull += nextInput - 'A' + 10;
                        }
                    }

                    unput(nextInput);

                    if(ull == 0)
                    {
                        g_parse->error("illegal NUL character in string constant");
                    }
                    str += static_cast<char>(ull);
                }
                else
                {
                    str += static_cast<char>(input);
                }

                break;
    	    }
    	    default:
    	    {
    	        str += static_cast<char>(input);
    	        break;
    	    }
    	}
    }

    DataGrammarPtr csPtr = new DataGrammar;
    csPtr->v = sole::SoleTools::newString(str);
    yylval = csPtr;
    return SOLE_STRING_LITERAL;
}


{sole_const_int}    {
    errno = 0;
    DataGrammarPtr ptr = new DataGrammar();
    yylval = ptr;
    
    string value = yytext;
    const char* beg = value.c_str();
    char* e = 0;

    ptr->v = sole::SoleTools::newLong(strtoll(beg, &e, 0));
    
    if(!(errno == 0 && beg != e))
    {
        assert(ptr->v.nV != 0);
        string err = "integer constant `";
        err += value;
        err += "' out of range";
        g_parse->error(err);
    }

    //
    
    return SOLE_CONST_INTEGER;
}

{sole_const_float}    {
    errno = 0;
    DataGrammarPtr ptr = new DataGrammar();
    yylval = ptr;
    
    string value(yytext);
    
    char lastChar = value[value.size() - 1];
    
    if ( lastChar == 'f' || lastChar == 'F')
    {
        value = value.substr(0, value.size() - 1);
    }

    ptr->v = sole::SoleTools::newDouble(strtod(value.c_str(),0),0);

    if((errno == ERANGE)&&(ptr->v.dV == HUGE_VAL||ptr->v.dV == -HUGE_VAL))
    {
        string err = "float point constant `";
        err += value;
        err += "' too large (overflow)";
        g_parse->error(err);
    }
    else if(errno == ERANGE && ptr->v.dV == 0)
    {
        string err = "float point constant `";
        err += value;
        err += "' too small (underflow)";
        g_parse->error(err);
    }

    //
    return SOLE_CONST_FLOAT;
}

<ARRAY>\[     {
	string str = "[";
    bool e = false;
	int dep = 0;
    while(!e)
    {
    	int input = yyinput();
    	switch(input)
    	{
    	    case ']':
    	    {
				str += "]";
				
				if(0 >= dep)
				{
				    e = true;
				}
				else
				{
				    dep--;
				}
    	        
    	        break;
    	    }
			case '[':
    	    {
				str += "[";
    	        dep ++;
    	        break;
    	    }
    	    case EOF:
    	    {
    	        g_parse->error("EOF in array");
    	        break;
    	    }
    	    case '\\':
    	    {
    	        static string specialChars = "nrtvfab?";
    	        static string octalChars = "0123";
    	        str += "\\";
    	        char nextInput = static_cast<char>(yyinput());
    	        if(nextInput == '\\' || nextInput == '"' || nextInput == '\'')
    	        {
    	            str += nextInput;
    	        }
    	        else if(specialChars.find(nextInput) != string::npos)
                {
                    str += '\\';
                    str += nextInput;
                }
                else if(octalChars.find(nextInput) != string::npos)
                {
                    static string octalDigits = "01234567";
                    
                    unsigned short us = nextInput - '0';
                    if(octalDigits.find_first_of(nextInput = static_cast<char>(yyinput())) != string::npos)
                    {
                        us = us * 8 + nextInput - '0';
                        if(octalDigits.find_first_of(nextInput = static_cast<char>(yyinput())) != string::npos)
                        {
                            us = us * 8 + nextInput - '0';
                        }
                        else
                        {
                            unput(nextInput);
                        }
                    }
                    else
                    {
                        unput(nextInput);
                    }

                    if(us == 0)
                    {
                        g_parse->error("illegal NUL character in array constant");
                    }
                    str += static_cast<char>(us);
                }
                else if(nextInput == 'x')
                {
                    long long ull = 0;
                    while(isxdigit(nextInput = static_cast<char>(yyinput())))
                    {
                        ull *= 16;
                        if(isdigit(nextInput))
                        {
                            ull += nextInput - '0';
                        }
                        else if(islower(nextInput))
                        {
                            ull += nextInput - 'a' + 10;
                        }
                        else
                        {
                            ull += nextInput - 'A' + 10;
                        }
                    }

                    unput(nextInput);

                    if(ull == 0)
                    {
                        g_parse->error("illegal NUL character in array constant");
                    }
                    str += static_cast<char>(ull);
                }
                else
                {
                    str += static_cast<char>(input);
                }

                break;
    	    }
            case '\n':
    	    {
				str += "\n";
    	        str += static_cast<char>(input);
                g_parse->nextLine();
    	        break;
    	    }
    	    default:
    	    {
    	        str += static_cast<char>(input);
    	        break;
    	    }
    	}
    }

    DataGrammarPtr aPtr = new DataGrammar();
    
    g_parse->json2Data(str,aPtr->v);

    yylval = aPtr;
    BEGIN(INITIAL);
    return SOLE_CONST_ARRAY;
}

<OBJECT>\{     {
	string str = "{";
    bool e = false;
	int dep = 0;
    while(!e)
    {
    	int input = yyinput();
    	switch(input)
    	{
    	    case '}':
    	    {
				str += "}";
				
				if(0 >= dep)
				{
				    e = true;
				}
				else
				{
				    dep--;
				}
    	        
    	        break;
    	    }
			case '{':
    	    {
				str += "{";
    	        dep ++;
    	        break;
    	    }
    	    case EOF:
    	    {
    	        g_parse->error("EOF in array");
    	        break;
    	    }
    	    case '\\':
    	    {
    	        static string specialChars = "nrtvfab?";
    	        static string octalChars = "0123";
    	        str += "\\";
    	        char nextInput = static_cast<char>(yyinput());
    	        if(nextInput == '\\' || nextInput == '"' || nextInput == '\'')
    	        {
    	            str += nextInput;
    	        }
    	        else if(specialChars.find(nextInput) != string::npos)
                {
                    str += '\\';
                    str += nextInput;
                }
                else if(octalChars.find(nextInput) != string::npos)
                {
                    static string octalDigits = "01234567";
                    
                    unsigned short us = nextInput - '0';
                    if(octalDigits.find_first_of(nextInput = static_cast<char>(yyinput())) != string::npos)
                    {
                        us = us * 8 + nextInput - '0';
                        if(octalDigits.find_first_of(nextInput = static_cast<char>(yyinput())) != string::npos)
                        {
                            us = us * 8 + nextInput - '0';
                        }
                        else
                        {
                            unput(nextInput);
                        }
                    }
                    else
                    {
                        unput(nextInput);
                    }

                    if(us == 0)
                    {
                        g_parse->error("illegal NUL character in array constant");
                    }
                    str += static_cast<char>(us);
                }
                else if(nextInput == 'x')
                {
                    long long ull = 0;
                    while(isxdigit(nextInput = static_cast<char>(yyinput())))
                    {
                        ull *= 16;
                        if(isdigit(nextInput))
                        {
                            ull += nextInput - '0';
                        }
                        else if(islower(nextInput))
                        {
                            ull += nextInput - 'a' + 10;
                        }
                        else
                        {
                            ull += nextInput - 'A' + 10;
                        }
                    }

                    unput(nextInput);

                    if(ull == 0)
                    {
                        g_parse->error("illegal NUL character in array constant");
                    }
                    str += static_cast<char>(ull);
                }
                else
                {
                    str += static_cast<char>(input);
                }

                break;
    	    }
            case '\n':
    	    {
				str += "\n";
    	        str += static_cast<char>(input);
                g_parse->nextLine();
    	        break;
    	    }
    	    default:
    	    {
    	        str += static_cast<char>(input);
    	        break;
    	    }
    	}
    }

    DataGrammarPtr oPtr = new DataGrammar;

    g_parse->json2Data(str,oPtr->v);

    yylval = oPtr;
    BEGIN(INITIAL);
    return SOLE_CONST_OBJECT;
}

[[:space:]]     {
    if(yytext[0] == '\n')
    {
        g_parse->nextLine();
    }
}

{sole_anychar}       {
    if(yytext[0] < 32 || yytext[0] > 126)
    {
        stringstream s;
        s << "illegal input character: '\\";
        s.width(3);
        s.fill('0');
        s << oct << static_cast<int>(static_cast<unsigned char>(yytext[0]));
        s << "'";
        
        g_parse->error(s.str());
        return BAD_CHAR;
    }

    //

    return yytext[0];
}

%%