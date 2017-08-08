// -- IMPORTS

#include "string.h"
#include "system.h"
#include "text.h"

// -- FUNCTIONS

TEXT * MakeText(
    void
    )
{
    TEXT
        * text;

    MakeObject( text );
    text->String = 0;
    text->PriorText = 0;
    text->NextText = 0;

    return text;
}

// ~~

void FreeText(
    TEXT * text
    )
{
    Assert( text != 0 );

    if ( text->String != 0 )
    {
        FreeString( text->String );
    }

    FreeObject( text );
}

// ~~

void PrintText(
    TEXT * text
    )
{
    Assert( text != 0 );

    if ( text->String != 0 )
    {
        PrintString( text->String );
    }
}
