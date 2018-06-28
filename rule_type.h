#ifndef __RULE_TYPE__
    #define __RULE_TYPE__

    // -- IMPORTS

    #include "string.h"

    // -- TYPES

    typedef int
        RULE_TYPE;

    // -- CONSTANTS

    enum
    {
        RULE_TYPE_BooleanConstant = 1,
        RULE_TYPE_IntegerConstant,
        RULE_TYPE_FunctionName,
        RULE_TYPE_VariableName,
        RULE_TYPE_FunctionType,
        RULE_TYPE_VariableType,
        RULE_TYPE_NextFunctionArgument,
        RULE_TYPE_FunctionArgument,
        RULE_TYPE_FunctionArgumentList,
        RULE_TYPE_FunctionCall,
        RULE_TYPE_StarExpression,
        RULE_TYPE_SlashExpression,
        RULE_TYPE_PlusExpression,
        RULE_TYPE_MinusExpression,
        RULE_TYPE_EqualEqualExpression,
        RULE_TYPE_SmallerEqualExpression,
        RULE_TYPE_SmallerExpression,
        RULE_TYPE_NotExpression,
        RULE_TYPE_AndExpression,
        RULE_TYPE_OrExpression,
        RULE_TYPE_BooleanConstantExpression,
        RULE_TYPE_IntegerConstantExpression,
        RULE_TYPE_ParenthesisExpression,
        RULE_TYPE_FunctionCallExpression,
        RULE_TYPE_VariableExpression,
        RULE_TYPE_NextFunctionParameter,
        RULE_TYPE_FunctionParameter,
        RULE_TYPE_FunctionParameterList,
        RULE_TYPE_Variable,
        RULE_TYPE_NextVariable,
        RULE_TYPE_VariableList,
        RULE_TYPE_VariableDeclaration,
        RULE_TYPE_LocalDeclaration,
        RULE_TYPE_LocalDeclarationList,
        RULE_TYPE_AssignmentStatement,
        RULE_TYPE_ElseStatement,
        RULE_TYPE_IfStatement,
        RULE_TYPE_WhileStatement,
        RULE_TYPE_ForStatement,
        RULE_TYPE_WriteStatement,
        RULE_TYPE_ReadStatement,
        RULE_TYPE_ReturnStatement,
        RULE_TYPE_ExpressionStatement,
        RULE_TYPE_Statement,
        RULE_TYPE_StatementList,
        RULE_TYPE_FunctionBlock,
        RULE_TYPE_FunctionDeclaration,
        RULE_TYPE_Program,

        RULE_TYPE_First = 1,
        RULE_TYPE_Last = RULE_TYPE_Program
    };

    // -- FUNCTIONS

    const STRING GetRuleTypeString(
        const RULE_TYPE rule_type
        );

    // ~~

    #define IsExpressionRuleType( _rule_type_ ) \
        \
        ( ( _rule_type_ ) >= RULE_TYPE_StarExpression \
          && ( _rule_type_ ) <= RULE_TYPE_VariableExpression )
#endif
