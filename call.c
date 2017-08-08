// -- IMPORTS

#include "argument.h"
#include "call.h"
#include "system.h"

// -- FUNCTIONS

CALL * MakeCall(
    void
    )
{
    CALL
        * call;

    MakeObject( call );
    call->FunctionNameString = 0;
    call->ArgumentCount = 0;
    call->FirstArgument = 0;
    call->LastArgument = 0;

    return call;
}

// ~~

void FreeCall(
    CALL * call
    )
{
    ARGUMENT
        * argument,
        * next_argument;

    Assert( call != 0 );

    for ( argument = call->FirstArgument;
          argument != 0;
          argument = next_argument )
    {
        next_argument = argument->NextArgument;
        FreeArgument( argument );
    }

    FreeObject( call );
}

// ~~

void AddLastArgument(
    CALL * call,
    ARGUMENT * last_argument
    )
{
    Assert( call != 0 );
    Assert( last_argument != 0 );
    Assert( last_argument->PriorArgument == 0 );
    Assert( last_argument->NextArgument == 0 );

    ++call->ArgumentCount;

    last_argument->PriorArgument = call->LastArgument;

    if ( call->FirstArgument == 0 )
    {
        call->FirstArgument = last_argument;
        call->LastArgument = last_argument;
    }
    else
    {
        call->LastArgument->NextArgument = last_argument;
    }

    call->LastArgument = last_argument;
}
