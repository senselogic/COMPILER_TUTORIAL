/*
    This file is part of the CompilerTutorial distribution.

    https://github.com/senselogic/COMPILER_TUTORIAL

    Copyright (C) 2017 Eric Pelzer (ecstatic.coder@gmail.com)

    CompilerTutorial is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3.

    CompilerTutorial is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

// -- IMPORTS

#include "allocation.h"
#include "program.h"
#include "string.h"
#include "system.h"

// -- FUNCTIONS

int main(
    int argument_count,
    STRING * argument_string_array
    )
{
    int
        argument_index;
    char
        * argument_string;

    --argument_count;
    ++argument_string_array;

    if ( argument_count == 0 )
    {
        CompileProgram( "" );
    }
    else
    {
        for ( argument_index = 0;
              argument_index < argument_count;
              ++argument_index )
        {
            argument_string = argument_string_array[ argument_index ];
            CompileProgram( argument_string_array[ argument_index ] );
        }
    }

    PrintMask = PRINT_MASK_Debug;
    PrintAllocations();
    Assert( AllocationCount == 0 );

    return 0;
}
