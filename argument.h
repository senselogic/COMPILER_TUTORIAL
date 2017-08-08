#ifndef __ARGUMENT__
    #define __ARGUMENT__

    // -- IMPORTS

    struct _CODE;
    #include "value_type.h"
    struct _VARIABLE;

    // -- TYPES

    typedef struct _ARGUMENT
    {
        struct _CODE
            * Code;
        VALUE_TYPE
            ValueType;
        struct _VARIABLE
            * Variable;
        struct _ARGUMENT
            * PriorArgument,
            * NextArgument;
    } ARGUMENT;

    // -- FUNCTIONS

    ARGUMENT * MakeArgument(
        void
        );

    // ~~

    void FreeArgument(
        ARGUMENT * argument
        );
#endif
