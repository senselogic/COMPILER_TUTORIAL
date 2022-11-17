// -- IMPORTS

#include "allocation.h"
#include "print_mask.h"
#include "program.h"
#include "rule.h"
#include "rule_type.h"
#include "string.h"
#include "system.h"
#include "token.h"
#include "token_type.h"

// -- FUNCTIONS

RULE * MakeRule(
    const RULE_TYPE rule_type
    )
{
    RULE
        * rule;

    Assert( rule_type >= RULE_TYPE_First && rule_type <= RULE_TYPE_Last );

    MakeObject( rule );
    rule->Type = rule_type;
    rule->FilePathString = Program->FilePathString;
    rule->FileLineIndex = Program->FileLineIndex;
    rule->SuperRule = 0;
    rule->PriorRule = 0;
    rule->NextRule = 0;
    rule->FirstSubRule = 0;
    rule->LastSubRule = 0;
    rule->FirstToken = 0;
    rule->LastToken = 0;

    return rule;
}

// ~~

void FreeRule(
    RULE * rule
    )
{
    RULE
        * sub_rule,
        * next_sub_rule;
    TOKEN
        * token,
        * next_token;

    Assert( rule != 0 );

    for ( sub_rule = rule->FirstSubRule;
          sub_rule != 0;
          sub_rule = next_sub_rule )
    {
        next_sub_rule = sub_rule->NextRule;
        FreeRule( sub_rule );
    }

    for ( token = rule->FirstToken;
          token != 0;
          token = next_token )
    {
        next_token = token->NextToken;
        FreeToken( token );
    }

    FreeObject( rule );
}

// ~~

void PrintRuleError(
    const RULE * rule,
    const STRING error_string,
    const STRING first_token_string,
    const STRING second_token_string
    )
{
    Assert( rule != 0 );
    Assert( rule->FilePathString != 0 );
    Assert( error_string != 0 );
    Assert( first_token_string != 0 || second_token_string == 0 );

    PrintMask = PRINT_MASK_ErrorDebug;
    PrintString( "KO\n" );
    PrintString( rule->FilePathString );
    PrintString( "(" );
    PrintInteger( rule->FileLineIndex );
    PrintString( ") : " );
    PrintString( error_string );

    if ( first_token_string != 0 )
    {
        if ( second_token_string == 0 )
        {
            PrintString( " (\'" );
            PrintString( first_token_string );
            PrintString( "\')" );
        }
        else
        {
            PrintString( " (\'" );
            PrintString( first_token_string );
            PrintString( "\'/\'" );
            PrintString( second_token_string );
            PrintString( "\')" );
        }
    }

    PrintString( "\n" );
    Abort();
}

// ~~

void AddLastTokens(
    RULE * rule,
    TOKEN * first_last_token,
    TOKEN * last_last_token
    )
{
    Assert( rule != 0 );
    Assert( first_last_token != 0 );
    Assert( first_last_token->PriorToken == 0 );
    Assert( last_last_token != 0 );
    Assert( last_last_token->NextToken == 0 );

    first_last_token->PriorToken = rule->LastToken;

    if ( rule->FirstToken == 0 )
    {
        rule->FirstToken = first_last_token;
        rule->LastToken = last_last_token;
    }
    else
    {
        rule->LastToken->NextToken = first_last_token;
    }

    rule->LastToken = last_last_token;

    if ( rule->FileLineIndex > first_last_token->FileLineIndex )
    {
        rule->FileLineIndex = first_last_token->FileLineIndex;
    }
}

// ~~

void AddLastToken(
    RULE * rule,
    TOKEN * last_token
    )
{
    Assert( rule != 0 );
    Assert( last_token != 0 );
    Assert( last_token->PriorToken == 0 );
    Assert( last_token->NextToken == 0 );

    AddLastTokens( rule, last_token, last_token );
}

// ~~

TOKEN * AddLastTokenType(
    RULE * rule,
    const TOKEN_TYPE last_token_type
    )
{
    TOKEN
        * last_token;

    Assert( rule != 0 );
    Assert( last_token_type >= TOKEN_TYPE_First && last_token_type <= TOKEN_TYPE_Last );

    last_token = MakeToken( last_token_type );
    AddLastTokens( rule, last_token, last_token );

    return last_token;
}

// ~~

void AddLastSubRules(
    RULE * rule,
    RULE * first_last_sub_rule,
    RULE * last_last_sub_rule,
    TOKEN * first_last_token,
    TOKEN * last_last_token
    )
{
    RULE
        * last_sub_rule;

    Assert( rule != 0 );
    Assert( first_last_sub_rule != 0 );
    Assert( first_last_sub_rule->PriorRule == 0 );
    Assert( last_last_sub_rule != 0 );
    Assert( last_last_sub_rule->NextRule == 0 );
    Assert( ( first_last_token == 0 ) == ( last_last_token == 0 ) );

    for ( last_sub_rule = first_last_sub_rule;
          last_sub_rule != 0;
          last_sub_rule = last_sub_rule->NextRule )
    {
        last_sub_rule->SuperRule = rule;
    }

    first_last_sub_rule->PriorRule = rule->LastSubRule;

    if ( rule->FirstSubRule == 0 )
    {
        rule->FirstSubRule = first_last_sub_rule;
        rule->LastSubRule = last_last_sub_rule;
    }
    else
    {
        rule->LastSubRule->NextRule = first_last_sub_rule;
    }

    rule->LastSubRule = last_last_sub_rule;

    if ( first_last_token != 0 )
    {
        AddLastTokens( rule, first_last_token, last_last_token );
    }

    if ( rule->FileLineIndex > first_last_sub_rule->FileLineIndex )
    {
        rule->FileLineIndex = first_last_sub_rule->FileLineIndex;
    }
}

// ~~

void AddLastSubRule(
    RULE * rule,
    RULE * last_sub_rule
    )
{
    TOKEN
        * last_token;

    Assert( rule != 0 );
    Assert( last_sub_rule != 0 );
    Assert( last_sub_rule->SuperRule == 0 );
    Assert( last_sub_rule->PriorRule == 0 );
    Assert( last_sub_rule->NextRule == 0 );

    last_token = MakeToken( 0 );
    last_token->Rule = last_sub_rule;

    AddLastSubRules( rule, last_sub_rule, last_sub_rule, last_token, last_token );
}

// ~~

void AddSkippedSubRule(
    RULE * rule,
    RULE * skipped_sub_rule
    )
{
    RULE
        * first_last_sub_rule,
        * last_last_sub_rule;
    TOKEN
        * first_last_token,
        * last_last_token;

    Assert( rule != 0 );
    Assert( skipped_sub_rule != 0 );
    Assert( skipped_sub_rule->SuperRule == 0 );
    Assert( skipped_sub_rule->PriorRule == 0 );
    Assert( skipped_sub_rule->NextRule == 0 );

    first_last_sub_rule = skipped_sub_rule->FirstSubRule;
    last_last_sub_rule = skipped_sub_rule->LastSubRule;
    first_last_token = skipped_sub_rule->FirstToken;
    last_last_token = skipped_sub_rule->LastToken;

    if ( first_last_sub_rule != 0 )
    {
        AddLastSubRules( rule, first_last_sub_rule, last_last_sub_rule, first_last_token, last_last_token );
    }
    else if ( first_last_token != 0 )
    {
        AddLastTokens( rule, first_last_token, last_last_token );
    }

    skipped_sub_rule->FirstSubRule = 0;
    skipped_sub_rule->LastSubRule = 0;
    skipped_sub_rule->FirstToken = 0;
    skipped_sub_rule->LastToken = 0;
    FreeRule( skipped_sub_rule );
}

// ~~

int GetRuleIndentationCount(
    const RULE * rule
    )
{
    int
        indentation_count;
    const RULE
        * super_rule;

    Assert( rule != 0 );

    indentation_count = 0;

    for ( super_rule = rule->SuperRule;
          super_rule != 0;
          super_rule = super_rule->SuperRule )
    {
        ++indentation_count;
    }

    return indentation_count;
}

// ~~

void PrintRule(
    const RULE * rule,
    const int indentation_count,
    const int level_count
    )
{
    const TOKEN
        * token;

    Assert( rule != 0 );
    Assert( indentation_count >= 0 );

    PrintString( "; " );
    PrintFileLocation( rule->FilePathString, rule->FileLineIndex, 3 );
    PrintSpaces( indentation_count * 4 );
    PrintString( GetRuleTypeString( rule->Type ) );

    if ( TracingAllocations )
    {
        PrintSpaces( 32 );
        PrintString( "[" );
        PrintString( GetPaddedIntegerString( ( long long )rule, 16, 8, '0' ) );
        PrintString( "]" );
    }

    PrintString( "\n" );

    if ( level_count != 0 )
    {
        for ( token = rule->FirstToken;
              token != 0;
              token = token->NextToken )
        {
            PrintToken( token, indentation_count + 1, level_count - 1 );
        }
    }
}

// ~~

void ParseBooleanConstantRule(
    RULE * boolean_constant_rule,
    int * boolean_constant
    )
{
    TOKEN
        * boolean_constant_token;

    Assert( boolean_constant_rule != 0 );
    Assert( boolean_constant_rule->Type == RULE_TYPE_BooleanConstant );
    Assert( boolean_constant_rule->FirstSubRule == 0 );
    Assert( boolean_constant != 0 );

    boolean_constant_token = boolean_constant_rule->FirstToken;
    Assert( boolean_constant_token != 0 );

    if ( boolean_constant_token->Type == TOKEN_TYPE_True )
    {
        *boolean_constant = 1;
    }
    else
    {
        Assert( boolean_constant_token->Type == TOKEN_TYPE_False );

        *boolean_constant = 0;
    }
}

// ~~

void ParseIntegerConstantRule(
    RULE * integer_constant_rule,
    int * integer_constant
    )
{
    TOKEN
        * integer_constant_token;

    Assert( integer_constant_rule != 0 );
    Assert( integer_constant_rule->Type == RULE_TYPE_IntegerConstant );
    Assert( integer_constant_rule->FirstSubRule == 0 );
    Assert( integer_constant != 0 );

    integer_constant_token = integer_constant_rule->FirstToken;
    Assert( integer_constant_token != 0 );
    Assert( integer_constant_token->Type == TOKEN_TYPE_Integer );
    Assert( integer_constant_token->String != 0 );

    *integer_constant = GetStringInteger( integer_constant_token->String );
}

// ~~

void ParseNameRule(
    RULE * name_rule,
    const STRING* name_string
    )
{
    TOKEN
        * identifier_token;

    Assert( name_rule != 0 );
    Assert( name_rule->Type == RULE_TYPE_FunctionName
            || name_rule->Type == RULE_TYPE_VariableName );
    Assert( name_rule->FirstSubRule == 0 );
    Assert( name_string != 0 );

    identifier_token = name_rule->FirstToken;
    Assert( identifier_token != 0 );
    Assert( identifier_token->Type == TOKEN_TYPE_Identifier );

    *name_string = identifier_token->String;
}

// ~~

void ParseFunctionNameRule(
    RULE * function_name_rule,
    const STRING* function_name_string
    )
{
    Assert( function_name_rule != 0 );
    Assert( function_name_rule->Type == RULE_TYPE_FunctionName );
    Assert( function_name_string != 0 );

    ParseNameRule( function_name_rule, function_name_string );
}

// ~~

void ParseVariableNameRule(
    RULE * variable_name_rule,
    const STRING* variable_name_string
    )
{
    Assert( variable_name_rule != 0 );
    Assert( variable_name_rule->Type == RULE_TYPE_VariableName );
    Assert( variable_name_string != 0 );

    ParseNameRule( variable_name_rule, variable_name_string );
}

// ~~

void ParseFunctionTypeRule(
    RULE * function_type_rule,
    VALUE_TYPE * function_value_type
    )
{
    TOKEN
        * function_type_token;
    TOKEN_TYPE
        token_type;

    Assert( function_type_rule != 0 );
    Assert( function_type_rule->Type == RULE_TYPE_FunctionType );
    Assert( function_type_rule->FirstSubRule == 0 );
    Assert( function_value_type != 0 );

    function_type_token = function_type_rule->FirstToken;
    Assert( function_type_token != 0 );

    token_type = function_type_token->Type;

    if ( token_type == TOKEN_TYPE_Void )
    {
        *function_value_type = VALUE_TYPE_Void;
    }
    else if ( token_type == TOKEN_TYPE_Bool )
    {
        *function_value_type = VALUE_TYPE_Bool;
    }
    else
    {
        Assert( token_type == TOKEN_TYPE_Int );

        *function_value_type = VALUE_TYPE_Int;
    }
}

// ~~

void ParseVariableTypeRule(
    RULE * variable_type_rule,
    VALUE_TYPE * variable_value_type,
    int * variable_cell_count
    )
{
    TOKEN
        * variable_type_token;
    TOKEN_TYPE
        token_type;

    Assert( variable_type_rule != 0 );
    Assert( variable_type_rule->Type == RULE_TYPE_VariableType );
    Assert( variable_type_rule->FirstSubRule == 0 );
    Assert( variable_value_type != 0 );
    Assert( variable_cell_count != 0 );

    variable_type_token = variable_type_rule->FirstToken;
    Assert( variable_type_token != 0 );

    token_type = variable_type_token->Type;

    if ( token_type == TOKEN_TYPE_Bool )
    {
        *variable_value_type = VALUE_TYPE_Bool;
        *variable_cell_count = 1;
    }
    else
    {
        Assert( token_type == TOKEN_TYPE_Int );
        *variable_value_type = VALUE_TYPE_Int;
        *variable_cell_count = 1;
    }

}

// ~~

void ParseFunctionArgumentRule(
    RULE * function_argument_rule,
    ARGUMENT * argument,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;

    Assert( function_argument_rule != 0 );
    Assert( function_argument_rule->Type == RULE_TYPE_FunctionArgument );
    Assert( argument != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, function_argument_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, argument->Code, &argument->ValueType, &argument->Variable, function );
}

// ~~

void ParseFunctionArgumentListRule(
    RULE * function_argument_list_rule,
    CODE * function_argument_list_code,
    CALL * call,
    FUNCTION * function
    )
{
    RULE
        * function_argument_rule;
    ARGUMENT
        * argument;

    Assert( function_argument_list_rule != 0 );
    Assert( function_argument_list_rule->Type == RULE_TYPE_FunctionArgumentList );
    Assert( function_argument_list_code != 0 );
    Assert( function != 0 );

    for ( function_argument_rule = function_argument_list_rule->FirstSubRule;
          function_argument_rule != 0;
          function_argument_rule = function_argument_rule->NextRule )
    {
        argument = MakeArgument();
        AddLastArgument( call, argument );

        Assert( function_argument_rule->Type == RULE_TYPE_FunctionArgument );
        ParseFunctionArgumentRule( function_argument_rule, argument, function );
    }
}

// ~~

void ParseFunctionCallRule(
    RULE * function_call_rule,
    CODE * function_call_code,
    VALUE_TYPE * function_call_value_type,
    FUNCTION * function
    )
{
    RULE
        * function_name_rule,
        * function_argument_rule;
    CALL
        * call;
    VARIABLE
        * parameter_variable;
    ARGUMENT
        * argument;
    FUNCTION
        * called_function;

    Assert( function_call_rule != 0 );
    Assert( function_call_rule->Type == RULE_TYPE_FunctionCall );
    Assert( function_call_code != 0 );
    Assert( function_call_value_type != 0 );
    Assert( function != 0 );

    call = MakeCall();

    SetFirstSubRule( function_name_rule, function_call_rule, RULE_TYPE_FunctionName );
    ParseFunctionNameRule( function_name_rule, &call->FunctionNameString );

    SetNextRule( function_argument_rule, function_name_rule, RULE_TYPE_FunctionArgumentList );
    Assert( function_argument_rule->NextRule == 0 );
    ParseFunctionArgumentListRule( function_argument_rule, function_call_code, call, function );

    if ( !FindCalledFunction( function, &called_function, call ) )
    {
        PrintRuleError( function_call_rule, "unknown function", call->FunctionNameString, 0 );
    }

    AddIntegerText3( function_call_code, "mst ", GetCalledFunctionDepth( called_function, function ), "\n" );

    parameter_variable = called_function->FirstVariable;

    for ( argument = call->FirstArgument;
          argument != 0;
          argument = argument->NextArgument )
    {
        if ( parameter_variable->PassingType == PASSING_TYPE_Value )
        {
            AddCodeText( function_call_code, argument->Code );

            if ( argument->Variable != 0 )
            {
                AddValueTypeText3( function_call_code, "ind ", argument->Variable->ValueType, "\n" );
            }
        }
        else
        {
            if ( argument->Variable == 0 )
            {
                PrintRuleError( function_call_rule, "incompatible argument type", call->FunctionNameString, parameter_variable->NameString );
            }

            AddVariableAddressText( function_call_code, argument->Variable, function );
        }

        parameter_variable = parameter_variable->NextVariable;
    }

    AddIntegerText2( function_call_code, "cup ", call->ArgumentCount );
    AddFunctionIdentifierText3( function_call_code, " @function_", called_function, "\n" );

    FreeCall( call );

    *function_call_value_type = called_function->ResultValueType;
}

// ~~

void ParseStarExpressionRule(
    RULE * star_expression_rule,
    CODE * star_expression_code,
    VALUE_TYPE * star_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( star_expression_rule != 0 );
    Assert( IsExpressionRuleType( star_expression_rule->Type ) );
    Assert( star_expression_code != 0 );
    Assert( star_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, star_expression_rule );
    ParseExpressionRule( expression_rule, star_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( star_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, star_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( star_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddRuleLocationText3( star_expression_code, "; ", star_expression_rule, " *\n" );
    AddText( star_expression_code, "mul i\n" );

    *star_expression_value_type = VALUE_TYPE_Int;
}

// ~~

void ParseSlashExpressionRule(
    RULE * slash_expression_rule,
    CODE * slash_expression_code,
    VALUE_TYPE * slash_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( slash_expression_rule != 0 );
    Assert( IsExpressionRuleType( slash_expression_rule->Type ) );
    Assert( slash_expression_code != 0 );
    Assert( slash_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, slash_expression_rule );
    ParseExpressionRule( expression_rule, slash_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( slash_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, slash_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( slash_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddRuleLocationText3( slash_expression_code, "; ", slash_expression_rule, " /\n" );
    AddText( slash_expression_code, "div i\n" );

    *slash_expression_value_type = VALUE_TYPE_Int;
}

// ~~

void ParsePlusExpressionRule(
    RULE * plus_expression_rule,
    CODE * plus_expression_code,
    VALUE_TYPE * plus_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( plus_expression_rule != 0 );
    Assert( IsExpressionRuleType( plus_expression_rule->Type ) );
    Assert( plus_expression_code != 0 );
    Assert( plus_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, plus_expression_rule );
    ParseExpressionRule( expression_rule, plus_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( plus_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, plus_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( plus_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddRuleLocationText3( plus_expression_code, "; ", plus_expression_rule, " +\n" );
    AddText( plus_expression_code, "add i\n" );

    *plus_expression_value_type = VALUE_TYPE_Int;
}

// ~~

void ParseMinusExpressionRule(
    RULE * minus_expression_rule,
    CODE * minus_expression_code,
    VALUE_TYPE * minus_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( minus_expression_rule != 0 );
    Assert( IsExpressionRuleType( minus_expression_rule->Type ) );
    Assert( minus_expression_code != 0 );
    Assert( minus_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, minus_expression_rule );
    ParseExpressionRule( expression_rule, minus_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( minus_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, minus_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( minus_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddRuleLocationText3( minus_expression_code, "; ", minus_expression_rule, " -\n" );
    AddText( minus_expression_code, "sub i\n" );

    *minus_expression_value_type = VALUE_TYPE_Int;
}

// ~~

void ParseEqualExpressionRule(
    RULE * equal_expression_rule,
    CODE * equal_expression_code,
    VALUE_TYPE * equal_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type,
        other_expression_value_type;

    Assert( equal_expression_rule != 0 );
    Assert( IsExpressionRuleType( equal_expression_rule->Type ) );
    Assert( equal_expression_code != 0 );
    Assert( equal_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, equal_expression_rule );
    ParseExpressionRule( expression_rule, equal_expression_code, &expression_value_type, 0, function );

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, equal_expression_code, &other_expression_value_type, 0, function );

    if ( other_expression_value_type != expression_value_type )
    {
        PrintRuleError( equal_expression_rule, "incompatible value types", GetValueTypeString( expression_value_type ), GetValueTypeString( other_expression_value_type ) );
    }

    AddRuleLocationText3( equal_expression_code, "; ", equal_expression_rule, " =\n" );
    AddValueTypeText3( equal_expression_code, "equ ", expression_value_type, "\n" );

    *equal_expression_value_type = VALUE_TYPE_Bool;
}

// ~~

void ParseSmallerEqualExpressionRule(
    RULE * smaller_equal_expression_rule,
    CODE * smaller_equal_expression_code,
    VALUE_TYPE * smaller_equal_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( smaller_equal_expression_rule != 0 );
    Assert( IsExpressionRuleType( smaller_equal_expression_rule->Type ) );
    Assert( smaller_equal_expression_code != 0 );
    Assert( smaller_equal_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, smaller_equal_expression_rule );
    ParseExpressionRule( expression_rule, smaller_equal_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( smaller_equal_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, smaller_equal_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( smaller_equal_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddRuleLocationText3( smaller_equal_expression_code, "; ", smaller_equal_expression_rule, " <=\n" );
    AddText( smaller_equal_expression_code, "leq i\n" );

    *smaller_equal_expression_value_type = VALUE_TYPE_Bool;
}

// ~~

void ParseSmallerExpressionRule(
    RULE * smaller_expression_rule,
    CODE * smaller_expression_code,
    VALUE_TYPE * smaller_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( smaller_expression_rule != 0 );
    Assert( IsExpressionRuleType( smaller_expression_rule->Type ) );
    Assert( smaller_expression_code != 0 );
    Assert( smaller_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, smaller_expression_rule );
    ParseExpressionRule( expression_rule, smaller_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( smaller_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, smaller_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( smaller_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddRuleLocationText3( smaller_expression_code, "; ", smaller_expression_rule, " <\n" );
    AddText( smaller_expression_code, "les i\n" );

    *smaller_expression_value_type = VALUE_TYPE_Bool;
}

// ~~

void ParseNotExpressionRule(
    RULE * not_expression_rule,
    CODE * not_expression_code,
    VALUE_TYPE * not_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( not_expression_rule != 0 );
    Assert( IsExpressionRuleType( not_expression_rule->Type ) );
    Assert( not_expression_code != 0 );
    Assert( not_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, not_expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, not_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Bool )
    {
        PrintRuleError( not_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddRuleLocationText3( not_expression_code, "; ", not_expression_rule, " !\n" );
    AddText( not_expression_code, "not b\n" );

    *not_expression_value_type = VALUE_TYPE_Bool;
}

// ~~

void ParseAndExpressionRule(
    RULE * and_expression_rule,
    CODE * and_expression_code,
    VALUE_TYPE * and_expression_value_type,
    FUNCTION * function
    )
{
    int
        label_index;
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( and_expression_rule != 0 );
    Assert( IsExpressionRuleType( and_expression_rule->Type ) );
    Assert( and_expression_code != 0 );
    Assert( and_expression_value_type != 0 );
    Assert( function != 0 );

    label_index = MakeLabelIndex();

    AddRuleLocationText3( and_expression_code, "; ", and_expression_rule, " &&\n" );

    SetFirstExpressionSubRule( expression_rule, and_expression_rule );
    ParseExpressionRule( expression_rule, and_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Bool )
    {
        PrintRuleError( and_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddText( and_expression_code, "not b\n" );
    AddIntegerText3( and_expression_code, "fjp @and_true_", label_index, "\n" );
    AddText( and_expression_code, "ldc b 0\n" );
    AddIntegerText3( and_expression_code, "ujp @and_end_", label_index, "\n" );
    AddIntegerText3( and_expression_code, "define @and_true_", label_index, "\n" );

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, and_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Bool )
    {
        PrintRuleError( and_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddIntegerText3( and_expression_code, "define @and_end_", label_index, "\n" );

    *and_expression_value_type = VALUE_TYPE_Bool;
}

// ~~

void ParseOrExpressionRule(
    RULE * or_expression_rule,
    CODE * or_expression_code,
    VALUE_TYPE * or_expression_value_type,
    FUNCTION * function
    )
{
    int
        label_index;
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( or_expression_rule != 0 );
    Assert( IsExpressionRuleType( or_expression_rule->Type ) );
    Assert( or_expression_code != 0 );
    Assert( or_expression_value_type != 0 );
    Assert( function != 0 );

    label_index = MakeLabelIndex();

    AddRuleLocationText3( or_expression_code, "; ", or_expression_rule, " ||\n" );

    SetFirstExpressionSubRule( expression_rule, or_expression_rule );
    ParseExpressionRule( expression_rule, or_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Bool )
    {
        PrintRuleError( or_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddText( or_expression_code, "not b\n" );
    AddIntegerText3( or_expression_code, "fjp @or_true_", label_index, "\n" );

    SetNextExpressionRule( expression_rule, expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, or_expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Bool )
    {
        PrintRuleError( or_expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddIntegerText3( or_expression_code, "ujp @or_end_", label_index, "\n" );
    AddIntegerText3( or_expression_code, "define @or_true_", label_index, "\n" );
    AddText( or_expression_code, "ldc b 1\n" );
    AddIntegerText3( or_expression_code, "define @or_end_", label_index, "\n" );

    *or_expression_value_type = VALUE_TYPE_Bool;
}

// ~~

void ParseBooleanConstantExpressionRule(
    RULE * boolean_constant_expression_rule,
    CODE * boolean_constant_expression_code,
    VALUE_TYPE * boolean_constant_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * boolean_constant_rule;
    int
        boolean_constant;

    Assert( boolean_constant_expression_rule != 0 );
    Assert( IsExpressionRuleType( boolean_constant_expression_rule->Type ) );
    Assert( boolean_constant_expression_code != 0 );
    Assert( boolean_constant_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstSubRule( boolean_constant_rule, boolean_constant_expression_rule, RULE_TYPE_BooleanConstant );
    Assert( boolean_constant_rule->NextRule == 0 );
    ParseBooleanConstantRule( boolean_constant_rule, &boolean_constant );

    AddText3( boolean_constant_expression_code, "; ", boolean_constant ? "true" : "false", "\n" );
    AddIntegerText3( boolean_constant_expression_code, "ldc b ", boolean_constant, "\n" );

    *boolean_constant_expression_value_type = VALUE_TYPE_Bool;
}

// ~~

void ParseIntegerConstantExpressionRule(
    RULE * integer_constant_expression_rule,
    CODE * integer_constant_expression_code,
    VALUE_TYPE * integer_constant_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * integer_constant_rule;
    int
        integer_constant;

    Assert( integer_constant_expression_rule != 0 );
    Assert( IsExpressionRuleType( integer_constant_expression_rule->Type ) );
    Assert( integer_constant_expression_code != 0 );
    Assert( integer_constant_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstSubRule( integer_constant_rule, integer_constant_expression_rule, RULE_TYPE_IntegerConstant );
    Assert( integer_constant_rule->NextRule == 0 );
    ParseIntegerConstantRule( integer_constant_rule, &integer_constant );

    AddIntegerText3( integer_constant_expression_code, "; ", integer_constant, "\n" );
    AddIntegerText3( integer_constant_expression_code, "ldc i ", integer_constant, "\n" );

    *integer_constant_expression_value_type = VALUE_TYPE_Int;
}

// ~~

void ParseParenthesisExpressionRule(
    RULE * parenthesis_expression_rule,
    CODE * parenthesis_expression_code,
    VALUE_TYPE * parenthesis_expression_value_type,
    VARIABLE ** argument_variable,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;

    Assert( parenthesis_expression_rule != 0 );
    Assert( IsExpressionRuleType( parenthesis_expression_rule->Type ) );
    Assert( parenthesis_expression_code != 0 );
    Assert( parenthesis_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, parenthesis_expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, parenthesis_expression_code, parenthesis_expression_value_type, argument_variable, function );
}

// ~~

void ParseFunctionCallExpressionRule(
    RULE * function_call_expression_rule,
    CODE * function_call_expression_code,
    VALUE_TYPE * function_call_expression_value_type,
    FUNCTION * function
    )
{
    RULE
        * function_call_rule;

    Assert( function_call_expression_rule != 0 );
    Assert( IsExpressionRuleType( function_call_expression_rule->Type ) );
    Assert( function_call_expression_code != 0 );
    Assert( function_call_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstSubRule( function_call_rule, function_call_expression_rule, RULE_TYPE_FunctionCall );
    Assert( function_call_rule->NextRule == 0 );
    ParseFunctionCallRule( function_call_rule, function_call_expression_code, function_call_expression_value_type, function );
}

// ~~

void ParseVariableExpressionRule(
    RULE * variable_expression_rule,
    CODE * variable_expression_code,
    VALUE_TYPE * variable_expression_value_type,
    VARIABLE ** argument_variable,
    FUNCTION * function
    )
{
    RULE
        * variable_name_rule;
    const char
        * variable_name_string;
    VARIABLE
        * found_variable;

    Assert( variable_expression_rule != 0 );
    Assert( variable_expression_rule->Type == RULE_TYPE_VariableExpression );
    Assert( variable_expression_code != 0 );
    Assert( variable_expression_value_type != 0 );
    Assert( function != 0 );

    SetFirstSubRule( variable_name_rule, variable_expression_rule, RULE_TYPE_VariableName );
    Assert( variable_name_rule->NextRule == 0 );
    ParseVariableNameRule( variable_name_rule, &variable_name_string );

    if ( !FindVariable( function, &found_variable, variable_name_string ) )
    {
        PrintRuleError( variable_expression_rule, "unknown variable", variable_name_string, 0 );
    }

    AddVariableAddressText( variable_expression_code, found_variable, function );

    if ( argument_variable != 0 )
    {
        *argument_variable = found_variable;
    }
    else
    {
        AddValueTypeText3( variable_expression_code, "ind ", found_variable->ValueType, "\n" );
    }

    *variable_expression_value_type = found_variable->ValueType;
}

// ~~

void ParseExpressionRule(
    RULE * expression_rule,
    CODE * expression_code,
    VALUE_TYPE * expression_value_type,
    VARIABLE ** argument_variable,
    FUNCTION * function
    )
{
    Assert( expression_rule != 0 );
    Assert( IsExpressionRuleType( expression_rule->Type ) );
    Assert( expression_code != 0 );
    Assert( expression_value_type != 0 );
    Assert( function != 0 );

    if ( argument_variable != 0 )
    {
        *argument_variable = 0;
    }

    if ( expression_rule->Type == RULE_TYPE_StarExpression )
    {
        ParseStarExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_SlashExpression )
    {
        ParseSlashExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_PlusExpression )
    {
        ParsePlusExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_MinusExpression )
    {
        ParseMinusExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_EqualEqualExpression )
    {
        ParseEqualExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_SmallerEqualExpression )
    {
        ParseSmallerEqualExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_SmallerExpression )
    {
        ParseSmallerExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_NotExpression )
    {
        ParseNotExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_AndExpression )
    {
        ParseAndExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_OrExpression )
    {
        ParseOrExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_BooleanConstantExpression )
    {
        ParseBooleanConstantExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_IntegerConstantExpression )
    {
        ParseIntegerConstantExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_ParenthesisExpression )
    {
        ParseParenthesisExpressionRule( expression_rule, expression_code, expression_value_type, argument_variable, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_FunctionCallExpression )
    {
        ParseFunctionCallExpressionRule( expression_rule, expression_code, expression_value_type, function );
    }
    else if ( expression_rule->Type == RULE_TYPE_VariableExpression )
    {
        ParseVariableExpressionRule( expression_rule, expression_code, expression_value_type, argument_variable, function );
    }
    else
    {
        Stop();
    }
}

// ~~

void ParseFunctionParameterRule(
    RULE * function_parameter_rule,
    CODE * function_parameter_code,
    FUNCTION * function
    )
{
    RULE
        * variable_name_rule,
        * variable_type_rule;
    VARIABLE
        * variable;

    Assert( function_parameter_rule != 0 );
    Assert( function_parameter_rule->Type == RULE_TYPE_FunctionParameter );
    Assert( function_parameter_code != 0 );
    Assert( function != 0 );

    variable = MakeVariable();
    AddLastVariable( function, variable );

    ++function->ParameterCount;

    if ( function_parameter_rule->FirstToken->Type == TOKEN_TYPE_Ref )
    {
        variable->PassingType = PASSING_TYPE_Address;
    }
    else
    {
        variable->PassingType = PASSING_TYPE_Value;
    }

    SetFirstSubRule( variable_name_rule, function_parameter_rule, RULE_TYPE_VariableName );
    ParseVariableNameRule( variable_name_rule, &variable->NameString );

    SetNextRule( variable_type_rule, variable_name_rule, RULE_TYPE_VariableType );
    Assert( variable_type_rule->NextRule == 0 );
    ParseVariableTypeRule( variable_type_rule, &variable->ValueType, &variable->CellCount );

    if ( variable->PassingType == PASSING_TYPE_Address )
    {
        variable->CellCount = 1;
    }

    variable->CellIndex = function->CellCount;
    function->CellCount += variable->CellCount;
}

// ~~

void ParseFunctionParameterListRule(
    RULE * function_parameter_list_rule,
    CODE * function_parameter_list_code,
    FUNCTION * function
    )
{
    RULE
        * function_parameter_rule;

    Assert( function_parameter_list_rule != 0 );
    Assert( function_parameter_list_rule->Type == RULE_TYPE_FunctionParameterList );
    Assert( function_parameter_list_code != 0 );
    Assert( function != 0 );
    Assert( function->ParameterCount == 0 );

    for ( function_parameter_rule = function_parameter_list_rule->FirstSubRule;
          function_parameter_rule != 0;
          function_parameter_rule = function_parameter_rule->NextRule )
    {
        Assert( function_parameter_rule->Type == RULE_TYPE_FunctionParameter );
        ParseFunctionParameterRule( function_parameter_rule, function_parameter_list_code, function );
    }
}

// ~~

void ParseVariableRule(
    RULE * variable_rule,
    CODE * variable_code,
    FUNCTION * function
    )
{
    RULE
        * variable_name_rule,
        * variable_type_rule;
    VARIABLE
        * variable;

    Assert( variable_rule != 0 );
    Assert( variable_rule->Type == RULE_TYPE_Variable );
    Assert( variable_code != 0 );
    Assert( function != 0 );

    variable = MakeVariable();
    AddLastVariable( function, variable );

    SetFirstSubRule( variable_name_rule, variable_rule, RULE_TYPE_VariableName );
    ParseVariableNameRule( variable_name_rule, &variable->NameString );

    SetNextRule( variable_type_rule, variable_name_rule, RULE_TYPE_VariableType );
    Assert( variable_type_rule->NextRule == 0 );
    ParseVariableTypeRule( variable_type_rule, &variable->ValueType, &variable->CellCount );

    variable->CellIndex = function->CellCount;
    function->CellCount += variable->CellCount;
}

// ~~

void ParseVariableDeclarationRule(
    RULE * variable_declaration_rule,
    CODE * variable_declaration_code,
    FUNCTION * function
    )
{
    RULE
        * variable_rule;

    Assert( variable_declaration_rule != 0 );
    Assert( variable_declaration_rule->Type == RULE_TYPE_VariableDeclaration );
    Assert( variable_declaration_code != 0 );
    Assert( function != 0 );

    for ( variable_rule = variable_declaration_rule->FirstSubRule;
          variable_rule != 0;
          variable_rule = variable_rule->NextRule )
    {
        Assert( variable_rule->Type == RULE_TYPE_Variable );
        ParseVariableRule( variable_rule, variable_declaration_code, function );
    }
}

// ~~

void ParseLocalDeclarationRule(
    RULE * local_rule,
    CODE * local_code,
    FUNCTION * function
    )
{
    RULE
        * sub_rule;
    FUNCTION
        * sub_function;

    Assert( local_rule != 0 );
    Assert( local_rule->Type == RULE_TYPE_LocalDeclaration );
    Assert( local_code != 0 );
    Assert( function != 0 );

    sub_rule = local_rule->FirstSubRule;
    Assert( sub_rule->NextRule == 0 );

    if ( sub_rule->Type == RULE_TYPE_VariableDeclaration )
    {
        ParseVariableDeclarationRule( sub_rule, local_code, function );
    }
    else
    {
        Assert( sub_rule->Type == RULE_TYPE_FunctionDeclaration );

        sub_function = MakeFunction();
        AddLastSubFunction( function, sub_function );
        ParseFunctionDeclarationRule( sub_rule, local_code, sub_function );
    }
}

// ~~

void ParseLocalDeclarationListRule(
    RULE * local_list_rule,
    CODE * local_list_code,
    FUNCTION * function
    )
{
    RULE
        * local_rule;

    Assert( local_list_rule != 0 );
    Assert( local_list_rule->Type == RULE_TYPE_LocalDeclarationList );
    Assert( local_list_code != 0 );
    Assert( function != 0 );

    for ( local_rule = local_list_rule->FirstSubRule;
          local_rule != 0;
          local_rule = local_rule->NextRule )
    {
        Assert( local_rule->Type == RULE_TYPE_LocalDeclaration );
        ParseLocalDeclarationRule( local_rule, local_list_code, function );
    }
}

// ~~

void ParseAssignmentStatementRule(
    RULE * assignment_statement_rule,
    CODE * assignment_statement_code,
    FUNCTION * function
    )
{
    RULE
        * variable_expression_rule,
        * expression_rule;
    VALUE_TYPE
        expression_value_type,
        variable_expression_value_type;
    VARIABLE
        * variable;

    Assert( assignment_statement_rule != 0 );
    Assert( assignment_statement_rule->Type == RULE_TYPE_AssignmentStatement );
    Assert( assignment_statement_code != 0 );
    Assert( function != 0 );

    SetFirstSubRule( variable_expression_rule, assignment_statement_rule, RULE_TYPE_VariableExpression );
    ParseVariableExpressionRule( variable_expression_rule, assignment_statement_code, &variable_expression_value_type, &variable, function );

    SetNextExpressionRule( expression_rule, variable_expression_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, assignment_statement_code, &expression_value_type, 0, function );

    if ( expression_value_type != variable->ValueType )
    {
        PrintRuleError( assignment_statement_rule, "incompatible value types", GetValueTypeString( expression_value_type ), GetValueTypeString( variable->ValueType ) );
    }

    AddRuleLocationText3( assignment_statement_code, "; ", assignment_statement_rule, " :=\n" );
    AddText( assignment_statement_code, "sto " );
    AddValueTypeText( assignment_statement_code, expression_value_type );
    AddText( assignment_statement_code, "\n" );
}

// ~~

void ParseElseStatementRule(
    RULE * else_statement_rule,
    CODE * else_statement_code,
    FUNCTION * function
    )
{
    RULE
        * statement_list_rule;

    Assert( else_statement_rule != 0 );
    Assert( else_statement_rule->Type == RULE_TYPE_ElseStatement );
    Assert( else_statement_code != 0 );
    Assert( function != 0 );

    if ( else_statement_rule->FirstSubRule != 0 )
    {
        AddRuleLocationText3( else_statement_code, "; ", else_statement_rule, " else\n" );

        SetFirstSubRule( statement_list_rule, else_statement_rule, RULE_TYPE_StatementList );
        Assert( statement_list_rule->NextRule == 0 );
        ParseStatementListRule( statement_list_rule, else_statement_code, function );
    }
}

// ~~

void ParseIfStatementRule(
    RULE * if_statement_rule,
    CODE * if_statement_code,
    FUNCTION * function
    )
{
    int
        label_index;
    RULE
        * expression_rule,
        * statement_list_rule,
        * else_statement_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( if_statement_rule != 0 );
    Assert( if_statement_rule->Type == RULE_TYPE_IfStatement );
    Assert( if_statement_code != 0 );
    Assert( function != 0 );

    label_index = MakeLabelIndex();

    AddRuleLocationText2( if_statement_code, "; ", if_statement_rule );
    AddRuleText3( if_statement_code, "", if_statement_rule, 2, "\n" );

    SetFirstExpressionSubRule( expression_rule, if_statement_rule );
    ParseExpressionRule( expression_rule, if_statement_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Bool )
    {
        PrintRuleError( expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddIntegerText3( if_statement_code, "fjp @if_else_", label_index, "\n" );

    SetNextRule( statement_list_rule, expression_rule, RULE_TYPE_StatementList );
    ParseStatementListRule( statement_list_rule, if_statement_code, function );

    AddIntegerText3( if_statement_code, "ujp @if_end_", label_index, "\n" );
    AddIntegerText3( if_statement_code, "define @if_else_", label_index, "\n" );

    SetNextRule( else_statement_rule, statement_list_rule, RULE_TYPE_ElseStatement );
    Assert( else_statement_rule->NextRule == 0 );
    ParseElseStatementRule( else_statement_rule, if_statement_code, function );

    AddIntegerText3( if_statement_code, "define @if_end_", label_index, "\n" );
}

// ~~

void ParseWhileStatementRule(
    RULE * while_statement_rule,
    CODE * while_statement_code,
    FUNCTION * function
    )
{
    int
        label_index;
    RULE
        * expression_rule,
        * statement_list_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( while_statement_rule != 0 );
    Assert( while_statement_rule->Type == RULE_TYPE_WhileStatement );
    Assert( while_statement_code != 0 );
    Assert( function != 0 );

    label_index = MakeLabelIndex();

    AddRuleLocationText2( while_statement_code, "; ", while_statement_rule );
    AddRuleText3( while_statement_code, "", while_statement_rule, 2, "\n" );

    AddIntegerText3( while_statement_code, "define @while_", label_index, "\n" );

    SetFirstExpressionSubRule( expression_rule, while_statement_rule );
    ParseExpressionRule( expression_rule, while_statement_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Bool )
    {
        PrintRuleError( expression_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddIntegerText3( while_statement_code, "fjp @while_end_", label_index, "\n" );

    SetNextRule( statement_list_rule, expression_rule, RULE_TYPE_StatementList );
    Assert( statement_list_rule->NextRule == 0 );
    ParseStatementListRule( statement_list_rule, while_statement_code, function );

    AddIntegerText3( while_statement_code, "ujp @while_", label_index, "\n" );
    AddIntegerText3( while_statement_code, "define @while_end_", label_index, "\n" );
}

// ~~

void ParseForStatementRule(
    RULE * for_statement_rule,
    CODE * for_statement_code,
    FUNCTION * function
    )
{
    int
        label_index;
    RULE
        * variable_expression_rule,
        * expression_rule,
        * statement_list_rule;
    VALUE_TYPE
        variable_expression_value_type,
        expression_value_type;
    VARIABLE
        * variable;

    Assert( for_statement_rule != 0 );
    Assert( for_statement_rule->Type == RULE_TYPE_ForStatement );
    Assert( for_statement_code != 0 );
    Assert( function != 0 );

    label_index = MakeLabelIndex();

    AddRuleLocationText2( for_statement_code, "; ", for_statement_rule );
    AddRuleText3( for_statement_code, "", for_statement_rule, 2, "\n" );

    SetFirstSubRule( variable_expression_rule, for_statement_rule, RULE_TYPE_VariableExpression );
    ParseVariableExpressionRule( variable_expression_rule, for_statement_code, &variable_expression_value_type, &variable, function );

    if ( variable_expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( for_statement_rule, "bad value type", GetValueTypeString( variable_expression_value_type ), 0 );
    }

    SetNextExpressionRule( expression_rule, variable_expression_rule );
    ParseExpressionRule( expression_rule, for_statement_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( for_statement_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddText( for_statement_code, "sto i\n" );
    AddIntegerText3( for_statement_code, "define @for_", label_index, "\n" );

    ParseVariableExpressionRule( variable_expression_rule, for_statement_code, &variable_expression_value_type, 0, function );
    SetNextExpressionRule( expression_rule, expression_rule );
    ParseExpressionRule( expression_rule, for_statement_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( for_statement_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddText( for_statement_code, "leq i\n" );
    AddIntegerText3( for_statement_code, "fjp @for_end_", label_index, "\n" );

    SetNextRule( statement_list_rule, expression_rule, RULE_TYPE_StatementList );
    Assert( statement_list_rule->NextRule == 0 );
    ParseStatementListRule( statement_list_rule, for_statement_code, function );

    ParseVariableExpressionRule( variable_expression_rule, for_statement_code, &variable_expression_value_type, &variable, function );
    ParseVariableExpressionRule( variable_expression_rule, for_statement_code, &variable_expression_value_type, 0, function );

    AddText( for_statement_code, "ldc i 1\n" );
    AddText( for_statement_code, "add i\n" );
    AddText( for_statement_code, "sto i\n" );
    AddIntegerText3( for_statement_code, "ujp @for_", label_index, "\n" );
    AddIntegerText3( for_statement_code, "define @for_end_", label_index, "\n" );
}

// ~~

void ParseWriteStatementRule(
    RULE * write_statement_rule,
    CODE * write_statement_code,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( write_statement_rule != 0 );
    Assert( write_statement_rule->Type == RULE_TYPE_WriteStatement );
    Assert( write_statement_code != 0 );
    Assert( function != 0 );

    SetFirstExpressionSubRule( expression_rule, write_statement_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, write_statement_code, &expression_value_type, 0, function );

    if ( expression_value_type != VALUE_TYPE_Int )
    {
        PrintRuleError( write_statement_rule, "bad value type", GetValueTypeString( expression_value_type ), 0 );
    }

    AddRuleLocationText3( write_statement_code, "; ", write_statement_rule, " write\n" );
    AddText( write_statement_code, "prin\n" );
}

// ~~

void ParseReadStatementRule(
    RULE * read_statement_rule,
    CODE * read_statement_code,
    FUNCTION * function
    )
{
    RULE
        * variable_expression_rule;
    VALUE_TYPE
        variable_expression_value_type;
    VARIABLE
        * variable;

    Assert( read_statement_rule != 0 );
    Assert( read_statement_rule->Type == RULE_TYPE_ReadStatement );
    Assert( read_statement_code != 0 );
    Assert( function != 0 );

    SetFirstSubRule( variable_expression_rule, read_statement_rule, RULE_TYPE_VariableExpression );
    Assert( variable_expression_rule->NextRule == 0 );
    ParseVariableExpressionRule( variable_expression_rule, read_statement_code, &variable_expression_value_type, &variable, function );

    if ( variable->ValueType != VALUE_TYPE_Int )
    {
        PrintRuleError( read_statement_rule, "bad value type", GetValueTypeString( variable->ValueType ), 0 );
    }

    AddRuleLocationText3( read_statement_code, "; ", read_statement_rule, " read\n" );
    AddText( read_statement_code, "read\n" );
    AddText( read_statement_code, "sto i\n" );
}

// ~~

void ParseReturnStatementRule(
    RULE * return_statement_rule,
    CODE * return_statement_code,
    FUNCTION * function
    )
{
    RULE
        * expression_rule;
    CODE
        * expression_code;
    VALUE_TYPE
        expression_value_type;

    Assert( return_statement_rule != 0 );
    Assert( return_statement_rule->Type == RULE_TYPE_ReturnStatement );
    Assert( return_statement_code != 0 );
    Assert( function != 0 );

    expression_code = MakeCode();

    SetFirstExpressionSubRule( expression_rule, return_statement_rule );
    Assert( expression_rule->NextRule == 0 );
    ParseExpressionRule( expression_rule, expression_code, &expression_value_type, 0, function );

    if ( expression_value_type != function->ResultValueType )
    {
        PrintRuleError( return_statement_rule, "incompatible value types", GetValueTypeString( expression_value_type ), GetValueTypeString( function->ResultValueType ) );
    }

    AddText( return_statement_code, "lda " );
    AddValueTypeText( return_statement_code, expression_value_type );
    AddText( return_statement_code, " 0 0\n" );
    AddCodeText( return_statement_code, expression_code );
    AddText( return_statement_code, "sto " );
    AddValueTypeText( return_statement_code, expression_value_type );
    AddText( return_statement_code, "\n" );
    AddText( return_statement_code, "retf\n" );

    FreeCode( expression_code );
}

// ~~

void ParseExpressionStatementRule(
    RULE * expression_statement_rule,
    CODE * expression_statement_code,
    FUNCTION * function
    )
{
    RULE
        * sub_rule;
    VALUE_TYPE
        expression_value_type;

    Assert( expression_statement_rule != 0 );
    Assert( expression_statement_rule->Type == RULE_TYPE_ExpressionStatement );
    Assert( expression_statement_code != 0 );
    Assert( function != 0 );

    sub_rule = expression_statement_rule->FirstSubRule;

    ParseExpressionRule( sub_rule, expression_statement_code, &expression_value_type, 0, function );
}

// ~~

void ParseStatementRule(
    RULE * statement_rule,
    CODE * statement_code,
    FUNCTION * function
    )
{
    RULE
        * sub_rule;

    Assert( statement_rule != 0 );
    Assert( statement_rule->Type == RULE_TYPE_Statement );
    Assert( statement_code != 0 );
    Assert( function != 0 );

    sub_rule = statement_rule->FirstSubRule;

    if ( sub_rule->Type != RULE_TYPE_IfStatement
         && sub_rule->Type != RULE_TYPE_WhileStatement
         && sub_rule->Type != RULE_TYPE_ForStatement )
    {
        AddRuleLocationText2( statement_code, "; ", sub_rule );
        AddRuleText3( statement_code, "", sub_rule, -1, "\n" );
    }

    if ( sub_rule->Type == RULE_TYPE_AssignmentStatement )
    {
        ParseAssignmentStatementRule( sub_rule, statement_code, function );
    }
    else if ( sub_rule->Type == RULE_TYPE_IfStatement )
    {
        ParseIfStatementRule( sub_rule, statement_code, function );
    }
    else if ( sub_rule->Type == RULE_TYPE_WhileStatement )
    {
        ParseWhileStatementRule( sub_rule, statement_code, function );
    }
    else if ( sub_rule->Type == RULE_TYPE_ForStatement )
    {
        ParseForStatementRule( sub_rule, statement_code, function );
    }
    else if ( sub_rule->Type == RULE_TYPE_WriteStatement )
    {
        ParseWriteStatementRule( sub_rule, statement_code, function );
    }
    else if ( sub_rule->Type == RULE_TYPE_ReadStatement )
    {
        ParseReadStatementRule( sub_rule, statement_code, function );
    }
    else if ( sub_rule->Type == RULE_TYPE_ReturnStatement )
    {
        ParseReturnStatementRule( sub_rule, statement_code, function );
    }
    else if ( sub_rule->Type == RULE_TYPE_ExpressionStatement )
    {
        ParseExpressionStatementRule( sub_rule, statement_code, function );
    }
    else
    {
        Stop();
    }
}

// ~~

void ParseStatementListRule(
    RULE * statement_list_rule,
    CODE * statement_list_code,
    FUNCTION * function
    )
{
    RULE
        * statement_rule;

    Assert( statement_list_rule != 0 );
    Assert( statement_list_rule->Type == RULE_TYPE_StatementList );
    Assert( statement_list_code != 0 );
    Assert( function != 0 );

    for ( statement_rule = statement_list_rule->FirstSubRule;
          statement_rule != 0;
          statement_rule = statement_rule->NextRule )
    {
        Assert( statement_rule->Type == RULE_TYPE_Statement );
        ParseStatementRule( statement_rule, statement_list_code, function );
    }
}

// ~~

void ParseFunctionDeclarationRule(
    RULE * function_rule,
    CODE * function_code,
    FUNCTION * function
    )
{
    RULE
        * function_name_rule,
        * function_parameter_list_rule,
        * function_type_rule,
        * local_list_rule,
        * statement_list_rule;
    FUNCTION
        * super_function,
        * found_function,
        * sub_function;
    int
        it_has_same_passing_type;

    Assert( function_rule != 0 );
    Assert( function_rule->Type == RULE_TYPE_FunctionDeclaration );
    Assert( function_code != 0 );
    Assert( function != 0 );

    function->Rule = function_rule;

    SetFirstSubRule( function_name_rule, function_rule, RULE_TYPE_FunctionName );
    ParseFunctionNameRule( function_name_rule, &function->NameString );

    SetNextRule( function_parameter_list_rule, function_name_rule, RULE_TYPE_FunctionParameterList );
    ParseFunctionParameterListRule( function_parameter_list_rule, function_code, function );

    SetNextRule( function_type_rule, function_parameter_list_rule, RULE_TYPE_FunctionType );
    ParseFunctionTypeRule( function_type_rule, &function->ResultValueType );

    if ( function_type_rule->NextRule != 0 )
    {
        SetNextRule( local_list_rule, function_type_rule, RULE_TYPE_LocalDeclarationList );
        ParseLocalDeclarationListRule( local_list_rule, function_code, function );

        SetNextRule( statement_list_rule, local_list_rule, RULE_TYPE_StatementList );
        Assert( statement_list_rule->NextRule == 0 );

        function->IsImplemented = 1;

        AddFunctionIdentifierText3( function_code, "define @function_", function, "\n" );
        AddIntegerText3( function_code, "ssp ", function->CellCount, "\n" );

        ParseStatementListRule( statement_list_rule, function_code, function );

        if ( function->ResultValueType == VALUE_TYPE_Void )
        {
            AddText( function_code, "retp\n" );
        }
        else
        {
            AddText( function_code, "retf\n" );
        }

        super_function = function->SuperFunction;

        if ( super_function == 0 )
        {
            super_function = function;
        }

        if ( FindFunction( super_function, &found_function, function, &it_has_same_passing_type )
             && found_function != function
             && found_function->SuperFunction == function->SuperFunction )
        {
            if ( found_function->IsImplemented )
            {
                PrintRuleError( function_rule, "duplicate function implementation", function->NameString, 0 );
            }
            else
            {
                if ( !it_has_same_passing_type )
                {
                    PrintRuleError( function_rule, "incompatible function implementation", function->NameString, 0 );
                }

                RemoveSubFunction( function->SuperFunction, found_function );
            }
        }
    }

    for ( sub_function = function->FirstSubFunction;
          sub_function != 0;
          sub_function = sub_function->NextFunction )
    {
        if ( !sub_function->IsImplemented )
        {
            PrintRuleError( sub_function->Rule, "missing function implementation", sub_function->NameString, 0 );
        }
    }
}

// ~~

void ParseProgramRule(
    RULE * program_rule,
    CODE * program_code,
    PROGRAM * program
    )
{
    RULE
        * function_rule;

    Assert( program_rule != 0 );
    Assert( program_rule->Type == RULE_TYPE_Program );
    Assert( program_code != 0 );
    Assert( program != 0 );

    AddText( program_code, "ssp 0\n" );
    AddText( program_code, "ujp @program\n" );

    SetFirstSubRule( function_rule, program_rule, RULE_TYPE_FunctionDeclaration );
    Assert( function_rule->NextRule == 0 );

    program->Function = MakeFunction();
    Assert( program->Function != 0 );

    ParseFunctionDeclarationRule( function_rule, program_code, program->Function );

    if ( program->Function->ParameterCount != 0
         || program->Function->ResultValueType != VALUE_TYPE_Void )
    {
        PrintRuleError( function_rule, "bad function signature", program->Function->NameString, 0 );
    }

    AddText( program_code, "define @program\n" );
    AddText( program_code, "mst 0\n" );
    AddFunctionIdentifierText3( program_code, "cup 0 @function_", program->Function, "\n" );
    AddText( program_code, "stp\n" );
}

