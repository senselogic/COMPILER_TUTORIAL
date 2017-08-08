// -- IMPORTS

#include "code.h"
#include "function.h"
#include "rule.h"
#include "text.h"
#include "value_type.h"
#include "variable.h"
#include "string.h"
#include "system.h"

// -- FUNCTIONS

CODE * MakeCode(
    void
    )
{
    CODE
        * code;

    MakeObject( code );
    code->FirstText = 0;
    code->LastText = 0;

    return code;
}

// ~~

void FreeCode(
    CODE * code
    )
{
    TEXT
        * text,
        * next_text;

    Assert( code != 0 );

    for ( text = code->FirstText;
          text != 0;
          text = next_text )
    {
        next_text = text->NextText;
        FreeText( text );
    }

    FreeObject( code );
}

// ~~

void PrintCode(
    const CODE * code
    )
{
    TEXT
        * text;

    Assert( code != 0 );

    for ( text = code->FirstText;
          text != 0;
          text = text->NextText )
    {
        PrintText( text );
    }
}

// ~~

void AddLastTexts(
    CODE * code,
    TEXT * first_last_text,
    TEXT * last_last_text
    )
{
    Assert( code != 0 );
    Assert( first_last_text != 0 );
    Assert( first_last_text->PriorText == 0 );
    Assert( last_last_text != 0 );
    Assert( last_last_text->NextText == 0 );

    first_last_text->PriorText = code->LastText;

    if ( code->FirstText == 0 )
    {
        code->FirstText = first_last_text;
        code->LastText = last_last_text;
    }
    else
    {
        code->LastText->NextText = first_last_text;
    }

    code->LastText = last_last_text;
}

// ~~

void AddCodeText(
    CODE * code,
    CODE * last_code
    )
{
    Assert( code != 0 );
    Assert( last_code != 0 );

    if ( last_code->FirstText != 0 )
    {
        AddLastTexts( code, last_code->FirstText, last_code->LastText );
        last_code->FirstText = 0;
        last_code->LastText = 0;
    }
}

// ~~

void AddText(
    CODE * code,
    const STRING string
    )
{
    TEXT
        * last_text;

    Assert( code != 0 );
    Assert( string != 0 );

    last_text = MakeText();
    last_text->String = MakeString( string );
    AddLastTexts( code, last_text, last_text );
}

// ~~

void AddText2(
    CODE * code,
    const STRING first_string,
    const STRING second_string
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( second_string != 0 );

    AddText( code, first_string );
    AddText( code, second_string );
}

// ~~

void AddText3(
    CODE * code,
    const STRING first_string,
    const STRING second_string,
    const STRING third_string
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( second_string != 0 );
    Assert( third_string != 0 );

    AddText( code, first_string );
    AddText( code, second_string );
    AddText( code, third_string );
}

// ~~

void AddIntegerText(
    CODE * code,
    const int integer
    )
{
    Assert( code != 0 );

    AddText( code, GetIntegerString( integer, 10 ) );
}

// ~~

void AddIntegerText2(
    CODE * code,
    const STRING first_string,
    const int integer
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );

    AddText( code, first_string );
    AddIntegerText( code, integer );
}

// ~~

void AddIntegerText3(
    CODE * code,
    const STRING first_string,
    const int integer,
    const STRING last_string
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( last_string != 0 );

    AddText( code, first_string );
    AddIntegerText( code, integer );
    AddText( code, last_string );
}

// ~~

void AddFunctionIdentifierText(
    CODE * code,
    const FUNCTION * function
    )
{
    const VARIABLE
        * parameter_variable;
    int
        parameter_index;

    Assert( code != 0 );
    Assert( function != 0 );
    Assert( function->NameString != 0 );

    AddText3( code, GetValueTypeString( function->ResultValueType ), "_", function->NameString );

    parameter_variable = function->FirstVariable;

    for ( parameter_index = 0;
          parameter_index < function->ParameterCount;
          ++parameter_index )
    {
        AddText2( code, "_", GetValueTypeString( parameter_variable->ValueType ) );
        parameter_variable = parameter_variable->NextVariable;
    }

    if ( function->SuperFunction != 0 )
    {
        AddFunctionIdentifierText2( code, "_of_", function->SuperFunction );
    }
}


// ~~

void AddFunctionIdentifierText2(
    CODE * code,
    const STRING first_string,
    const FUNCTION * function
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( function != 0 );

    AddText( code, first_string );
    AddFunctionIdentifierText( code, function );
}

// ~~

void AddFunctionIdentifierText3(
    CODE * code,
    const STRING first_string,
    const FUNCTION * function,
    const STRING last_string
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( function != 0 );
    Assert( last_string != 0 );

    AddText( code, first_string );
    AddFunctionIdentifierText( code, function );
    AddText( code, last_string );
}

// ~~

void AddValueTypeText(
    CODE * code,
    const VALUE_TYPE value_type
    )
{
    Assert( code != 0 );
    Assert( value_type == VALUE_TYPE_Bool || value_type == VALUE_TYPE_Int );

    if ( value_type == VALUE_TYPE_Bool )
    {
        AddText( code, "b" );
    }
    else 
    {
        Assert( value_type == VALUE_TYPE_Int );
        AddText( code, "i" );
    }
}

// ~~

void AddValueTypeText2(
    CODE * code,
    const STRING first_string,
    const VALUE_TYPE value_type
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( value_type == VALUE_TYPE_Bool || value_type == VALUE_TYPE_Int );

    AddText( code, first_string );
    AddValueTypeText( code, value_type );
}

// ~~

void AddValueTypeText3(
    CODE * code,
    const STRING first_string,
    const VALUE_TYPE value_type,
    const STRING last_string
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( value_type == VALUE_TYPE_Bool || value_type == VALUE_TYPE_Int );
    Assert( last_string != 0 );

    AddText( code, first_string );
    AddValueTypeText( code, value_type );
    AddText( code, last_string );
}

// ~~

void AddVariableAddressText(
    CODE * code,
    const VARIABLE * variable,
    const FUNCTION * function
    )
{
    Assert( code != 0 );
    Assert( variable != 0 );
    Assert( variable->Function != 0 );
    Assert( function != 0 );

    AddText( code, "; " );
    AddText( code, variable->NameString );
    AddFunctionIdentifierText3( code, " of ", variable->Function, "\n" );

    if ( variable->PassingType == PASSING_TYPE_Address )
    {
        AddText( code, "lod a" );
    }
    else
    {
        AddValueTypeText2( code, "lda ", variable->ValueType );
    }

    AddIntegerText2( code, " ", GetVariableDepth( variable, function ) );
    AddIntegerText3( code, " ", variable->CellIndex, "\n" );
}

// ~~

void AddRuleLocationText(
    CODE * code,
    const RULE * rule
    )
{
    Assert( code != 0 );
    Assert( rule != 0 );

    AddText( code, rule->FilePathString );
    AddIntegerText3( code, "(", rule->FileLineIndex, ") :" );
}

// ~~

void AddRuleLocationText2(
    CODE * code,
    const STRING first_string,
    const RULE * rule
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( rule != 0 );

    AddText( code, first_string );
    AddRuleLocationText( code, rule );
}

// ~~

void AddRuleLocationText3(
    CODE * code,
    const STRING first_string,
    const RULE * rule,
    const STRING last_string
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( rule != 0 );
    Assert( last_string != 0 );

    AddText( code, first_string );
    AddRuleLocationText( code, rule );
    AddText( code, last_string );
}

// ~~

void AddRuleText(
    CODE * code,
    const RULE * rule,
    int token_count
    )
{
    TOKEN
        * token;

    Assert( code != 0 );
    Assert( rule != 0 );
    
    for ( token = rule->FirstToken;
          token != 0 
          && token_count != 0;
          token = token->NextToken )
    {
        if ( token->Rule != 0 )
        {
            AddRuleText( code, token->Rule, -1 );
        }
        else
        {
            AddText( code, " " );

            if ( token->String != 0 )
            {
                AddText( code, token->String );
            }
            else
            {
                AddText( code, GetTokenString( token->Type ) );
            }
        }

        --token_count;
    }
}

// ~~

void AddRuleText2(
    CODE * code,
    const STRING first_string,
    const RULE * rule,
    int token_count
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( rule != 0 );

    AddText( code, first_string );
    AddRuleText( code, rule, token_count );
}

// ~~

void AddRuleText3(
    CODE * code,
    const STRING first_string,
    const RULE * rule,
    int token_count,
    const STRING last_string
    )
{
    Assert( code != 0 );
    Assert( first_string != 0 );
    Assert( rule != 0 );
    Assert( last_string != 0 );

    AddText( code, first_string );
    AddRuleText( code, rule, token_count );
    AddText( code, last_string );
}
