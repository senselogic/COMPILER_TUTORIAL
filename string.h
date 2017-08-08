#ifndef __STRING__
    #define __STRING__

    // -- IMPORTS

    #include <../include/string.h>

    // -- TYPES

    #define STRING    char *

    // -- FUNCTIONS

    STRING MakeString(
        const STRING first_string
        );

    // ~~

    STRING MakeString2(
        const STRING first_string,
        const STRING second_string
        );

    // ~~

    STRING MakeString3(
        const STRING first_string,
        const STRING second_string,
        const STRING third_string
        );

    // ~~

    void FreeString(
        STRING string
        );

    // ~~

    #define CopyString( _string_, _other_string_ ) \
        \
        strcpy( _string_, _other_string_ )

    // ~~

    #define IsSameString( _string_, _other_string_ ) \
        \
        ( !strcmp( _string_, _other_string_ ) )

    // ~~

    #define GetCharacterCount( _string_ ) \
        \
        strlen( _string_ )

    // ~~

    #define GetStringInteger( _string_ ) \
        \
        atoi( _string_ )

    // ~~

    const STRING GetIntegerString(
        const int integer,
        const int basis
        );

    // ~~

    const STRING GetPaddedIntegerString(
        const int integer,
        const int basis,
        const int character_count,
        const char padding_character
        );
#endif
