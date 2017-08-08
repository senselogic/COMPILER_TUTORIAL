// -- IMPORTS

#include "argument.h"
#include "code.h"
#include "system.h"

// -- FUNCTIONS

ARGUMENT * MakeArgument(
    void
    )
{
    ARGUMENT
        * argument;

    MakeObject( argument );
    argument->Code = MakeCode();
    argument->ValueType = 0;
    argument->Variable = 0;
    argument->PriorArgument = 0;
    argument->NextArgument = 0;

    return argument;
}

// ~~

void FreeArgument(
    ARGUMENT * argument
    )
{
    Assert( argument != 0 );

    FreeCode( argument->Code );
    FreeObject( argument );
}

