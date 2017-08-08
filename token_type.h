#ifndef __TOKEN_TYPE__
    #define __TOKEN_TYPE__

    // -- IMPORTS

    #include "string.h"
    struct _RULE;

    // ~~

    #include "y.tab.h"

    // -- TYPES

    typedef int
        TOKEN_TYPE;

    // -- CONSTANTS

    enum
    {
        TOKEN_TYPE_ClosingBracerst = TOKEN_TYPE_And,
        TOKEN_TYPE_Last = TOKEN_TYPE_Write
    };

    // -- FUNCTIONS

    const STRING GetTokenTypeString(
        const TOKEN_TYPE token_type
        );
    
    // ~~

    const STRING GetTokenString(
        const TOKEN_TYPE token_type
        );
#endif
