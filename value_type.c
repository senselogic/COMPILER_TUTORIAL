// -- IMPORTS

#include "string.h"
#include "system.h"
#include "value_type.h"

// -- FUNCTIONS

const STRING GetValueTypeString(
    const VALUE_TYPE value_type
    )
{
    Assert( value_type >= VALUE_TYPE_First && value_type <= VALUE_TYPE_Last );

    switch ( value_type )
    {
        case VALUE_TYPE_Void : return "void";
        case VALUE_TYPE_Bool : return "bool";
        case VALUE_TYPE_Int : return "int";
    }

    Stop();

    return "";
}
