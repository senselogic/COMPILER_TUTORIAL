// -- IMPORTS

#include "allocation.h"
#include "string.h"
#include "system.h"

// -- VARIABLES

ALLOCATION
    * FirstAllocation = 0,
    * LastAllocation = 0;
int
    AllocationIndex = 0,
    AllocationCount = 0,
    TracingAllocations = 0;

// -- FUNCTIONS

ALLOCATION * MakeAllocation(
    const STRING file_path_string,
    const int file_line_index,
    const int byte_count
    )
{
    ALLOCATION
        * allocation;

    Assert( file_path_string != 0 );
    Assert( file_line_index > 0 );
    Assert( byte_count > 0 );

    allocation = malloc( sizeof( ALLOCATION ) + byte_count );
    allocation->FilePathString = file_path_string;
    allocation->FileLineIndex = file_line_index;
    allocation->ByteCount = byte_count;
    allocation->Index = AllocationIndex;
    allocation->PriorAllocation = 0;
    allocation->NextAllocation = 0;

    if ( FirstAllocation == 0 )
    {
        FirstAllocation = allocation;
        LastAllocation = allocation;
    }
    else
    {
        allocation->PriorAllocation = LastAllocation;
        LastAllocation->NextAllocation = allocation;
        LastAllocation = allocation;
    }

    if ( TracingAllocations )
    {
        PrintString( "+ " );
        PrintAllocation( allocation );
    }

    ++AllocationIndex;
    ++AllocationCount;

    return allocation;
}

// ~~

void FreeAllocation(
    ALLOCATION * allocation
    )
{
    Assert( allocation != 0 );

    if ( TracingAllocations )
    {
        PrintString( "- " );
        PrintAllocation( allocation );
    }

    if ( allocation == FirstAllocation )
    {
        if ( allocation == LastAllocation )
        {
            FirstAllocation = 0;
            LastAllocation = 0;
        }
        else
        {
            FirstAllocation = allocation->NextAllocation;
            FirstAllocation->PriorAllocation = 0;
        }
    }
    else if ( allocation == LastAllocation )
    {
        LastAllocation = allocation->PriorAllocation;
        LastAllocation->NextAllocation = 0;
    }
    else
    {
        allocation->PriorAllocation->NextAllocation = allocation->NextAllocation;
        allocation->NextAllocation->PriorAllocation = allocation->PriorAllocation;
    }

    free( allocation );

    --AllocationCount;
}

// ~~

void PrintAllocation(
    const ALLOCATION * allocation
    )
{
    Assert( allocation != 0 );

    PrintFileLocation( allocation->FilePathString, allocation->FileLineIndex, 0 );
    PrintInteger( allocation->ByteCount );
    PrintString( " [" );
    PrintString( GetPaddedIntegerString( ( long long )( allocation + 1 ), 16, 8, '0' ) );
    PrintString( "/" );
    PrintInteger( allocation->Index );
    PrintString( "]\n" );
}

// ~~

void PrintAllocations(
    void
    )
{
    ALLOCATION
        * allocation;

    for ( allocation = FirstAllocation;
          allocation != 0;
          allocation = allocation->NextAllocation )
    {
        PrintAllocation( allocation );
    }
}
