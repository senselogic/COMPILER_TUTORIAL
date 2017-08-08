#ifndef __VALUE_TYPE__
    #define __VALUE_TYPE__

    // -- IMPORTS

    #include "string.h"

    // -- TYPES

    typedef int
        VALUE_TYPE;

    // -- CONSTANTS

    enum
    {
        VALUE_TYPE_Void = 1,
        VALUE_TYPE_Bool,
        VALUE_TYPE_Int,

        VALUE_TYPE_First = 1,
        VALUE_TYPE_Last = VALUE_TYPE_Int
    };

    // -- FUNCTIONS

    const STRING GetValueTypeString(
        const VALUE_TYPE value_type
        );
#endif
