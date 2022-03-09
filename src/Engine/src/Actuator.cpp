#include "Actuator.h"
#include "SoleTools.h"
#include "Operator.h"
#include "SolePublic.h"
#include "SoleException.h"

namespace sole
{
    void Actuator::doContext(sole::Data & d,sole::Data & v)
    {
        doStatment(d,v);
    }

    void Actuator::doStatment(sole::Data & d,sole::Data & v)
    {
        if(_TYPE_STATEMENT_ == d.type)
        {
            if(_KEYWORD_IF_ == d.sV)
            {
                doIf(d,v);
            }
            else if(_KEYWORD_VAR_ == d.sV)
            {
                doVar(d,v);
            }
            else
            {
                v.v.push_back(sole::SoleTools::newObject());
                for(size_t i=0;i< d.v.size();i++)
                {
                    doStatment(d.v[i],v);
                }

                cout<<"v:\n"<<v.writeToJsonString()<<endl;
                v.v.pop_back();
            }
        }
        else if(_TYPE_EXPRESSION_ == d.type)
        {
            sole::Data t;
            doExpression(d,v,t);
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"StatmentException:"<<_ERROR_STATMENT_1(d.type) << endl;
            #endif

            throw StatmentException(_ERROR_STATMENT_1(d.type));
        }
    }

    sole::Data& Actuator::getVar(sole::Data & v,sole::Data & vn)
    {
        sole::Data t = vn;
        for(size_t i=0;i<vn.v.size();i++)
        {
            if(_TYPE_STRING_ == vn.v[i].type)
            {
                ;
            }
            else if(_TYPE_LONG_ == vn.v[i].type)
            {
                ;
            }
            else if(_TYPE_VAR_ == vn.v[i].type)
            {
                t.v[i] = getVar(v,vn.v[i]);
            }
            else if(_TYPE_EXPRESSION_ == vn.v[i].type)
            {
                sole::Data st;
                doExpression(vn.v[i],v,st);
                size_t ss = st.v.size();

                if(_TYPE_STRING_ == st.v[ss - 1].type 
                    or _TYPE_LONG_ == st.v[ss - 1].type
                    )
                {
                    t.v[i] = st.v[ss - 1];
                }
                else
                {
                    #ifdef _TEST_flag_
                        cerr<<"StatmentException:"<<_ERROR_VAR_2(st.v[ss - 1].type,vn.sV) << endl;
                    #endif
                    
                    throw StatmentException(_ERROR_VAR_2(st.v[ss - 1].type,vn.sV));
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"StatmentException:"<<_ERROR_VAR_1(vn.v[i].type,vn.sV) << endl;
                #endif
                
                throw StatmentException(_ERROR_VAR_1(vn.v[i].type,vn.sV));
            }
        }
        return sole::SoleTools::getVar(v,t);
    }

    sole::Data& Actuator::getVar4Assign(sole::Data & v,sole::Data & vn)
    {
        sole::Data t = vn;
        for(size_t i=0;i<vn.v.size();i++)
        {
            if(_TYPE_STRING_ == vn.v[i].type)
            {
                ;
            }
            else if(_TYPE_LONG_ == vn.v[i].type)
            {
                ;
            }
            else if(_TYPE_VAR_ == vn.v[i].type)
            {
                t.v[i] = getVar(v,vn.v[i]);
            }
            else if(_TYPE_EXPRESSION_ == vn.v[i].type)
            {
                sole::Data st;
                doExpression(vn.v[i],v,st);
                size_t ss = st.v.size();

                if(_TYPE_STRING_ == st.v[ss - 1].type 
                    or _TYPE_LONG_ == st.v[ss - 1].type
                    )
                {
                    t.v[i] = st.v[ss - 1];
                }
                else
                {
                    #ifdef _TEST_flag_
                        cerr<<"StatmentException:"<<_ERROR_VAR_2(st.v[ss - 1].type,vn.sV) << endl;
                    #endif
                    
                    throw StatmentException(_ERROR_VAR_2(st.v[ss - 1].type,vn.sV));
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"StatmentException:"<<_ERROR_VAR_1(vn.v[i].type,vn.sV) << endl;
                #endif
                
                throw StatmentException(_ERROR_VAR_1(vn.v[i].type,vn.sV));
            }
        }
        return sole::SoleTools::getVar4Assign(v,t);
    }

    void Actuator::doExpression(sole::Data & d,sole::Data & v,sole::Data & t)
    {
        for(size_t i=0;i < d.v.size();i++)
        {
            t.v.push_back(sole::Data());
            if("Expression" == d.v[i].type)
            {
                sole::Data st;
                doExpression(d.v[i],v,st);
                size_t ss = st.v.size();
                t.v[i] = st.v[ss - 1];
            }
            else if("Var" == d.v[i].type)
            {
                t.v[i] = d.v[i];
            }
            else if("Operator" == d.v[i].type)
            {
                t.v[i] = d.v[i];
            }
            else if("Bool" == d.v[i].type)
            {
                t.v[i] = d.v[i];
            }
            else if("Long" == d.v[i].type)
            {
                t.v[i] = d.v[i];
            }
            else if("String" == d.v[i].type)
            {
                t.v[i] = d.v[i];
            }
            else if("Double" == d.v[i].type)
            {
                t.v[i] = d.v[i];
            }
            else if("Obj" == d.v[i].type)
            {
                t.v[i] = d.v[i];
            }
            else if("Arr" == d.v[i].type)
            {
                t.v[i] = d.v[i];
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"StatmentException:"<<_ERROR_EXCEPTION_1(d.v[i].type) << endl;
                #endif
                
                throw StatmentException(_ERROR_EXCEPTION_1(d.v[i].type));
            }
        }

        if(1 == t.v.size())
        {
            t.v.push_back(sole::Data());
            if("Long" == t.v[0].type)
            {
                t.v[1] = t.v[0];
            }
            else if("Double" == t.v[0].type)
            {
                t.v[1] = t.v[0];
            }
            else if("Bool" == t.v[0].type)
            {
                t.v[1] = t.v[0];
            }
            else if("Var" == t.v[0].type)
            {
                t.v[1] = getVar(v,t.v[0]);
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"StatmentException:"<<_ERROR_EXCEPTION_1(t.v[0].type) << endl;
                #endif
                
                throw StatmentException(_ERROR_EXCEPTION_1(t.v[0].type));
            }
        }
        else
        {
            for(size_t i=0 ; i<t.v.size() ; i++)
            {
                if("Operator" == t.v[i].type)
                {
                    Operator op(t.v[i].sV);
                    op.doOperation(v,t,i);
                }
            }
        }
    }

    void Actuator::doIf(sole::Data & d,sole::Data & v)
    {
        for(size_t i=0;i<d.v.size();i++)
        {
            if(doIfBranch(d.v[i],v))
            {
                break;
            }
        }
        
    }

    bool Actuator::doIfBranch(sole::Data & d,sole::Data & v)
    {
        sole::Data t;
        doExpression(d.v[0],v,t);
        bool eFlag = true;
        size_t retIndex = t.v.size() -1;

        if("Bool" == t.v[retIndex].type)
        {
            if(0 == t.v[retIndex].nV)
            {
                eFlag = false;
            }
        }
        else if("Long" == t.v[retIndex].type)
        {
            if(0 == t.v[retIndex].nV)
            {
                eFlag = false;
            }
        }
        else if("Double" == t.v[retIndex].type)
        {
            if(sole::SoleTools::equalZero(t.v[retIndex]))
            {
                eFlag = false;
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"StatmentException:"<<_ERROR_if_1(t.v[retIndex].type) << endl;
            #endif

            throw StatmentException(_ERROR_if_1(t.v[retIndex].type));
        }

        //cout << "eFlag:" << eFlag <<endl;

        if(eFlag)
        {
            v.v.push_back(sole::SoleTools::newObject());
            for(size_t i=1;i< d.v.size();i++)
            {
                doStatment(d.v[i],v);
            }

            v.v.pop_back();
        }

        return eFlag;
    }

    void Actuator::doVar(sole::Data & d,sole::Data & v)
    {
        for(size_t i=0;i<d.v.size();i++)
        {
            string vName = d.v[i].v[0].sV;
            sole::SoleTools::putVar(v,vName);
            sole::Data t;
            sole::Data& e = d.v[i];
            
            doExpression(e,v,t);
        }
    }
}