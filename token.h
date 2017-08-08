#ifndef __TOKEN__
    #define __TOKEN__

    // -- IMPORTS

    struct _RULE;
    #include "token_type.h"

    // -- TYPES

    typedef struct _TOKEN
    {
        TOKEN_TYPE
            Type;
        struct _RULE
            * Rule;
        STRING
            String;
        const STRING
            FilePathString;
        int
            FileLineIndex;
        struct _TOKEN
            * PriorToken,
            * NextToken;
    } TOKEN;

    // -- FUNCTIONS

    TOKEN * MakeToken(
        const TOKEN_TYPE token_type
        );

    // ~~

    void FreeToken(
        TOKEN * token
        );

    // ~~

    void PrintToken(
        const TOKEN * token,
        const int indentation_count,
        const int level_count
        );
#endif
