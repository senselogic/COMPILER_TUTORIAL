// -- IMPORTS

#include "rule_type.h"
#include "string.h"
#include "system.h"

// -- FUNCTIONS

const STRING GetRuleTypeString(
    const RULE_TYPE rule_type
    )
{
    Assert( rule_type >= RULE_TYPE_First && rule_type <= RULE_TYPE_Last );

    switch ( rule_type )
    {
        case RULE_TYPE_BooleanConstant : return "BooleanConstant";
        case RULE_TYPE_IntegerConstant : return "IntegerConstant";
        case RULE_TYPE_FunctionName : return "FunctionName";
        case RULE_TYPE_VariableName : return "VariableName";
        case RULE_TYPE_FunctionType : return "FunctionType";
        case RULE_TYPE_VariableType : return "VariableType";
        case RULE_TYPE_FunctionArgument : return "FunctionArgument";
        case RULE_TYPE_NextFunctionArgument : return "NextFunctionArgument";
        case RULE_TYPE_FunctionArgumentList : return "FunctionArgumentList";
        case RULE_TYPE_FunctionCall : return "FunctionCall";
        case RULE_TYPE_StarExpression : return "StarExpression";
        case RULE_TYPE_SlashExpression : return "SlashExpression";
        case RULE_TYPE_PlusExpression : return "PlusExpression";
        case RULE_TYPE_MinusExpression : return "MinusExpression";
        case RULE_TYPE_EqualEqualExpression : return "EqualExpression";
        case RULE_TYPE_SmallerEqualExpression : return "SmallerEqualExpression";
        case RULE_TYPE_SmallerExpression : return "SmallerExpression";
        case RULE_TYPE_NotExpression : return "NotExpression";
        case RULE_TYPE_AndExpression : return "AndExpression";
        case RULE_TYPE_OrExpression : return "OrExpression";
        case RULE_TYPE_BooleanConstantExpression : return "BooleanConstantExpression";
        case RULE_TYPE_IntegerConstantExpression : return "IntegerConstantExpression";
        case RULE_TYPE_ParenthesisExpression : return "ParenthesisExpression";
        case RULE_TYPE_FunctionCallExpression : return "FunctionCallExpression";
        case RULE_TYPE_VariableExpression : return "VariableExpression";
        case RULE_TYPE_FunctionParameter : return "FunctionParameter";
        case RULE_TYPE_NextFunctionParameter : return "NextFunctionParameter";
        case RULE_TYPE_FunctionParameterList : return "FunctionParameterList";
        case RULE_TYPE_Variable : return "Variable";
        case RULE_TYPE_NextVariable : return "NextVariable";
        case RULE_TYPE_VariableList : return "VariableList";
        case RULE_TYPE_VariableDeclaration : return "VariableDeclaration";
        case RULE_TYPE_LocalDeclaration : return "LocalDeclaration";
        case RULE_TYPE_LocalDeclarationList : return "LocalDeclarationList";
        case RULE_TYPE_AssignmentStatement : return "AssignmentStatement";
        case RULE_TYPE_ElseStatement : return "ElseStatement";
        case RULE_TYPE_IfStatement : return "IfStatement";
        case RULE_TYPE_WhileStatement : return "WhileStatement";
		case RULE_TYPE_ForStatement : return "ForStatement";
        case RULE_TYPE_WriteStatement : return "WriteStatement";
        case RULE_TYPE_ReadStatement : return "ReadStatement";
        case RULE_TYPE_ReturnStatement : return "ReturnStatement";
        case RULE_TYPE_ExpressionStatement : return "ExpressionStatement";
        case RULE_TYPE_Statement : return "Statement";
        case RULE_TYPE_StatementList : return "StatementList";
        case RULE_TYPE_FunctionBlock : return "FunctionBlock";
        case RULE_TYPE_FunctionDeclaration : return "FunctionDeclaration";
        case RULE_TYPE_Program : return "Program";
    }

    Stop();

    return "";
}
