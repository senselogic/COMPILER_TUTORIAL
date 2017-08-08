#ifndef __CALL__
    #define __CALL__

    // -- TYPES

    typedef struct _CALL
    {
        const STRING
            FunctionNameString;
        int
            ArgumentCount;
        struct _ARGUMENT
            * FirstArgument,
            * LastArgument;
    } CALL;

    // -- IMPORTS

    #include "argument.h"

    // -- FUNCTIONS

    CALL * MakeCall(
        void
        );

    // ~~

    void FreeCall(
        CALL * call
        );

    // ~~

    void AddLastArgument(
        CALL * call,
        ARGUMENT * last_argument
        );
#endif
