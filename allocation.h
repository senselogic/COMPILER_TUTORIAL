#ifndef __ALLOCATION__
    #define __ALLOCATION__

    // -- IMPORTS

    #include "string.h"

    // -- TYPES

    typedef struct _ALLOCATION
    {
        const STRING
            FilePathString;
        int
            FileLineIndex,
            ByteCount,
            Index;
        struct _ALLOCATION
            * PriorAllocation,
            * NextAllocation;
    } ALLOCATION;

    // -- VARIABLES

    extern int
        AllocationIndex,
        AllocationCount,
        TracingAllocations;

    // -- FUNCTIONS

    ALLOCATION * MakeAllocation(
        const STRING file_path_string,
        const int file_line_index,
        const int byte_count
        );

    // ~~

    void FreeAllocation(
        ALLOCATION * allocation
        );

    // ~~

    void PrintAllocation(
        const ALLOCATION * allocation
        );

    // ~~

    void PrintAllocations(
        void
        );
#endif
