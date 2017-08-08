// -- IMPORTS

#include "string.h"
#include "system.h"

// -- CONSTANTS

#define IntegerStringCount    8
#define IntegerStringByteCount    16

// -- VARIABLES

static char
    IntegerStringArray[ IntegerStringCount ][ IntegerStringByteCount ];
static int
    IntegerStringIndex = IntegerStringCount - 1;

// -- FUNCTIONS

STRING MakeString(
    const STRING first_string
    )
{
    int
        first_character_count,
        byte_count;
    char
        * string;

    Assert( first_string != 0 );

    first_character_count = GetCharacterCount( first_string );
    byte_count = first_character_count + 1;
    MakeObjectArray( string, byte_count );
    CopyByteArray( string, first_string, byte_count );

    return string;
}

// ~~

STRING MakeString2(
    const STRING first_string,
    const STRING second_string
    )
{
    int
        first_character_count,
        second_character_count,
        byte_count;
    char
        * string;

    Assert( first_string != 0 );
    Assert( second_string != 0 );

    first_character_count = GetCharacterCount( first_string );
    second_character_count = GetCharacterCount( second_string );
    byte_count = first_character_count + second_character_count + 1;
    MakeObjectArray( string, byte_count );
    CopyByteArray( string, first_string, first_character_count );
    CopyByteArray( string + first_character_count, second_string, second_character_count + 1 );

    return string;
}

// ~~

STRING MakeString3(
    const STRING first_string,
    const STRING second_string,
    const STRING third_string
    )
{
    int
        first_character_count,
        second_character_count,
        third_character_count,
        byte_count;
    char
        * string;

    Assert( first_string != 0 );
    Assert( second_string != 0 );
    Assert( third_string != 0 );

    first_character_count = GetCharacterCount( first_string );
    second_character_count = GetCharacterCount( second_string );
    third_character_count = GetCharacterCount( third_string );
    byte_count = first_character_count + second_character_count + third_character_count + 1;
    MakeObjectArray( string, byte_count );
    CopyByteArray( string, first_string, first_character_count );
    CopyByteArray( string + first_character_count, second_string, second_character_count );
    CopyByteArray( string + first_character_count + second_character_count, third_string, third_character_count + 1 );

    return string;
}

// ~~

void FreeString(
    STRING string
    )
{
    Assert( string != 0 );

    FreeObjectArray( string );
}

// ~~

const STRING GetIntegerString(
    const int integer,
    const int basis
    )
{
    char
        * decimal_integer_string;

    Assert( basis == 10 || basis == 16 );

    IntegerStringIndex = ( IntegerStringIndex + 1 ) & ( IntegerStringCount - 1 );
    decimal_integer_string = IntegerStringArray[ IntegerStringIndex ];

    if ( basis == 10 )
    {
        sprintf( decimal_integer_string, "%d", integer );
    }
    else
    {
        Assert( basis == 16 );

        sprintf( decimal_integer_string, "%X", integer );
    }

    Assert( GetCharacterCount( decimal_integer_string ) < IntegerStringByteCount );

    return decimal_integer_string;
}

// ~~

const STRING GetPaddedIntegerString(
    const int integer,
    const int basis,
    const int character_count,
    const char padding_character
    )
{
    char
        * integer_string;

    Assert( basis == 10 || basis == 16 );
    Assert( character_count > 0 );
    Assert( character_count < IntegerStringByteCount );
    Assert( padding_character == ' ' || padding_character == '0' );

    IntegerStringIndex = ( IntegerStringIndex + 1 ) & ( IntegerStringCount - 1 );
    integer_string = IntegerStringArray[ IntegerStringIndex ];

    if ( basis == 10 )
    {
        if ( padding_character == '0' )
        {
            sprintf( integer_string, "%0*d", character_count, integer );
        }
        else
        {
            Assert( padding_character == ' ' );

            sprintf( integer_string, "%*d", character_count, integer );
        }
    }
    else
    {
        Assert( basis == 16 );

        if ( padding_character == '0' )
        {
            sprintf( integer_string, "%0*X", character_count, integer );
        }
        else
        {
            Assert( padding_character == ' ' );

            sprintf( integer_string, "%*X", character_count, integer );
        }
    }

    Assert( GetCharacterCount( integer_string ) < IntegerStringByteCount );

    return integer_string;
}

// ~~

const STRING GetPaddedHexadecimalIntegerString(
    const int integer,
    const int character_count,
    const char padding_character
    )
{
    char
        * integer_string;

    Assert( character_count > 0 );
    Assert( character_count < IntegerStringByteCount );
    Assert( padding_character == ' ' || padding_character == '0' );

    IntegerStringIndex = ( IntegerStringIndex + 1 ) & ( IntegerStringCount - 1 );
    integer_string = IntegerStringArray[ IntegerStringIndex ];
    
    if ( padding_character == '0' )
    {
        sprintf( integer_string, "%0*X", character_count, integer );
    }
    else
    {
        Assert( padding_character == ' ' );

        sprintf( integer_string, "%*X", character_count, integer );
    }

    Assert( GetCharacterCount( integer_string ) < IntegerStringByteCount );

    return integer_string;
}
