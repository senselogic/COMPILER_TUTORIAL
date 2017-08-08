#ifndef __VARIABLE__
    #define __VARIABLE__

    // -- IMPORTS

    struct _FUNCTION;
    #include "passing_type.h"
    #include "value_type.h"

    // -- TYPES

    typedef struct _VARIABLE
    {
        const STRING
            NameString;
        PASSING_TYPE
            PassingType;
        VALUE_TYPE
            ValueType;
        struct _FUNCTION
            * Function;
        int
            CellIndex,
            CellCount;
        struct _VARIABLE
            * PriorVariable,
            * NextVariable;
    } VARIABLE;

    // -- IMPORTS

    #include "function.h"

    // -- FUNCTIONS

    VARIABLE * MakeVariable(
        void
        );

    // ~~

    void FreeVariable(
        VARIABLE * variable
        );

    // ~~

    int GetVariableDepth(
        const VARIABLE * variable,
        const FUNCTION * function
        );
#endif
