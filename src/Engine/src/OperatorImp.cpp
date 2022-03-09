#include "OperatorImp.h"
#include "SoleException.h"
#include "SolePublic.h"
#include "Actuator.h"

namespace sole{
    void doAdd(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAdd_3<<endl;
            #endif
            throw OperatorException(_ERROR_doAdd_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAdd_4<<endl;
            #endif
            throw OperatorException(_ERROR_doAdd_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_VAR_ == l.type
        || _TYPE_STRING_ == l.type)
        {
            if(_TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                || _TYPE_BOOL_ == r.type || _TYPE_VAR_ == r.type
                || _TYPE_STRING_ == r.type)
            {
                try
                {
                    if(_TYPE_VAR_ == l.type)
                    {
                        l = Actuator::getVar(v,l);
                        doAdd(v,t,i); 
                    }
                    else
                    {
                        if(_TYPE_VAR_ == r.type)
                        {
                            r = Actuator::getVar(v,r);
                            doAdd(v,t,i); 
                        }
                        else
                        {
                            t.v.push_back(SoleTools::addData(l,r));
                        }
                    }
                }
                catch(const DataException &e)
                {
                    #ifdef _TEST_flag_
                        cerr<<"OperatorException:"<<e.what()<<endl;
                    #endif
                    throw OperatorException(e.what());
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doAdd_2<<endl;
                #endif

                throw OperatorException(_ERROR_doAdd_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAdd_1<<endl;
            #endif

            throw OperatorException(_ERROR_doAdd_1);
        }
    }

    void doSub(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doSub_3<<endl;
            #endif
            throw OperatorException(_ERROR_doSub_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doSub_4<<endl;
            #endif
            throw OperatorException(_ERROR_doSub_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_VAR_ == l.type)
        {
            if( _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                || _TYPE_BOOL_ == r.type || _TYPE_VAR_ == r.type)
            {
                try
                {
                    if(_TYPE_VAR_ == l.type)
                    {
                        l = Actuator::getVar(v,l);
                        doSub(v,t,i); 
                    }
                    else
                    {
                        if(_TYPE_VAR_ == r.type)
                        {
                            r = Actuator::getVar(v,r);
                            doSub(v,t,i); 
                        }
                        else
                        {
                            t.v.push_back(SoleTools::subData(l,r));
                        }
                    }
                }
                catch(const DataException &e)
                {
                    #ifdef _TEST_flag_
                        cerr<<"OperatorException:"<<e.what()<<endl;
                    #endif
                    
                    throw OperatorException(e.what());
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doSub_2<<endl;
                #endif

                throw OperatorException(_ERROR_doSub_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doSub_1<<endl;
            #endif

            throw OperatorException(_ERROR_doSub_1);
        }
    }

    void doMul(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doMul_3<<endl;
            #endif
            throw OperatorException(_ERROR_doMul_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doMul_4<<endl;
            #endif
            throw OperatorException(_ERROR_doMul_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                || _TYPE_BOOL_ == r.type || _TYPE_VAR_ == r.type)
            {
                try
                {
                    if(_TYPE_VAR_ == l.type)
                    {
                        l = Actuator::getVar(v,l);
                        doMul(v,t,i); 
                    }
                    else
                    {
                        if(_TYPE_VAR_ == r.type)
                        {
                            r = Actuator::getVar(v,r);
                            doMul(v,t,i); 
                        }
                        else
                        {
                            t.v.push_back(SoleTools::mulData(l,r));
                        }
                    }
                }
                catch(const DataException &e)
                {
                    #ifdef _TEST_flag_
                        cerr<<"OperatorException:"<<e.what()<<endl;
                    #endif
                    
                    throw OperatorException(e.what());
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doMul_2<<endl;
                #endif

                throw OperatorException(_ERROR_doMul_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doMul_1<<endl;
            #endif

            throw OperatorException(_ERROR_doMul_1);
        }
    }

    void doDiv(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doDiv_3<<endl;
            #endif
            throw OperatorException(_ERROR_doDiv_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doDiv_4<<endl;
            #endif
            throw OperatorException(_ERROR_doDiv_4);
        }
        
        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                || _TYPE_BOOL_ == r.type || _TYPE_VAR_ == r.type)
            {
                try
                {
                    if(_TYPE_VAR_ == l.type)
                    {
                        l = Actuator::getVar(v,l);
                        doDiv(v,t,i); 
                    }
                    else
                    {
                        if(_TYPE_VAR_ == r.type)
                        {
                            r = Actuator::getVar(v,r);
                            doDiv(v,t,i); 
                        }
                        else
                        {
                            t.v.push_back(SoleTools::divData(l,r));
                        }
                    }
                }
                catch(const DataException &e)
                {
                    #ifdef _TEST_flag_
                        cerr<<"OperatorException:"<<e.what()<<endl;
                    #endif
                    
                    throw OperatorException(e.what());
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doDiv_2<<endl;
                #endif

                throw OperatorException(_ERROR_doDiv_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doDiv_1<<endl;
            #endif

            throw OperatorException(_ERROR_doDiv_1);
        }
    }

    void doSur(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doSur_3<<endl;
            #endif
            throw OperatorException(_ERROR_doSur_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doSur_4<<endl;
            #endif
            throw OperatorException(_ERROR_doSur_4);
        }
        
        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                || _TYPE_BOOL_ == r.type || _TYPE_VAR_ == r.type)
            {
                try
                {
                    if(_TYPE_VAR_ == l.type)
                    {
                        l = Actuator::getVar(v,l);
                        doSur(v,t,i); 
                    }
                    else
                    {
                        if(_TYPE_VAR_ == r.type)
                        {
                            r = Actuator::getVar(v,r);
                            doSur(v,t,i); 
                        }
                        else
                        {
                            t.v.push_back(SoleTools::surData(l,r));
                        }
                    }
                }
                catch(const DataException &e)
                {
                    #ifdef _TEST_flag_
                        cerr<<"OperatorException:"<<e.what()<<endl;
                    #endif
                    
                    throw OperatorException(e.what());
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doSur_2<<endl;
                #endif

                throw OperatorException(_ERROR_doSur_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doSur_1<<endl;
            #endif

            throw OperatorException(_ERROR_doSur_1);
        }
    }

    void doAssign(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAssign_3<<endl;
            #endif
            throw OperatorException(_ERROR_doAssign_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAssign_4<<endl;
            #endif
            throw OperatorException(_ERROR_doAssign_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_VAR_ != l.type)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAssign_1<<endl;
            #endif

            throw OperatorException(_ERROR_doAssign_1);
        }
        
        if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                || _TYPE_BOOL_ == r.type || _TYPE_OBJ_ == r.type || _TYPE_ARR_ == r.type)
        {
            Actuator::getVar4Assign(v,l) = r;
            t.v.push_back(sole::SoleTools::newData(Actuator::getVar(v,l)));
        }
        else if(_TYPE_VAR_ == r.type)
        {
            Actuator::getVar4Assign(v,l) = Actuator::getVar(v,r);
            t.v.push_back(sole::SoleTools::newData(Actuator::getVar(v,l)));
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAssign_2<<endl;
            #endif
            throw OperatorException(_ERROR_doAssign_2);
        }
    }

    void doEqual(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doEqual_3<<endl;
            #endif
            throw OperatorException(_ERROR_doEqual_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doEqual_4<<endl;
            #endif
            throw OperatorException(_ERROR_doEqual_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_OBJ_ == l.type || _TYPE_ARR_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                    || _TYPE_BOOL_ == r.type || _TYPE_OBJ_ == r.type || _TYPE_ARR_ == r.type || _TYPE_VAR_ == r.type)
            {
                if("Var" == l.type)
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataEqual(Actuator::getVar(v,l),Actuator::getVar(v,r)))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataEqual(Actuator::getVar(v,l),r))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                }
                else
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataEqual(l,Actuator::getVar(v,r)))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataEqual(l,r))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doEqual_2<<endl;
                #endif

                throw OperatorException(_ERROR_doEqual_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doEqual_1<<endl;
            #endif

            throw OperatorException(_ERROR_doEqual_1);
        }
    }

    void doGreater(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doGreater_3<<endl;
            #endif
            throw OperatorException(_ERROR_doGreater_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doGreater_4<<endl;
            #endif
            throw OperatorException(_ERROR_doGreater_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_OBJ_ == l.type || _TYPE_ARR_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                    || _TYPE_BOOL_ == r.type || _TYPE_OBJ_ == r.type || _TYPE_ARR_ == r.type || _TYPE_VAR_ == r.type)
            {
                if("Var" == l.type)
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataGreater(Actuator::getVar(v,l),Actuator::getVar(v,r)))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataGreater(Actuator::getVar(v,l),r))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                }
                else
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataGreater(l,Actuator::getVar(v,r)))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataGreater(l,r))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doGreater_2<<endl;
                #endif

                throw OperatorException(_ERROR_doGreater_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doGreater_1<<endl;
            #endif

            throw OperatorException(_ERROR_doGreater_1);
        }
    }

    void doLess(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doLess_3<<endl;
            #endif
            throw OperatorException(_ERROR_doLess_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doLess_4<<endl;
            #endif
            throw OperatorException(_ERROR_doLess_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_OBJ_ == l.type || _TYPE_ARR_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                    || _TYPE_BOOL_ == r.type || _TYPE_OBJ_ == r.type || _TYPE_ARR_ == r.type || _TYPE_VAR_ == r.type)
            {
                if("Var" == l.type)
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataLess(Actuator::getVar(v,l),Actuator::getVar(v,r)))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataLess(Actuator::getVar(v,l),r))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                }
                else
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataLess(l,Actuator::getVar(v,r)))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataLess(l,r))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doLess_2<<endl;
                #endif

                throw OperatorException(_ERROR_doLess_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doLess_1<<endl;
            #endif

            throw OperatorException(_ERROR_doLess_1);
        }
    }

    void doNEqual(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doNEqual_3<<endl;
            #endif
            throw OperatorException(_ERROR_doNEqual_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doNEqual_4<<endl;
            #endif
            throw OperatorException(_ERROR_doNEqual_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_OBJ_ == l.type || _TYPE_ARR_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                    || _TYPE_BOOL_ == r.type || _TYPE_OBJ_ == r.type || _TYPE_ARR_ == r.type || _TYPE_VAR_ == r.type)
            {
                if("Var" == l.type)
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataEqual(Actuator::getVar(v,l),Actuator::getVar(v,r)))
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataEqual(Actuator::getVar(v,l),r))
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                    }
                }
                else
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataEqual(l,Actuator::getVar(v,r)))
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataEqual(l,r))
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doNEqual_2<<endl;
                #endif

                throw OperatorException(_ERROR_doNEqual_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doNEqual_1<<endl;
            #endif

            throw OperatorException(_ERROR_doNEqual_1);
        }
    }

    void doEGreater(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doEGreater_3<<endl;
            #endif
            throw OperatorException(_ERROR_doEGreater_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doEGreater_4<<endl;
            #endif
            throw OperatorException(_ERROR_doEGreater_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_OBJ_ == l.type || _TYPE_ARR_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                    || _TYPE_BOOL_ == r.type || _TYPE_OBJ_ == r.type || _TYPE_ARR_ == r.type || _TYPE_VAR_ == r.type)
            {
                if("Var" == l.type)
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataEGreater(Actuator::getVar(v,l),Actuator::getVar(v,r)))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataEGreater(Actuator::getVar(v,l),r))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                }
                else
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataEGreater(l,Actuator::getVar(v,r)))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataEGreater(l,r))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doEGreater_2<<endl;
                #endif

                throw OperatorException(_ERROR_doEGreater_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doEGreater_1<<endl;
            #endif

            throw OperatorException(_ERROR_doEGreater_1);
        }
    }

    void doELess(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doELess_3<<endl;
            #endif
            throw OperatorException(_ERROR_doELess_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doELess_4<<endl;
            #endif
            throw OperatorException(_ERROR_doELess_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_OBJ_ == l.type || _TYPE_ARR_ == l.type || _TYPE_VAR_ == l.type)
        {
            if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                    || _TYPE_BOOL_ == r.type || _TYPE_OBJ_ == r.type || _TYPE_ARR_ == r.type || _TYPE_VAR_ == r.type)
            {
                if("Var" == l.type)
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataELess(Actuator::getVar(v,l),Actuator::getVar(v,r)))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataELess(Actuator::getVar(v,l),r))
                        {
                            t.v.push_back(SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(SoleTools::newBool(false));
                        }
                    }
                }
                else
                {
                    if("Var" == r.type)
                    {
                        if(SoleTools::dataELess(l,Actuator::getVar(v,r)))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                    else
                    {
                        if(SoleTools::dataELess(l,r))
                        {
                            t.v.push_back(sole::SoleTools::newBool(true));
                        }
                        else
                        {
                            t.v.push_back(sole::SoleTools::newBool(false));
                        }
                    }
                }
            }
            else
            {
                #ifdef _TEST_flag_
                    cerr<<"OperatorException:"<<_ERROR_doELess_2<<endl;
                #endif

                throw OperatorException(_ERROR_doELess_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doELess_1<<endl;
            #endif

            throw OperatorException(_ERROR_doELess_1);
        }
    }

    void doComma(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doComma_3<<endl;
            #endif
            throw OperatorException(_ERROR_doComma_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doComma_4<<endl;
            #endif
            throw OperatorException(_ERROR_doComma_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];

        if(_TYPE_STRING_ == l.type || _TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type 
                || _TYPE_BOOL_ == l.type || _TYPE_OBJ_ == l.type || _TYPE_ARR_ == l.type 
                || _TYPE_VAR_ == l.type)
        {
            ;
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doComma_1<<endl;
            #endif

            throw OperatorException(_ERROR_doComma_1);
        }
        
        if(_TYPE_STRING_ == r.type || _TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type 
                || _TYPE_BOOL_ == r.type || _TYPE_OBJ_ == r.type || _TYPE_ARR_ == r.type)
        {
            t.v.push_back(sole::SoleTools::newData(r));
        }
        else if(_TYPE_VAR_ == r.type)
        {
            t.v.push_back(sole::SoleTools::newData(Actuator::getVar(v,r)));
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doComma_2<<endl;
            #endif
            throw OperatorException(_ERROR_doComma_2);
        }
    }

    void doAnd(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAnd_3<<endl;
            #endif
            throw OperatorException(_ERROR_doAnd_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAnd_4<<endl;
            #endif
            throw OperatorException(_ERROR_doAnd_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];
        bool lFlag = true;
        bool rFlag = true;

        if(_TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type)
        {
            if("Bool" == l.type)
            {
                if(0 == l.nV)
                {
                    lFlag = false;
                }
            }
            else if("Long" == l.type)
            {
                if(0 == l.nV)
                {
                    lFlag = false;
                }
            }
            else if("Double" == l.type)
            {
                if(sole::SoleTools::equalZero(l))
                {
                    lFlag = false;
                }
            }
        }
        else if(_TYPE_VAR_ == l.type)
        {
            sole::Data tmp = Actuator::getVar(v,l);
            if("Bool" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    lFlag = false;
                }
            }
            else if("Long" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    lFlag = false;
                }
            }
            else if("Double" == tmp.type)
            {
                if(sole::SoleTools::equalZero(tmp))
                {
                    lFlag = false;
                }
            }
            else
            {
                #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAnd_1<<endl;
                #endif

                throw OperatorException(_ERROR_doAnd_1);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAnd_1<<endl;
            #endif

            throw OperatorException(_ERROR_doAnd_1);
        }

        if(_TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type)
        {
            if("Bool" == r.type)
            {
                if(0 == r.nV)
                {
                    rFlag = false;
                }
            }
            else if("Long" == r.type)
            {
                if(0 == r.nV)
                {
                    rFlag = false;
                }
            }
            else if("Double" == r.type)
            {
                if(sole::SoleTools::equalZero(r))
                {
                    rFlag = false;
                }
            }
        }
        else if(_TYPE_VAR_ == r.type)
        {
            sole::Data tmp = Actuator::getVar(v,r);
            if("Bool" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    rFlag = false;
                }
            }
            else if("Long" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    rFlag = false;
                }
            }
            else if("Double" == tmp.type)
            {
                if(sole::SoleTools::equalZero(tmp))
                {
                    rFlag = false;
                }
            }
            else
            {
                #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAnd_2<<endl;
                #endif

                throw OperatorException(_ERROR_doAnd_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doAnd_2<<endl;
            #endif

            throw OperatorException(_ERROR_doAnd_2);
        }
        
        if(lFlag and rFlag)
        {
            t.v.push_back(sole::SoleTools::newBool(true));
        }
        else
        {
            t.v.push_back(sole::SoleTools::newBool(false));
        }
    }

    void doOr(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 1)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doOr_3<<endl;
            #endif
            throw OperatorException(_ERROR_doOr_3);
        }

        if(t.v.size() < 3)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doOr_4<<endl;
            #endif
            throw OperatorException(_ERROR_doOr_4);
        }

        sole::Data & r = t.v[2];
        sole::Data & l = t.v[0];
        bool lFlag = true;
        bool rFlag = true;

        if(_TYPE_LONG_ == l.type || _TYPE_DOUBLE_ == l.type || _TYPE_BOOL_ == l.type)
        {
            if("Bool" == l.type)
            {
                if(0 == l.nV)
                {
                    lFlag = false;
                }
            }
            else if("Long" == l.type)
            {
                if(0 == l.nV)
                {
                    lFlag = false;
                }
            }
            else if("Double" == l.type)
            {
                if(sole::SoleTools::equalZero(l))
                {
                    lFlag = false;
                }
            }
        }
        else if(_TYPE_VAR_ == l.type)
        {
            sole::Data tmp = Actuator::getVar(v,l);
            if("Bool" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    lFlag = false;
                }
            }
            else if("Long" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    lFlag = false;
                }
            }
            else if("Double" == tmp.type)
            {
                if(sole::SoleTools::equalZero(tmp))
                {
                    lFlag = false;
                }
            }
            else
            {
                #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doOr_1<<endl;
                #endif

                throw OperatorException(_ERROR_doOr_1);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doOr_1<<endl;
            #endif

            throw OperatorException(_ERROR_doOr_1);
        }

        if(_TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type)
        {
            if("Bool" == r.type)
            {
                if(0 == r.nV)
                {
                    rFlag = false;
                }
            }
            else if("Long" == r.type)
            {
                if(0 == r.nV)
                {
                    rFlag = false;
                }
            }
            else if("Double" == r.type)
            {
                if(sole::SoleTools::equalZero(r))
                {
                    rFlag = false;
                }
            }
        }
        else if(_TYPE_VAR_ == r.type)
        {
            sole::Data tmp = Actuator::getVar(v,r);
            if("Bool" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    rFlag = false;
                }
            }
            else if("Long" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    rFlag = false;
                }
            }
            else if("Double" == tmp.type)
            {
                if(sole::SoleTools::equalZero(tmp))
                {
                    rFlag = false;
                }
            }
            else
            {
                #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doOr_2<<endl;
                #endif

                throw OperatorException(_ERROR_doOr_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doOr_2<<endl;
            #endif

            throw OperatorException(_ERROR_doOr_2);
        }
        
        if(lFlag or rFlag)
        {
            t.v.push_back(sole::SoleTools::newBool(true));
        }
        else
        {
            t.v.push_back(sole::SoleTools::newBool(false));
        }
    }

    void doNon(sole::Data & v,sole::Data & t,size_t i)
    {
        if(i != 0)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doNon_3<<endl;
            #endif
            throw OperatorException(_ERROR_doNon_3);
        }

        if(t.v.size() < 2)
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doNon_4<<endl;
            #endif
            throw OperatorException(_ERROR_doNon_4);
        }

        sole::Data & r = t.v[1];
        bool rFlag = true;

        if(_TYPE_LONG_ == r.type || _TYPE_DOUBLE_ == r.type || _TYPE_BOOL_ == r.type)
        {
            if("Bool" == r.type)
            {
                if(0 == r.nV)
                {
                    rFlag = false;
                }
            }
            else if("Long" == r.type)
            {
                if(0 == r.nV)
                {
                    rFlag = false;
                }
            }
            else if("Double" == r.type)
            {
                if(sole::SoleTools::equalZero(r))
                {
                    rFlag = false;
                }
            }
        }
        else if(_TYPE_VAR_ == r.type)
        {
            sole::Data tmp = Actuator::getVar(v,r);
            if("Bool" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    rFlag = false;
                }
            }
            else if("Long" == tmp.type)
            {
                if(0 == tmp.nV)
                {
                    rFlag = false;
                }
            }
            else if("Double" == tmp.type)
            {
                if(sole::SoleTools::equalZero(tmp))
                {
                    rFlag = false;
                }
            }
            else
            {
                #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doNon_2<<endl;
                #endif

                throw OperatorException(_ERROR_doNon_2);
            }
        }
        else
        {
            #ifdef _TEST_flag_
                cerr<<"OperatorException:"<<_ERROR_doNon_2<<endl;
            #endif

            throw OperatorException(_ERROR_doNon_2);
        }
        
        if(!rFlag)
        {
            t.v.push_back(sole::SoleTools::newBool(true));
        }
        else
        {
            t.v.push_back(sole::SoleTools::newBool(false));
        }
    }
};