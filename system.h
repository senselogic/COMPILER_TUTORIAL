#ifndef __SYSTEM__
    #define __SYSTEM__

    // -- IMPORTS

    #include <assert.h>
    #include <stdio.h>
    #include <stdlib.h>

    // ~~

    #include "print_mask.h"
    #include "string.h"

    // -- VARIABLES

    extern PRINT_MASK
        PrintMask;

    // -- FUNCTIONS

    void * MakeByteArray(
        const STRING file_path_string,
        const int file_line_index,
        const int allocated_byte_count
        );

    // ~~

    void FreeByteArray(
        void * allocated_byte_array
        );

    // ~~

    #define MakeObject( _object ) \
        \
        _object = MakeByteArray( __FILE__, __LINE__, sizeof( *( _object ) ) )

    // ~~

    #define FreeObject( _object ) \
        \
        FreeByteArray( _object )

    // ~~

    #define MakeObjectArray( _object_array_, _object_count_ ) \
        \
        _object_array_ = MakeByteArray( __FILE__, __LINE__, ( _object_count_ ) * sizeof( *( _object_array_ ) ) )

    // ~~

    #define FreeObjectArray( _object_array_ ) \
        \
        FreeByteArray( _object_array_ )

    // ~~

    #define Exit() \
        \
        exit( 0 );

    // ~~

    #define Abort() \
        \
        exit( 1 );

    // ~~

    #define Assert \
        \
        assert

    // ~~

    #define Stop() \
        \
        assert( 0 )

    // ~~

    #define CopyByteArray( _byte_array_, _other_byte_array_, _byte_count_ ) \
        \
        memcpy( _byte_array_, _other_byte_array_, _byte_count_ )

    // ~~

    void PrintString(
        const STRING string
        );

    // ~~

    void PrintCharacter(
        const char character
        );

    // ~~

    void PrintInteger(
        const int integer
        );

    // ~~

    void PrintSpaces(
        int space_count
        );

    // ~~

    void PrintFileLocation(
        const STRING file_path_string,
        const int file_line_index,
        const int file_line_index_character_count
        );
#endif
