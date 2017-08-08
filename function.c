// -- IMPORTS

#include "function.h"
#include "string.h"
#include "system.h"

// -- FUNCTIONS

FUNCTION * MakeFunction(
    void
    )
{
    FUNCTION
        * function;

    MakeObject( function );
    function->Rule = 0;
    function->NameString = 0;
    function->ResultValueType = 0;
    function->ParameterCount = 0;
    function->CellCount = 5;
    function->IsImplemented = 0;
    function->FirstVariable = 0;
    function->LastVariable = 0;
    function->SuperFunction = 0;
    function->PriorFunction = 0;
    function->NextFunction = 0;
    function->FirstSubFunction = 0;
    function->LastSubFunction = 0;

    return function;
}

// ~~

void FreeFunction(
    FUNCTION * function
    )
{
    VARIABLE
        * variable,
        * next_variable;
    FUNCTION
        * sub_function,
        * next_sub_function;

    Assert( function != 0 );

    for ( variable = function->FirstVariable;
          variable != 0;
          variable = next_variable )
    {
        next_variable = variable->NextVariable;
        FreeVariable( variable );
    }

    for ( sub_function = function->FirstSubFunction;
          sub_function != 0;
          sub_function = next_sub_function )
    {
        next_sub_function = sub_function->NextFunction;
        FreeFunction( sub_function );
    }

    FreeObject( function );
}

// ~~

int GetLevelIndex(
    const FUNCTION * function
    )
{
    Assert( function != 0 );

    if ( function->SuperFunction == 0 )
    {
        return 0;
    }
    else
    {
        return GetLevelIndex( function->SuperFunction ) + 1;
    }
}

// ~~

void AddLastVariable(
    FUNCTION * function,
    VARIABLE * last_variable
    )
{
    Assert( function != 0 );
    Assert( last_variable != 0 );
    Assert( last_variable->Function == 0 );
    Assert( last_variable->PriorVariable == 0 );
    Assert( last_variable->NextVariable == 0 );

    last_variable->Function = function;
    last_variable->PriorVariable = function->LastVariable;

    if ( function->FirstVariable == 0 )
    {
        function->FirstVariable = last_variable;
        function->LastVariable = last_variable;
    }
    else
    {
        function->LastVariable->NextVariable = last_variable;
    }

    function->LastVariable = last_variable;
}

// ~~

int FindVariable(
    FUNCTION * function,
    VARIABLE ** found_variable,
    const STRING variable_name_string
    )
{
    VARIABLE
        * variable;

    Assert( function != 0 );
    Assert( found_variable != 0 );
    Assert( variable_name_string != 0 );

    for ( variable = function->FirstVariable;
          variable != 0;
          variable = variable->NextVariable )
    {
        if ( IsSameString( variable->NameString, variable_name_string ) )
        {
            *found_variable = variable;

            return 1;
        }
    }

    if ( function->SuperFunction != 0 )
    {
        return FindVariable( function->SuperFunction, found_variable, variable_name_string );
    }

    return 0;
}

// ~~

void AddLastSubFunction(
    FUNCTION * function,
    FUNCTION * last_sub_function
    )
{
    Assert( function != 0 );
    Assert( last_sub_function != 0 );
    Assert( last_sub_function->SuperFunction == 0 );
    Assert( last_sub_function->PriorFunction == 0 );
    Assert( last_sub_function->NextFunction == 0 );

    last_sub_function->SuperFunction = function;
    last_sub_function->PriorFunction = function->LastSubFunction;

    if ( function->FirstSubFunction == 0 )
    {
        function->FirstSubFunction = last_sub_function;
        function->LastSubFunction = last_sub_function;
    }
    else
    {
        function->LastSubFunction->NextFunction = last_sub_function;
    }

    function->LastSubFunction = last_sub_function;
}

// ~~

void RemoveSubFunction(
    FUNCTION * function,
    FUNCTION * sub_function
    )
{
    Assert( function != 0 );
    Assert( sub_function != 0 );
    Assert( sub_function->SuperFunction == function );

    if ( sub_function == function->FirstSubFunction )
    {
        if ( sub_function == function->LastSubFunction )
        {
            function->FirstSubFunction = 0;
            function->LastSubFunction = 0;
        }
        else
        {
            function->FirstSubFunction = sub_function->NextFunction;
            function->FirstSubFunction->PriorFunction = 0;
        }
    }
    else if ( sub_function == function->LastSubFunction )
    {
        function->LastSubFunction = sub_function->PriorFunction;
        function->LastSubFunction->NextFunction = 0;
    }
    else
    {
        sub_function->PriorFunction->NextFunction = sub_function->NextFunction;
        sub_function->NextFunction->PriorFunction = sub_function->PriorFunction;
    }

    sub_function->SuperFunction = 0;
    FreeFunction( sub_function );
}

// ~~

int IsSameFunctionSignature(
    const FUNCTION * function,
    const FUNCTION * other_function,
    int * it_has_same_passing_type
    )
{
    const VARIABLE
        * parameter_variable,
        * other_parameter_variable;
    int
        parameter_index;

    Assert( function != 0 );
    Assert( other_function != 0 );
    Assert( it_has_same_passing_type != 0 );

    if ( IsSameString( function->NameString, other_function->NameString )
         && function->ParameterCount == other_function->ParameterCount )
    {
        *it_has_same_passing_type = 1;

        parameter_variable = function->FirstVariable;
        other_parameter_variable = other_function->FirstVariable;

        for ( parameter_index = 0;
              parameter_index < function->ParameterCount;
              ++parameter_index )
        {
            Assert( parameter_variable != 0 );
            Assert( other_parameter_variable != 0 );

            if ( parameter_variable->ValueType != other_parameter_variable->ValueType )
            {
                return 0;
            }

            if ( parameter_variable->PassingType != other_parameter_variable->PassingType )
            {
                *it_has_same_passing_type = 0;
            }

            parameter_variable = parameter_variable->NextVariable;
            other_parameter_variable = other_parameter_variable->NextVariable;
        }

        return 1;
    }

    return 0;
}

// ~~

int FindFunction(
    FUNCTION * function,
    FUNCTION ** found_function,
    const FUNCTION * searched_function,
    int * it_has_same_passing_type
    )
{
    FUNCTION
        * sub_function;

    Assert( function != 0 );
    Assert( found_function != 0 );
    Assert( searched_function != 0 );
    Assert( it_has_same_passing_type != 0 );

    for ( sub_function = function->FirstSubFunction;
          sub_function != 0;
          sub_function = sub_function->NextFunction )
    {
        if ( IsSameFunctionSignature( sub_function, searched_function, it_has_same_passing_type ) )
        {
            *found_function = sub_function;

            return 1;
        }
    }

    if ( IsSameFunctionSignature( function, searched_function, it_has_same_passing_type ) )
    {
        *found_function = function;

        return 1;
    }

    if ( function->SuperFunction != 0 )
    {
        return FindFunction( function->SuperFunction, found_function, searched_function, it_has_same_passing_type );
    }

    return 0;
}

// ~~

int IsCalledFunction(
    const FUNCTION * function,
    const CALL * call
    )
{
    const VARIABLE
        * parameter_variable;
    const ARGUMENT
        * argument;
    int
        parameter_index;

    Assert( function != 0 );
    Assert( function->NameString != 0 );
    Assert( call != 0 );
    Assert( call->FunctionNameString != 0 );

    if ( IsSameString( function->NameString, call->FunctionNameString )
         && function->ParameterCount == call->ArgumentCount )
    {
        parameter_variable = function->FirstVariable;
        argument = call->FirstArgument;

        for ( parameter_index = 0;
              parameter_index < function->ParameterCount;
              ++parameter_index )
        {
            Assert( parameter_variable != 0 );
            Assert( argument != 0 );

            if ( parameter_variable->ValueType != argument->ValueType )
            {
                return 0;
            }

            parameter_variable = parameter_variable->NextVariable;
            argument = argument->NextArgument;
        }

        return 1;
    }

    return 0;
}

// ~~

int FindCalledFunction(
    FUNCTION * function,
    FUNCTION ** called_function,
    const CALL * call
    )
{
    FUNCTION
        * sub_function;

    Assert( function != 0 );
    Assert( called_function != 0 );
    Assert( call != 0 );

    for ( sub_function = function->FirstSubFunction;
          sub_function != 0;
          sub_function = sub_function->NextFunction )
    {
        if ( IsCalledFunction( sub_function, call ) )
        {
            *called_function = sub_function;

            return 1;
        }
    }

    if ( IsCalledFunction( function, call ) )
    {
        *called_function = function;

        return 1;
    }

    if ( function->SuperFunction != 0 )
    {
        return FindCalledFunction( function->SuperFunction, called_function, call );
    }

    return 0;
}

// ~~

int GetCalledFunctionDepth(
    const FUNCTION * called_function,
    const FUNCTION * function
    )
{
    int
        called_function_depth;

    Assert( called_function != 0 );
    Assert( function != 0 );

    called_function_depth = 1;

    while ( function != called_function )
    {
        if ( called_function->SuperFunction == function )
        {
            return called_function_depth - 1;
        }
        else if ( called_function->SuperFunction == function->SuperFunction )
        {
            return called_function_depth;
        }
        else
        {
            ++called_function_depth;
            function = function->SuperFunction;
            Assert( function != 0 );
        }
    }

    return called_function_depth;
}
