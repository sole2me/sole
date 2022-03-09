#include "SoleTools.h"
#include "SoleException.h"
#include "SolePublic.h"
#include "util/tc_common.h"

namespace sole
{
    const long SoleTools::_EPSILON_INT64 = 1000000;

    sole::Data SoleTools::newObject()
    {
        sole::Data d;
        d.type = _TYPE_OBJ_;
        return d;
    }

    sole::Data SoleTools::newData(sole::Data & d)
    {
        sole::Data t;
        t = d;
        return t;
    }

    sole::Data SoleTools::newString(string str)
    {
        sole::Data d;
        d.type = _TYPE_STRING_;
        d.sV = str;
        return d;
    }

    sole::Data SoleTools::newLong(long val)
    {
        sole::Data d;
        d.type = _TYPE_LONG_;
        d.nV = val;
        return d;
    }

    sole::Data SoleTools::newDouble(double val,long el)
    {
        sole::Data d;
        d.type = _TYPE_DOUBLE_;
        d.dV = val;
        d.nV = el;
        return d;
    }

    sole::Data SoleTools::newOperator(string o)
    {
        sole::Data d;
        d.type = _TYPE_OPERATOR_;
        d.sV = o;
        return d;
    }

    sole::Data SoleTools::newExpression(sole::Data & l,string o,sole::Data & r)
    {
        sole::Data d;
        d.type = _TYPE_EXPRESSION_;
        d.v.push_back(l);
        d.v.push_back(newOperator(o));
        d.v.push_back(r);
        return d;
    }

    sole::Data SoleTools::newExpression(string o,sole::Data & r)
    {
        sole::Data d;
        d.type = _TYPE_EXPRESSION_;
        d.v.push_back(newOperator(o));
        d.v.push_back(r);
        return d;
    }

    sole::Data SoleTools::newExpression(sole::Data & e)
    {
        sole::Data d;
        d.type = _TYPE_EXPRESSION_;
        d.v.push_back(e);
        return d;
    }

    bool SoleTools::equalZero(sole::Data & val)
    {        
        if(_TYPE_DOUBLE_ == val.type)
        {
            if(0 >= val.nV)
            {
                double epsilon = 1/_EPSILON_INT64;
                if(val.dV < epsilon)
                {
                    return true;
                }
            }
            else
            {
                double epsilon = 1/val.nV;
                if(val.dV < epsilon)
                {
                    return true;
                }
            }
        }
        else if(_TYPE_BOOL_ == val.type)
        {
            if(0 == val.nV)
            {
                return true;
            }
        }
        else if(_TYPE_LONG_ == val.type)
        {
            if(0 == val.nV)
            {
                return true;
            }
        }
        
        return false;
    }

    sole::Data SoleTools::newBool(bool flag)
    {
        sole::Data d;
        d.type = _TYPE_BOOL_;
        if(flag)
        {
            d.nV = 1;
        }
        else
        {
            d.nV = 0;
        }
        
        return d;
    }

    sole::Data SoleTools::subDouble(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_DOUBLE_ != l.type)
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_subDouble_1<<endl;
            #endif
            throw DataException(_TYPE_subDouble_1);
        }

        if(_TYPE_DOUBLE_ != r.type)
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_subDouble_2<<endl;
            #endif
            throw DataException(_TYPE_subDouble_2);
        }

        if(0 < l.nV)
        {
            if(0 < r.nV)
            {
                if(l.nV < r.nV)
                {
                    return newDouble(l.dV - r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV - r.dV,r.nV);
                }
            }
            else
            {
                if(l.nV < _EPSILON_INT64)
                {
                    return newDouble(l.dV - r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV - r.dV,r.nV);
                }
            }
        }
        else
        {
            if(0 < r.nV)
            {
                if(SoleTools::_EPSILON_INT64 < r.nV)
                {
                    return newDouble(l.dV - r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV - r.dV,r.nV);
                }
            }
            else
            {
                return newDouble(l.dV - r.dV,l.nV);
            }
        }
    }

    sole::Data SoleTools::mulDouble(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_DOUBLE_ != l.type)
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_mulDouble_1<<endl;
            #endif
            throw DataException(_TYPE_mulDouble_1);
        }

        if(_TYPE_DOUBLE_ != r.type)
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_mulDouble_2<<endl;
            #endif
            throw DataException(_TYPE_mulDouble_2);
        }

        if(0 < l.nV)
        {
            if(0 < r.nV)
            {
                if(l.nV < r.nV)
                {
                    return newDouble(l.dV * r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV * r.dV,r.nV);
                }
            }
            else
            {
                if(l.nV < _EPSILON_INT64)
                {
                    return newDouble(l.dV * r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV * r.dV,r.nV);
                }
            }
        }
        else
        {
            if(0 < r.nV)
            {
                if(SoleTools::_EPSILON_INT64 < r.nV)
                {
                    return newDouble(l.dV * r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV * r.dV,r.nV);
                }
            }
            else
            {
                return newDouble(l.dV * r.dV,l.nV);
            }
        }
    }

    sole::Data SoleTools::divDouble(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_DOUBLE_ != l.type)
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_addDouble_1<<endl;
            #endif
            throw DataException(_TYPE_addDouble_1);
        }

        if(_TYPE_DOUBLE_ != r.type)
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_addDouble_2<<endl;
            #endif
            throw DataException(_TYPE_addDouble_2);
        }

        if(0 < l.nV)
        {
            if(0 < r.nV)
            {
                if(l.nV < r.nV)
                {
                    return newDouble(l.dV / r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV / r.dV,r.nV);
                }
            }
            else
            {
                if(l.nV < _EPSILON_INT64)
                {
                    return newDouble(l.dV / r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV / r.dV,r.nV);
                }
            }
        }
        else
        {
            if(0 < r.nV)
            {
                if(SoleTools::_EPSILON_INT64 < r.nV)
                {
                    return newDouble(l.dV / r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV / r.dV,r.nV);
                }
            }
            else
            {
                return newDouble(l.dV / r.dV,l.nV);
            }
        }
    }

    sole::Data SoleTools::addDouble(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_DOUBLE_ != l.type)
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_addDouble_1<<endl;
            #endif
            throw DataException(_TYPE_addDouble_1);
        }

        if(_TYPE_DOUBLE_ != r.type)
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_addDouble_2<<endl;
            #endif
            throw DataException(_TYPE_addDouble_2);
        }

        if(0 < l.nV)
        {
            if(0 < r.nV)
            {
                if(l.nV < r.nV)
                {
                    return newDouble(l.dV + r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV + r.dV,r.nV);
                }
            }
            else
            {
                if(l.nV < _EPSILON_INT64)
                {
                    return newDouble(l.dV + r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV + r.dV,r.nV);
                }
            }
        }
        else
        {
            if(0 < r.nV)
            {
                if(SoleTools::_EPSILON_INT64 < r.nV)
                {
                    return newDouble(l.dV + r.dV,l.nV);
                }
                else
                {
                    return newDouble(l.dV + r.dV,r.nV);
                }
            }
            else
            {
                return newDouble(l.dV + r.dV,l.nV);
            }
        }
    }

    sole::Data SoleTools::addData(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type 
            || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type 
            )
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type 
            || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_STRING_ == l.type)
                {
                    if(_TYPE_STRING_ == r.type)
                    {
                        return newString(l.sV + r.sV);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_addData_3<<endl;
                        #endif
                        throw DataException(_TYPE_addData_3);
                    }
                }
                else if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        return newLong(l.nV + r.nV);
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        return newDouble(l.nV + r.dV,r.nV);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_addData_4<<endl;
                        #endif
                        throw DataException(_TYPE_addData_4);
                    }
                }
                else if(_TYPE_DOUBLE_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        return newDouble(l.dV + r.nV,l.nV);
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        return addDouble(l,r);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_addData_5<<endl;
                        #endif
                        throw DataException(_TYPE_addData_5);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_addData_2<<endl;
                #endif

                throw DataException(_TYPE_addData_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_addData_1<<endl;
            #endif

            throw DataException(_TYPE_addData_1);
        }

        throw DataException("");
    }

    sole::Data SoleTools::subData(sole::Data & l,sole::Data & r)
    {
        if( _TYPE_LONG_ == l.type 
            || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type 
            )
        {
            if( _TYPE_LONG_ == r.type 
            || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        return newLong(l.nV - r.nV);
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        return newDouble(l.nV - r.dV,r.nV);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_subData_4<<endl;
                        #endif
                        throw DataException(_TYPE_subData_4);
                    }
                }
                else if(_TYPE_DOUBLE_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        return newDouble(l.dV - r.nV,l.nV);
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        return subDouble(l,r);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_subData_5<<endl;
                        #endif
                        throw DataException(_TYPE_subData_5);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_subData_2<<endl;
                #endif

                throw DataException(_TYPE_subData_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_subData_1<<endl;
            #endif

            throw DataException(_TYPE_subData_1);
        }

        throw DataException("");
    }

    sole::Data SoleTools::mulData(sole::Data & l,sole::Data & r)
    {
        if( _TYPE_LONG_ == l.type 
            || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type 
            )
        {
            if( _TYPE_LONG_ == r.type 
            || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        return newLong(l.nV * r.nV);
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        return newDouble(l.nV * r.dV,r.nV);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_mulData_4<<endl;
                        #endif
                        throw DataException(_TYPE_mulData_4);
                    }
                }
                else if(_TYPE_DOUBLE_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        return newDouble(l.dV * r.nV,l.nV);
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        return mulDouble(l,r);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_mulData_5<<endl;
                        #endif
                        throw DataException(_TYPE_mulData_5);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_mulData_2<<endl;
                #endif

                throw DataException(_TYPE_mulData_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_mulData_1<<endl;
            #endif

            throw DataException(_TYPE_mulData_1);
        }

        throw DataException("");
    }

    sole::Data SoleTools::divData(sole::Data & l,sole::Data & r)
    {
        if( _TYPE_LONG_ == l.type 
            || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type 
            )
        {
            if( _TYPE_LONG_ == r.type 
            || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(equalZero(r))
                        {
                            #ifdef _TEST_flag_
                                cerr<<"DataException:"<<_TYPE_divData_3<<endl;
                            #endif
                            throw DataException(_TYPE_divData_3);
                        }

                        return newLong(l.nV / r.nV);
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        if(equalZero(r))
                        {
                            #ifdef _TEST_flag_
                                cerr<<"DataException:"<<_TYPE_divData_3<<endl;
                            #endif
                            throw DataException(_TYPE_divData_3);
                        }
                        return newDouble(l.nV / r.dV,r.nV);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_divData_4<<endl;
                        #endif
                        throw DataException(_TYPE_divData_4);
                    }
                }
                else if(_TYPE_DOUBLE_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(equalZero(r))
                        {
                            #ifdef _TEST_flag_
                                cerr<<"DataException:"<<_TYPE_divData_3<<endl;
                            #endif
                            throw DataException(_TYPE_divData_3);
                        }
                        return newDouble(l.dV / r.nV,l.nV);
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        if(equalZero(r))
                        {
                            #ifdef _TEST_flag_
                                cerr<<"DataException:"<<_TYPE_divData_3<<endl;
                            #endif
                            throw DataException(_TYPE_divData_3);
                        }
                        return divDouble(l,r);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_divData_5<<endl;
                        #endif
                        throw DataException(_TYPE_divData_5);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_divData_2<<endl;
                #endif

                throw DataException(_TYPE_divData_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_divData_1<<endl;
            #endif

            throw DataException(_TYPE_divData_1);
        }

        throw DataException("");
    }

    sole::Data SoleTools::surData(sole::Data & l,sole::Data & r)
    {
        if( _TYPE_LONG_ == l.type 
            || _TYPE_BOOL_ == l.type 
            )
        {
            if( _TYPE_LONG_ == r.type 
                || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        return newLong(l.nV % r.nV);
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_surData_4<<endl;
                        #endif
                        throw DataException(_TYPE_surData_4);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_surData_2<<endl;
                #endif

                throw DataException(_TYPE_surData_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_surData_1<<endl;
            #endif

            throw DataException(_TYPE_surData_1);
        }

        throw DataException("");
    }

    bool SoleTools::dataEqual(sole::Data & l,sole::Data & r)
    {
        if(l.type == r.type && l.v == r.v && l.m == r.m && l.sV == r.sV)
        {
            if(l.v.size() == r.v.size())
            {
                if(l.v == r.v)
                {
                    for(size_t i=0;i < l.v.size();i++)
                    {
                        if(l.v[i].type != r.v[i].type)
                        {
                            return false;
                        }

                        if(false == dataEqual(l.v[i],r.v[i]))
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }

            if(l.m.size() == r.m.size())
            {
                if(l.m == r.m)
                {
                    
                    for(map<std::string, sole::Data>::iterator it = l.m.begin();it !=l.m.end();it++)
                    {
                        if(l.m[it->first].type != r.m[it->first].type)
                        {
                            return false;
                        }

                        if(false == dataEqual(l.m[it->first],r.m[it->first]))
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }

            if(_TYPE_DOUBLE_ == l.type)
            {
                if(0 < l.nV)
                {
                    if(0 < r.nV)
                    {
                        if(l.nV < r.nV)
                        {
                            if(false == tars::TC_Common::equal(l.dV,r.dV,1/l.nV))
                            {
                                return false;
                            }
                        }
                        else
                        {
                            if(false == tars::TC_Common::equal(l.dV,r.dV,1/r.nV))
                            {
                                return false;
                            }
                        }
                    }
                    else
                    {
                        if(l.nV < _EPSILON_INT64)
                        {
                            if(false == tars::TC_Common::equal(l.dV,r.dV,1/l.nV))
                            {
                                return false;
                            }
                        }
                        else
                        {
                            if(false == tars::TC_Common::equal(l.dV,r.dV,1/_EPSILON_INT64))
                            {
                                return false;
                            }
                        }
                    }
                }
                else
                {
                    if(0 < r.nV)
                    {
                        if(_EPSILON_INT64 < r.nV)
                        {
                            if(false == tars::TC_Common::equal(l.dV,r.dV,1/_EPSILON_INT64))
                            {
                                return false;
                            }
                        }
                        else
                        {
                            if(false == tars::TC_Common::equal(l.dV,r.dV,1/r.nV))
                            {
                                return false;
                            }
                        }
                    }
                    else
                    {
                        if(false == tars::TC_Common::equal(l.dV,r.dV,1/_EPSILON_INT64))
                        {
                            return false;
                        }
                    }
                }
            }
            else if(_TYPE_LONG_ == l.type)
            {
                if(l.nV != r.nV)
                {
                    return false;
                }
            }
            else if(_TYPE_BOOL_ == l.type)
            {
                if(l.nV != r.nV)
                {
                    return false;
                }
            }
        }
        else if(l.type != r.type)
        {
            if(_TYPE_DOUBLE_ == l.type)
            {
                if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                {
                    if(l.dV != r.nV)
                    {
                        long ll = l.dV * (l.nV?l.nV:_EPSILON_INT64);
                        long lr = r.nV * (l.nV?l.nV:_EPSILON_INT64);
                        if(ll != lr)
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
            }
            else if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
            {
                if(_TYPE_DOUBLE_ == r.type)
                {
                    if(l.nV != r.dV)
                    {
                        long ll = l.nV * (r.nV?r.nV:_EPSILON_INT64);
                        long lr = r.nV * (r.nV?r.nV:_EPSILON_INT64);
                        if(ll != lr)
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        return true;
    }

    bool SoleTools::dataGreater(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type 
            || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type 
            )
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type 
            || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_STRING_ == l.type)
                {
                    if(_TYPE_STRING_ == r.type)
                    {
                        if(l.sV > r.sV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataGreater_3<<endl;
                        #endif
                        throw DataException(_TYPE_dataGreater_3);
                    }
                }
                else if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(l.nV > r.nV)
                        {
                            return true;
                        }
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        if(l.nV > r.dV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataGreater_4<<endl;
                        #endif
                        throw DataException(_TYPE_dataGreater_4);
                    }
                }
                else if(_TYPE_DOUBLE_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(l.dV > r.nV)
                        {
                            double dr = r.nV;
                            double epsilon = l.nV?1/l.nV:1/_EPSILON_INT64;
                            if(false == tars::TC_Common::equal(l.dV,dr,epsilon))
                            {
                                return true;
                            }
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataGreater_5<<endl;
                        #endif
                        throw DataException(_TYPE_dataGreater_5);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_dataGreater_2<<endl;
                #endif

                throw DataException(_TYPE_dataGreater_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_dataGreater_1<<endl;
            #endif

            throw DataException(_TYPE_dataGreater_1);
        }

        return false;
    }

    bool SoleTools::dataLess(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type 
            || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type 
            )
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type 
            || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_STRING_ == l.type)
                {
                    if(_TYPE_STRING_ == r.type)
                    {
                        if(l.sV < r.sV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataLess_3<<endl;
                        #endif
                        throw DataException(_TYPE_dataLess_3);
                    }
                }
                else if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(l.nV < r.nV)
                        {
                            return true;
                        }
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        if(l.nV < r.dV)
                        {
                            double dl = l.nV;
                            double epsilon = r.nV?1/r.nV:1/_EPSILON_INT64;
                            if(false == tars::TC_Common::equal(r.dV,dl,epsilon))
                            {
                                return true;
                            }
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataLess_4<<endl;
                        #endif
                        throw DataException(_TYPE_dataLess_4);
                    }
                }
                else if(_TYPE_DOUBLE_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(l.dV < r.nV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataLess_5<<endl;
                        #endif
                        throw DataException(_TYPE_dataLess_5);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_dataLess_2<<endl;
                #endif

                throw DataException(_TYPE_dataLess_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_dataLess_1<<endl;
            #endif

            throw DataException(_TYPE_dataLess_1);
        }

        return false;
    }

    bool SoleTools::dataEGreater(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type 
            || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type 
            )
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type 
            || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_STRING_ == l.type)
                {
                    if(_TYPE_STRING_ == r.type)
                    {
                        if(l.sV >= r.sV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataEGreater_3<<endl;
                        #endif
                        throw DataException(_TYPE_dataEGreater_3);
                    }
                }
                else if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(l.nV >= r.nV)
                        {
                            return true;
                        }
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        if(l.nV >= r.dV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataEGreater_4<<endl;
                        #endif
                        throw DataException(_TYPE_dataEGreater_4);
                    }
                }
                else if(_TYPE_DOUBLE_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(l.dV >= r.nV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataEGreater_5<<endl;
                        #endif
                        throw DataException(_TYPE_dataEGreater_5);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_dataEGreater_2<<endl;
                #endif

                throw DataException(_TYPE_dataEGreater_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_dataEGreater_1<<endl;
            #endif

            throw DataException(_TYPE_dataEGreater_1);
        }

        return false;
    }

    bool SoleTools::dataELess(sole::Data & l,sole::Data & r)
    {
        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type 
            || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type 
            )
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type 
            || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type 
            )
            {
                if(_TYPE_STRING_ == l.type)
                {
                    if(_TYPE_STRING_ == r.type)
                    {
                        if(l.sV <= r.sV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataELess_3<<endl;
                        #endif
                        throw DataException(_TYPE_dataELess_3);
                    }
                }
                else if(_TYPE_LONG_ == l.type || _TYPE_BOOL_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(l.nV <= r.nV)
                        {
                            return true;
                        }
                    }
                    else if(_TYPE_DOUBLE_ == r.type)
                    {
                        if(l.nV <= r.dV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataELess_4<<endl;
                        #endif
                        throw DataException(_TYPE_dataELess_4);
                    }
                }
                else if(_TYPE_DOUBLE_ == l.type)
                {
                    if(_TYPE_LONG_ == r.type || _TYPE_BOOL_ == r.type)
                    {
                        if(l.dV <= r.nV)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        #ifdef _TEST_flag_
                            cerr<<"DataException:"<<_TYPE_dataELess_5<<endl;
                        #endif
                        throw DataException(_TYPE_dataELess_5);
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_TYPE_dataELess_2<<endl;
                #endif

                throw DataException(_TYPE_dataELess_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_TYPE_dataELess_1<<endl;
            #endif

            throw DataException(_TYPE_dataELess_1);
        }

        return false;
    }

    sole::Data& SoleTools::getElement4Assign(sole::Data & v,sole::Data & vn,size_t i,string& varName,string& traceVar)
    {
        if(_TYPE_LONG_ == vn.v[i].type)
        {
            size_t index = (size_t)vn.v[i].nV;
            traceVar += "[" + tars::TC_Common::tostr(index) + "]";

            if(index > v.v.size())
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_ERROR_getElement_1((varName),(traceVar))<<endl;
                #endif
                throw DataException(_ERROR_getElement_1((varName),(traceVar)));
            }

            if(index == v.v.size())
            {
                if(0 == index)
                {
                    if(_TYPE_VAR_ != v.type)
                    {
                        if(_TYPE_ARR_ != v.type)
                        {
                            v.type = _TYPE_ARR_;
                        }
                    }
                }

                v.v.push_back(sole::Data());
            }

            if(i == vn.v.size() - 1)
            {
                return v.v[ index ];
            }
            else
            {
                return getElement4Assign(v.v[ vn.v[i].nV ],vn,i+1,varName,traceVar);
            }
            
        }
        else
        {
            string element = vn.v[i].sV;
            traceVar += "." + element;

            if(v.m.find(element) == v.m.end())
            {
                if(_TYPE_VAR_ != v.type)
                {
                    if(_TYPE_OBJ_ != v.type)
                    {
                        v.type = _TYPE_OBJ_;
                    }
                }
                v.m[ element ] = sole::Data();
            }

            if(i == vn.v.size() - 1)
            {
                return v.m[ vn.v[i].sV ];
            }
            else
            {
                return getElement4Assign(v.m[ vn.v[i].sV ],vn,i+1,varName,traceVar);
            }
        }
    }

    sole::Data& SoleTools::getVar4Assign(sole::Data & v,sole::Data & vn)
    {
        size_t len=v.v.size();

        string varName = vn.sV;
        
        for(size_t i=0;i < vn.v.size();i++)
        {
            if(_TYPE_STRING_ == vn.v[i].type)
            {
                varName += ".";
                varName += vn.v[i].sV;
            }
            else if(_TYPE_LONG_ == vn.v[i].type)
            {
                varName += "[";
                varName += tars::TC_Common::tostr(vn.v[i].nV);
                varName += "]";
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_ERROR_getVar4Assign_1((varName),(vn.v[i].writeToJsonString()))<<endl;
                #endif

                throw DataException(_ERROR_getVar4Assign_1((varName),(vn.v[i].writeToJsonString())));
            }
        }

        #ifdef _TEST_flag_
            //cerr<<"varName:"<<varName<<endl;
        #endif

        string traceVar = vn.sV;
        for(size_t i=0;i < v.v.size();i++)
        {
            map<string, sole::Data>::iterator iter;
            iter = v.v[len-i-1].m.find(vn.sV);

            if(iter != v.v[len-i-1].m.end())
            {
                if(0 == vn.v.size())
                {
                    return iter->second;
                }
                else
                {
                    return getElement4Assign(iter->second,vn,0,varName,traceVar);
                }
            }
        }

        #ifdef _TEST_flag_
            cerr<<"DataException:"<<_ERROR_getVar4Assign_2((varName))<<endl;
        #endif
        throw DataException(_ERROR_getVar4Assign_2((varName)));
    }

    sole::Data& SoleTools::getVar(sole::Data & v,sole::Data & vn)
    {
        size_t len=v.v.size();

        string varName = vn.sV;

        //
        
        for(size_t i=0;i < vn.v.size();i++)
        {
            if(_TYPE_STRING_ == vn.v[i].type)
            {
                varName += ".";
                varName += vn.v[i].sV;
            }
            else if(_TYPE_LONG_ == vn.v[i].type)
            {
                varName += "[";
                varName += tars::TC_Common::tostr(vn.v[i].nV);
                varName += "]";
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_ERROR_getVar_1((varName),(vn.v[i].writeToJsonString()))<<endl;
                #endif

                throw DataException(_ERROR_getVar_1((varName),(vn.v[i].writeToJsonString())));
            }
        }

        #ifdef _TEST_flag_
           // cout<<"varName:"<<varName<<endl;
        #endif

        string traceVar = vn.sV;
        for(size_t i=0;i < v.v.size();i++)
        {
            map<string, sole::Data>::iterator iter;
            iter = v.v[len-i-1].m.find(vn.sV);

            if(iter != v.v[len-i-1].m.end())
            {
                if(0 == vn.v.size())
                {
                    return iter->second;
                }
                else
                {
                    return getElement(iter->second,vn,0,varName,traceVar);
                }
            }
        }

        #ifdef _TEST_flag_
            cerr<<"DataException:"<<_ERROR_getVar_2((varName))<<endl;
        #endif
        throw DataException(_ERROR_getVar_2((varName)));
    }

    sole::Data& SoleTools::getElement(sole::Data & v,sole::Data & vn,size_t i,string& varName,string& traceVar)
    {
        if(_TYPE_LONG_ == vn.v[i].type)
        {
            size_t index = (size_t)vn.v[i].nV;
            traceVar += "[" + tars::TC_Common::tostr(index) + "]";

            if(index >= v.v.size())
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_ERROR_getElement_1((varName),(traceVar))<<endl;
                #endif
                throw DataException(_ERROR_getElement_1((varName),(traceVar)));
            }

            if(i == vn.v.size() - 1)
            {
                return v.v[ index ];
            }
            else
            {
                return getElement(v.v[ vn.v[i].nV ],vn,i+1,varName,traceVar);
            }
            
        }
        else
        {
            string element = vn.v[i].sV;
            traceVar += "." + element;
            if(v.m.find(element) == v.m.end())
            {
                #ifdef _TEST_flag_
                    cerr<<"DataException:"<<_ERROR_getElement_2((varName),(traceVar))<<endl;
                #endif
                throw DataException(_ERROR_getElement_2((varName),(traceVar)));
            }

            if(i == vn.v.size() - 1)
            {
                return v.m[ vn.v[i].sV ];
            }
            else
            {
                return getElement(v.m[ vn.v[i].sV ],vn,i+1,varName,traceVar);
            }
        }
    }

    void SoleTools::putVar(sole::Data & v,string& varName)
    {
        #ifdef _TEST_flag_
           // cerr<<"varName:"<<varName<<endl;
        #endif

        size_t index=v.v.size() - 1;
        if(index == 0)
        {
            v.v.push_back(SoleTools::newObject());
        }
        
        std::map<string, sole::Data>::iterator it = v.v[index].m.find(varName);

        if(it != v.v[index].m.end())
        {
            #ifdef _TEST_flag_
                cerr<<"DataException:"<<_ERROR_putVar_1((varName))<<endl;
            #endif
            throw DataException(_ERROR_putVar_1((varName)));
        }
        else
        {
            v.v[index].m[varName] = sole::Data();
        }
    }
};