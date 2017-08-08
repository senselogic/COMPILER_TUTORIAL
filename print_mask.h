#ifndef __PRINT_MASK__
    #define __PRINT_MASK__

    // -- TYPES

    typedef unsigned int
        PRINT_MASK;

    // .. CONSTANTS

    enum
    {
        PRINT_MASK_Output = 1 << 0,
        PRINT_MASK_Error = 1 << 1,
        PRINT_MASK_Debug = 1 << 2,
        PRINT_MASK_OutputDebug = PRINT_MASK_Output | PRINT_MASK_Debug,
        PRINT_MASK_ErrorDebug = PRINT_MASK_Error | PRINT_MASK_Debug
    };
#endif
