#ifndef _SolePublic_H_
#define _SolePublic_H_

#define _TYPE_STRING_ "String"
#define _TYPE_LONG_ "Long"
#define _TYPE_DOUBLE_ "Double"
#define _TYPE_BOOL_ "Bool"
#define _TYPE_VAR_ "Var"
#define _TYPE_OBJ_ "Obj"
#define _TYPE_ARR_ "Arr"
#define _TYPE_OPERATOR_ "Operator"
#define _TYPE_EXPRESSION_ "Expression"
#define _TYPE_STATEMENT_ "Statement"

#define _KEYWORD_IF_ "if"
#define _KEYWORD_VAR_ "var"

#define _TYPE_addData_1 "Invalid lvalue type"
#define _TYPE_addData_2 "Invalid rvalue type"
#define _TYPE_addData_3 "Invalid rvalue type,lvalue is String ,rvalue must be String type"
#define _TYPE_addData_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_addData_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_subData_1 "Invalid lvalue type"
#define _TYPE_subData_2 "Invalid rvalue type"
#define _TYPE_subData_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_subData_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_mulData_1 "Invalid lvalue type"
#define _TYPE_mulData_2 "Invalid rvalue type"
#define _TYPE_mulData_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_mulData_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_divData_1 "Invalid lvalue type"
#define _TYPE_divData_2 "Invalid rvalue type"
#define _TYPE_divData_3 "Divisor cannot be 0"
#define _TYPE_divData_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_divData_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_surData_1 "Invalid lvalue type"
#define _TYPE_surData_2 "Invalid rvalue type"
#define _TYPE_surData_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool type"

#define _TYPE_dataGreater_1 "Invalid lvalue type"
#define _TYPE_dataGreater_2 "Invalid rvalue type"
#define _TYPE_dataGreater_3 "Invalid rvalue type,lvalue is String ,rvalue must be String type"
#define _TYPE_dataGreater_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_dataGreater_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_dataLess_1 "Invalid lvalue type"
#define _TYPE_dataLess_2 "Invalid rvalue type"
#define _TYPE_dataLess_3 "Invalid rvalue type,lvalue is String ,rvalue must be String type"
#define _TYPE_dataLess_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_dataLess_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_dataEGreater_1 "Invalid lvalue type"
#define _TYPE_dataEGreater_2 "Invalid rvalue type"
#define _TYPE_dataEGreater_3 "Invalid rvalue type,lvalue is String ,rvalue must be String type"
#define _TYPE_dataEGreater_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_dataEGreater_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_dataELess_1 "Invalid lvalue type"
#define _TYPE_dataELess_2 "Invalid rvalue type"
#define _TYPE_dataELess_3 "Invalid rvalue type,lvalue is String ,rvalue must be String type"
#define _TYPE_dataELess_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_dataELess_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_dataGreater_1 "Invalid lvalue type"
#define _TYPE_dataGreater_2 "Invalid rvalue type"
#define _TYPE_dataGreater_3 "Invalid rvalue type,lvalue is String ,rvalue must be String type"
#define _TYPE_dataGreater_4 "Invalid rvalue type,lvalue is Long、Bool ,rvalue must be Long、Bool、Double type"
#define _TYPE_dataGreater_5 "Invalid rvalue type,lvalue is Double ,rvalue must be Long、Bool、Double type"

#define _TYPE_addDouble_1 "Invalid lvalue type,lvalue must be Double type"
#define _TYPE_addDouble_2 "Invalid rvalue type,rvalue must be Double type"

#define _TYPE_subDouble_1 "Invalid lvalue type,lvalue must be Double type"
#define _TYPE_subDouble_2 "Invalid rvalue type,rvalue must be Double type"

#define _TYPE_mulDouble_1 "Invalid lvalue type,lvalue must be Double type"
#define _TYPE_mulDouble_2 "Invalid rvalue type,rvalue must be Double type"

#define _TYPE_divDouble_1 "Invalid lvalue type,lvalue must be Double type"
#define _TYPE_divDouble_2 "Invalid rvalue type,rvalue must be Double type"

#define _TYPE_surDouble_1 "Invalid lvalue type,lvalue must be Double type"
#define _TYPE_surDouble_2 "Invalid rvalue type,rvalue must be Double type"

#define _ERROR_doAdd_1  "Invalid lvalue type"
#define _ERROR_doAdd_2  "Invalid rvalue type"
#define _ERROR_doAdd_3  "Addition expression operation exception"
#define _ERROR_doAdd_4  "Abnormal data structure of Addition expression"

#define _ERROR_doSub_1  "Invalid lvalue type"
#define _ERROR_doSub_2  "Invalid rvalue type"
#define _ERROR_doSub_3  "Subtraction expression operation exception"
#define _ERROR_doSub_4  "Abnormal data structure of Subtraction expression"

#define _ERROR_doMul_1  "Invalid lvalue type"
#define _ERROR_doMul_2  "Invalid rvalue type"
#define _ERROR_doMul_3  "Multiplication expression operation exception"
#define _ERROR_doMul_4  "Abnormal data structure of Multiplication expression"

#define _ERROR_doDiv_1  "Invalid lvalue type"
#define _ERROR_doDiv_2  "Invalid rvalue type"
#define _ERROR_doDiv_3  "Division expression operation exception"
#define _ERROR_doDiv_4  "Abnormal data structure of Division expression"

#define _ERROR_doSur_1  "Invalid lvalue type"
#define _ERROR_doSur_2  "Invalid rvalue type"
#define _ERROR_doSur_3  "Surplus expression operation exception"
#define _ERROR_doSur_4  "Abnormal data structure of Surplus expression"

#define _ERROR_doAssign_1  "Lvalue must be of variable type"
#define _ERROR_doAssign_2  "The right value is not a valid type"
#define _ERROR_doAssign_3  "Assign expression operation exception"
#define _ERROR_doAssign_4  "Abnormal data structure of Assign expression"

#define _ERROR_doEqual_1  "Invalid lvalue type"
#define _ERROR_doEqual_2  "Invalid rvalue type"
#define _ERROR_doEqual_3  "Equal expression operation exception"
#define _ERROR_doEqual_4  "Abnormal data structure of Equal expression"

#define _ERROR_doNEqual_1  "Invalid lvalue type"
#define _ERROR_doNEqual_2  "Invalid rvalue type"
#define _ERROR_doNEqual_3  "NEqual expression operation exception"
#define _ERROR_doNEqual_4  "Abnormal data structure of Equal expression"

#define _ERROR_doGreater_1  "Invalid lvalue type"
#define _ERROR_doGreater_2  "Invalid rvalue type"
#define _ERROR_doGreater_3  "Greater expression operation exception"
#define _ERROR_doGreater_4  "Abnormal data structure of Equal expression"

#define _ERROR_doLess_1  "Invalid lvalue type"
#define _ERROR_doLess_2  "Invalid rvalue type"
#define _ERROR_doLess_3  "Less expression operation exception"
#define _ERROR_doLess_4  "Abnormal data structure of Equal expression"

#define _ERROR_doEGreater_1  "Invalid lvalue type"
#define _ERROR_doEGreater_2  "Invalid rvalue type"
#define _ERROR_doEGreater_3  "EGreater expression operation exception"
#define _ERROR_doEGreater_4  "Abnormal data structure of Equal expression"

#define _ERROR_doELess_1  "Invalid lvalue type"
#define _ERROR_doELess_2  "Invalid rvalue type"
#define _ERROR_doELess_3  "ELess expression operation exception"
#define _ERROR_doELess_4  "Abnormal data structure of Equal expression"

#define _ERROR_doComma_1  "Lvalue must be of variable type"
#define _ERROR_doComma_2  "The right value is not a valid type"
#define _ERROR_doComma_3  "Comma expression operation exception"
#define _ERROR_doComma_4  "Abnormal data structure of Comma expression"

#define _ERROR_doAnd_1  "Lvalue must be of variable type"
#define _ERROR_doAnd_2  "The right value is not a valid type"
#define _ERROR_doAnd_3  "And expression operation exception"
#define _ERROR_doAnd_4  "Abnormal data structure of And expression"

#define _ERROR_doOr_1  "Lvalue must be of variable type"
#define _ERROR_doOr_2  "The right value is not a valid type"
#define _ERROR_doOr_3  "Or expression operation exception"
#define _ERROR_doOr_4  "Abnormal data structure of Or expression"

#define _ERROR_doNon_2  "The right value is not a valid type"
#define _ERROR_doNon_3  "Or expression operation exception"
#define _ERROR_doNon_4  "Abnormal data structure of Or expression"

#define _ERROR_getVar_1(A,B)  "Variable " + A + " exception : " + B
#define _ERROR_getVar_2(A)  "Unknown variable " + A

#define _ERROR_getVar4Assign_1(A,B)  "Variable " + A + " exception : " + B
#define _ERROR_getVar4Assign_2(A)  "Unknown variable " + A

#define _ERROR_putVar_1(A)  "Duplicate definition variable " + A

#define _ERROR_getElement_1(A,B)  "Abnormal structure of variable " + A + ",Index " + B + " non-existent"
#define _ERROR_getElement_2(A,B)  "Abnormal structure of variable " + A + ",Element " + B + " non-existent"

#define _ERROR_if_1(A)  "Type " + A + " error of return value class of if expression"
#define _ERROR_VAR_1(A,B) "Variable " + B + ",element type " + A + " is not a valid type"
#define _ERROR_VAR_2(A,B) "Variable " + B + ",element Expression return value type '" + A + "' is not a valid type"

#define _ERROR_EXCEPTION_1(A) "Exception element type " + A + " is not a valid type"
#define _ERROR_STATMENT_1(A)  A + " is not a valid statement type"


#define _ERROR_PARSER_1(A) "Alias " + A + " does not exist."

#define _ERROR_PARSER_2(A) "Variable " + A + " does not exist."




#define _TEST_flag_ 0

#endif