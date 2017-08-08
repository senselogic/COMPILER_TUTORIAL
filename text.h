#ifndef __TEXT__
    #define __TEXT__

    // -- IMPORTS

    #include "string.h"

    // -- TYPES

    typedef struct _TEXT
    {
        STRING
            String;
        struct _TEXT
            * PriorText,
            * NextText;
    } TEXT;

    // -- FUNCTIONS

    TEXT * MakeText(
        void
        );

    // ~~

    void FreeText(
        TEXT * text
        );

    // ~~

    void PrintText(
        TEXT * text
        );
#endif
