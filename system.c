// -- IMPORTS

#include "allocation.h"
#include "print_mask.h"
#include "string.h"
#include "system.h"

// ~~

#ifdef _MSC_VER
    void __stdcall OutputDebugStringA( 
        const STRING string 
        );
#endif

// -- VARIABLES

PRINT_MASK
    PrintMask = PRINT_MASK_OutputDebug;

// -- FUNCTIONS

void * MakeByteArray(
    const STRING file_path_string,
    const int file_line_index,
    const int byte_count
    )
{
    Assert( file_path_string != 0 );
    Assert( file_line_index > 0 );
    Assert( byte_count > 0 );

    #ifdef _DEBUG
        return MakeAllocation( file_path_string, file_line_index, byte_count ) + 1;
    #else
        return malloc( byte_count );
    #endif
}

// ~~

void FreeByteArray(
    void * byte_array
    )
{
    Assert( byte_array != 0 );

    #ifdef _DEBUG
        FreeAllocation( ( ALLOCATION * )byte_array - 1 );
    #else
        free( byte_array );
    #endif
}

// ~~

void PrintString(
    const STRING string
    )
{
    Assert( string != 0 );

    if ( *string )
    {
        if ( PrintMask & PRINT_MASK_Output )
        {
            fputs( string, stdout );
        }

        if ( PrintMask & PRINT_MASK_Error )
        {
            fputs( string, stderr );
        }

        #ifdef _MSC_VER
            if ( PrintMask & PRINT_MASK_Debug )
            {
                OutputDebugStringA( string );
            }
        #endif
    }
}

// ~~

void PrintCharacter(
    const char character
    )
{
    char
        string[ 2 ];

    *string = character;
    string[ 1 ] = 0;

    PrintString( string );
}

// ~~

void PrintInteger(
    const int integer
    )
{
    PrintString( GetIntegerString( integer, 10 ) );
}

// ~~

void PrintSpaces(
    int space_count
    )
{
    int
        space_index;

    Assert( space_count >= 0 );

    while ( space_count > 0 )
    {
        if ( space_count >= 64 )
        {
            space_index = 0;
        }
        else
        {
            space_index = 64 - space_count;
        }

        PrintString( "                                                                " + space_index );
        space_count -= 64;
    }
}

// ~~

void PrintFileLocation(
    const STRING file_path_string,
    const int file_line_index,
    const int maximum_space_count
    )
{
    int
        maximum_file_line_index,
        space_count;

    Assert( file_path_string != 0 );
    Assert( file_line_index > 0 );
    Assert( maximum_space_count >= 0 );

    PrintString( file_path_string );
    PrintString( "(" );
    PrintInteger( file_line_index );
    PrintString( ") : " );

    space_count = maximum_space_count;
    maximum_file_line_index = 9;

    while ( space_count > 0
            && file_line_index > maximum_file_line_index )
    {
        --space_count;
        maximum_file_line_index = maximum_file_line_index * 10 + 9;
    }

    PrintSpaces( space_count );
}
