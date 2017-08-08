#ifndef __RULE__
    #define __RULE__

    // -- IMPORTS

    struct _FUNCTION;
    #include "rule_type.h"
    #include "string.h"
    struct _TOKEN;
    #include "token_type.h"
    #include "value_type.h"
    struct _VARIABLE;

    // -- TYPES

    typedef struct _RULE
    {
        RULE_TYPE
            Type;
        const STRING
            FilePathString;
        int
            FileLineIndex;
        struct _RULE
            * SuperRule,
            * PriorRule,
            * NextRule,
            * FirstSubRule,
            * LastSubRule;
        struct _TOKEN
            * FirstToken,
            * LastToken;
    } RULE;

    // -- IMPORTS

    #include "argument.h"
    #include "call.h"
    #include "code.h"
    #include "function.h"
    #include "program.h"
    #include "rule.h"
    #include "token.h"
    #include "variable.h"

    // -- FUNCTIONS

    RULE * MakeRule(
        const RULE_TYPE rule_type
        );

    // ~~

    void FreeRule(
        RULE * rule
        );

    // ~~

    void PrintRuleError(
        const RULE * rule,
        const STRING error_string,
        const STRING first_token_string,
        const STRING second_token_string
        );

    // ~~

    void AddLastTokens(
        RULE * rule,
        TOKEN * first_last_token,
        TOKEN * last_last_token
        );

    // ~~

    void AddLastToken(
        RULE * rule,
        TOKEN * last_token
        );

    // ~~

    TOKEN * AddLastTokenType(
        RULE * rule,
        const TOKEN_TYPE last_token_type
        );

    // ~~

    void AddLastSubRules(
        RULE * super_rule,
        RULE * first_last_sub_rule,
        RULE * last_last_sub_rule,
        TOKEN * first_last_token,
        TOKEN * last_last_token
        );

    // ~~

    void AddLastSubRule(
        RULE * super_rule,
        RULE * last_sub_rule
        );

    // ~~

    void AddSkippedSubRule(
        RULE * super_rule,
        RULE * skipped_sub_rule
        );

    // ~~

    int GetRuleIndentationCount(
        const RULE * rule
        );

    // ~~

    void PrintRule(
        const RULE * rule,
        const int indentation_count,
        const int level_count
        );

    // ~~

    void ParseBooleanConstantRule(
        RULE * boolean_constant_rule,
        int * boolean_constant
        );

    // ~~

    void ParseIntegerConstantRule(
        RULE * integer_constant_rule,
        int * integer_constant
        );

    // ~~

    void ParseFunctionNameRule(
        RULE * function_name_rule,
        const STRING* function_name_string
        );

    // ~~

    void ParseVariableNameRule(
        RULE * variable_name_rule,
        const STRING* variable_name_string
        );

    // ~~

    void ParseFunctionTypeRule(
        RULE * function_type_rule,
        VALUE_TYPE * function_value_type
        );

    // ~~

    void ParseVariableTypeRule(
        RULE * variable_type_rule,
        VALUE_TYPE * variable_value_type,
        int * variable_cell_count
        );

    // ~~

    void ParseFunctionArgumentRule(
        RULE * function_argument_rule,
        ARGUMENT * argument,
        FUNCTION * function
        );

    // ~~

    void ParseFunctionArgumentListRule(
        RULE * function_argument_list_rule,
        CODE * function_argument_list_code,
        CALL * call,
        FUNCTION * function
        );

    // ~~

    void ParseFunctionCallRule(
        RULE * function_call_rule,
        CODE * function_call_code,
        VALUE_TYPE * function_call_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseStarExpressionRule(
        RULE * star_expression_rule,
        CODE * star_expression_code,
        VALUE_TYPE * star_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseSlashExpressionRule(
        RULE * slash_expression_rule,
        CODE * slash_expression_code,
        VALUE_TYPE * slash_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParsePlusExpressionRule(
        RULE * plus_expression_rule,
        CODE * plus_expression_code,
        VALUE_TYPE * plus_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseMinusExpressionRule(
        RULE * minus_expression_rule,
        CODE * minus_expression_code,
        VALUE_TYPE * minus_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseEqualExpressionRule(
        RULE * equal_expression_rule,
        CODE * equal_expression_code,
        VALUE_TYPE * equal_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseSmallerEqualExpressionRule(
        RULE * smaller_equal_expression_rule,
        CODE * smaller_equal_expression_code,
        VALUE_TYPE * smaller_equal_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseSmallerExpressionRule(
        RULE * smaller_expression_rule,
        CODE * smaller_expression_code,
        VALUE_TYPE * smaller_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseNotExpressionRule(
        RULE * not_expression_rule,
        CODE * not_expression_code,
        VALUE_TYPE * not_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseAndExpressionRule(
        RULE * and_expression_rule,
        CODE * and_expression_code,
        VALUE_TYPE * and_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseOrExpressionRule(
        RULE * or_expression_rule,
        CODE * or_expression_code,
        VALUE_TYPE * or_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseBooleanConstantExpressionRule(
        RULE * boolean_constant_expression_rule,
        CODE * boolean_constant_expression_code,
        VALUE_TYPE * boolean_constant_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseIntegerConstantExpressionRule(
        RULE * integer_constant_expression_rule,
        CODE * integer_constant_expression_code,
        VALUE_TYPE * integer_constant_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseParenthesisExpressionRule(
        RULE * parenthesis_expression_rule,
        CODE * parenthesis_expression_code,
        VALUE_TYPE * parenthesis_expression_value_type,
        VARIABLE ** variable,
        FUNCTION * function
        );

    // ~~

    void ParseFunctionCallExpressionRule(
        RULE * function_call_expression_rule,
        CODE * function_call_expression_code,
        VALUE_TYPE * function_call_expression_value_type,
        FUNCTION * function
        );

    // ~~

    void ParseVariableExpressionRule(
        RULE * variable_expression_rule,
        CODE * variable_expression_code,
        VALUE_TYPE * variable_expression_value_type,
        VARIABLE ** variable,
        FUNCTION * function
        );

    // ~~

    void ParseExpressionRule(
        RULE * expression_rule,
        CODE * expression_code,
        VALUE_TYPE * expression_value_type,
        VARIABLE ** expression_variable,
        FUNCTION * function
        );

    // ~~

    void ParseFunctionParameterRule(
        RULE * function_parameter_rule,
        CODE * function_parameter_code,
        FUNCTION * function
        );

    // ~~

    void ParseFunctionParameterListRule(
        RULE * function_parameter_list_rule,
        CODE * function_parameter_list_code,
        FUNCTION * function
        );

    // ~~

    void ParseVariableRule(
        RULE * variable_rule,
        CODE * variable_code,
        FUNCTION * function
        );
        
    // ~~

    void ParseVariableDeclarationRule(
        RULE * variable_declaration_rule,
        CODE * variable_declaration_code,
        FUNCTION * function
        );

    // ~~

    void ParseLocalDeclarationRule(
        RULE * local_rule,
        CODE * local_code,
        FUNCTION * function
        );

    // ~~

    void ParseLocalDeclarationListRule(
        RULE * local_list_rule,
        CODE * local_list_code,
        FUNCTION * function
        );

    // ~~

    void ParseAssignmentStatementRule(
        RULE * assignment_statement_rule,
        CODE * assignment_statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseElseStatementRule(
        RULE * else_statement_rule,
        CODE * else_statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseIfStatementRule(
        RULE * if_statement_rule,
        CODE * if_statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseWhileStatementRule(
        RULE * while_statement_rule,
        CODE * while_statement_code,
        FUNCTION * function
        );
		
	// ~~

    void ParseForStatementRule(
        RULE * for_statement_rule,
        CODE * for_statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseWriteStatementRule(
        RULE * write_statement_rule,
        CODE * write_statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseReadStatementRule(
        RULE * read_statement_rule,
        CODE * read_statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseReturnStatementRule(
        RULE * return_statement_rule,
        CODE * return_statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseExpressionStatementRule(
        RULE * expression_statement_rule,
        CODE * expression_statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseStatementRule(
        RULE * statement_rule,
        CODE * statement_code,
        FUNCTION * function
        );

    // ~~

    void ParseStatementListRule(
        RULE * statement_list_rule,
        CODE * statement_list_code,
        FUNCTION * function
        );

    // ~~

    void ParseFunctionDeclarationRule(
        RULE * function_rule,
        CODE * function_code,
        FUNCTION * function
        );

    // ~~

    void ParseProgramRule(
        RULE * program_rule,
        CODE * program_code,
        PROGRAM * program
        );

    // ~~

    #define SetFirstSubRule( _first_sub_rule_, _rule_, _sub_rule_type_ ) \
        \
        { \
            _first_sub_rule_ = _rule_->FirstSubRule; \
            Assert( _first_sub_rule_ != 0 ); \
            Assert( _first_sub_rule_->Type == _sub_rule_type_ ); \
        }

    // ~~

    #define SetNextRule( _next_rule_, _rule_, _next_rule_type_ ) \
        \
        { \
            _next_rule_ = _rule_->NextRule; \
            Assert( _next_rule_ != 0 ); \
            Assert( _next_rule_->Type == _next_rule_type_ ); \
        }

    // ~~

    #define SetFirstExpressionSubRule( _first_expression_sub_rule_, _rule_ ) \
        \
        { \
            _first_expression_sub_rule_ = _rule_->FirstSubRule; \
            Assert( _first_expression_sub_rule_ != 0 ); \
            Assert( IsExpressionRuleType( _first_expression_sub_rule_->Type ) ); \
        }

    // ~~

    #define SetNextExpressionRule( _next_expression_rule_, _rule_ ) \
        \
        { \
            _next_expression_rule_ = _rule_->NextRule; \
            Assert( _next_expression_rule_ != 0 ); \
            Assert( IsExpressionRuleType( _next_expression_rule_->Type ) ); \
        }
#endif
