#ifndef __FUNCTION_
    #define __FUNCTION_

    // -- IMPORTS

    struct _RULE;
    #include "string.h"
    struct _SYMBOL;
    #include "value_type.h"
    struct _VARIABLE;

    // -- TYPES

    typedef struct _FUNCTION
    {
        struct _RULE
            * Rule;
        const STRING
            NameString;
        VALUE_TYPE
            ResultValueType;
        int
            ParameterCount,
            CellCount,
            IsImplemented;
        struct _VARIABLE
            * FirstVariable,
            * LastVariable;
        struct _FUNCTION
            * SuperFunction,
            * PriorFunction,
            * NextFunction,
            * FirstSubFunction,
            * LastSubFunction;
    } FUNCTION;

    // -- IMPORTS

    #include "call.h"
    #include "code.h"
    #include "rule.h"
    #include "variable.h"

    // -- FUNCTIONS

    FUNCTION * MakeFunction(
        void
        );

    // ~~

    void FreeFunction(
        FUNCTION * function
        );

    // ~~

    int GetLevelIndex(
        const FUNCTION * function
        );

    // ~~

    void AddLastVariable(
        FUNCTION * function,
        VARIABLE * last_variable
        );

    // ~~

    int FindVariable(
        FUNCTION * function,
        VARIABLE ** found_variable,
        const STRING variable_name_string
        );

    // ~~

    void AddLastSubFunction(
        FUNCTION * function,
        FUNCTION * last_sub_function
        );

    // ~~

    void RemoveSubFunction(
        FUNCTION * function,
        FUNCTION * sub_function
        );

    // ~~

    int IsSameFunctionSignature(
        const FUNCTION * function,
        const FUNCTION * other_function,
        int * it_has_same_passing_type
        );

    // ~~

    int FindFunction(
        FUNCTION * function,
        FUNCTION ** found_function,
        const FUNCTION * searched_function,
        int * it_has_same_passing_type
        );

    // ~~

    int IsCalledFunction(
        const FUNCTION * function,
        const CALL * call
        );

    // ~~

    int FindCalledFunction(
        FUNCTION * function,
        FUNCTION ** called_function,
        const CALL * call
        );

    // ~~

    int GetCalledFunctionDepth(
        const FUNCTION * called_function,
        const FUNCTION * function
        );
#endif
