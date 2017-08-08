#ifndef __PASSING_TYPE__
    #define __PASSING_TYPE__

    // -- TYPES

    typedef int
        PASSING_TYPE;

    // -- CONSTANTS

    enum
    {
        PASSING_TYPE_Value = 1,
        PASSING_TYPE_Address,

        PASSING_TYPE_First = 1,
        PASSING_TYPE_Last = PASSING_TYPE_Address
    };
#endif
