// -- IMPORTS

#include "allocation.h"
#include "print_mask.h"
#include "program.h"
#include "rule.h"
#include "system.h"
#include "token.h"
#include "token_type.h"

// -- FUNCTIONS

TOKEN * MakeToken(
    const TOKEN_TYPE token_type
    )
{
    TOKEN
        * token;

    Assert( token_type >= 0 && token_type <= TOKEN_TYPE_Last );

    MakeObject( token );
    token->Type = token_type;
    token->Rule = 0;
    token->String = 0;
    token->FilePathString = Program->FilePathString;
    token->FileLineIndex = Program->FileLineIndex;
    token->PriorToken = 0;
    token->NextToken = 0;

    return token;
}

// ~~

void FreeToken(
    TOKEN * token
    )
{
    Assert( token != 0 );

    if ( token->String != 0 )
    {
        FreeString( token->String );
    }

    FreeObject( token );
}

// ~~

void PrintToken(
    const TOKEN * token,
    const int indentation_count,
    const int level_count
    )
{
    Assert( token != 0 );
    Assert( indentation_count >= 0 );

    if ( token->Type == 0 )
    {
        PrintRule( token->Rule, indentation_count, level_count );
    }
    else
    {
        PrintString( "; " );
        PrintFileLocation( token->FilePathString, token->FileLineIndex, 3 );
        PrintSpaces( indentation_count * 4 );
        PrintString( "\"" );

        if ( token->String == 0 )
        {
            PrintString( GetTokenString( token->Type ) );
        }
        else
        {
            PrintString( token->String );
        }

        PrintString( "\"" );

        if ( TracingAllocations )
        {
            PrintSpaces( 32 );
            PrintString( "[" );
            PrintString( GetPaddedIntegerString( ( long long )token, 16, 8, '0' ) );
            PrintString( "]" );
        }

        PrintString( "\n" );
    }
}


