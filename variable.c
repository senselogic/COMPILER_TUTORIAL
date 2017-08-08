// -- IMPORTS

#include "system.h"
#include "variable.h"

// -- FUNCTIONS

VARIABLE * MakeVariable(
    void
    )
{
    VARIABLE
        * variable;

    MakeObject( variable );
    variable->NameString;
    variable->PassingType = 0;
    variable->ValueType = 0;
    variable->Function = 0;
    variable->CellIndex = 0;
    variable->CellCount = 0;
    variable->PriorVariable = 0;
    variable->NextVariable = 0;

    return variable;
}

// ~~

void FreeVariable(
    VARIABLE * variable
    )
{
    Assert( variable != 0 );

    FreeObject( variable );
}


// ~~

int GetVariableDepth(
    const VARIABLE * variable,
    const FUNCTION * function
    )
{
    int
        variable_depth;

    Assert( variable != 0 );
    Assert( function != 0 );

    variable_depth = 0;

    while ( function != variable->Function )
    {
        ++variable_depth;
        function = function->SuperFunction;
        Assert( function != 0 );
    }

    return variable_depth;
}
