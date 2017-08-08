// -- IMPORTS

#include "function.h"
#include "program.h"
#include "rule.h"
#include "string.h"
#include "system.h"

// ~~

int yyparse(
    void
    );

// -- VARIABLES

PROGRAM
    * Program = 0;

// -- FUNCTIONS

PROGRAM * MakeProgram(
    void
    )
{
    PROGRAM
        * program;

    MakeObject( program );
    program->FilePathString = 0;
    program->FileLineIndex = 1;
    program->Rule = 0;
    program->Function = 0;
    program->Code = 0;
    program->LabelIndex = 0;

    return program;
}

// ~~

void FreeProgram(
    PROGRAM * program
    )
{
    Assert( program != 0 );

    if ( program->Rule != 0 )
    {
        FreeRule( program->Rule );
    }

    if ( program->Function != 0 )
    {
        FreeFunction( program->Function );
    }

    if ( program->Code != 0 )
    {
        FreeCode( program->Code );
    }

    FreeObject( program );
}

// ~~

int MakeLabelIndex(
    void
    )
{
    Assert( Program != 0 );

    return ++Program->LabelIndex;
}

// ~~

void PrintProgramError(
    const STRING error_string,
    const STRING token_string
    )
{
    Assert( error_string != 0 );
    Assert( Program != 0 );
    Assert( Program->FilePathString != 0 );
    Assert( Program->FileLineIndex > 0 );

    PrintMask = PRINT_MASK_ErrorDebug;
    PrintString( "KO\n" );
    PrintString( Program->FilePathString );
    PrintString( "(" );
    PrintInteger( Program->FileLineIndex );
    PrintString( ") : " );
    PrintString( error_string );

    if ( token_string != 0 )
    {
        PrintString( " (\'" );
        PrintString( token_string );
        PrintString( "\')" );
    }

    PrintString( "\n" );
    Abort();
}

// ~~

void MakeProgramRule(
    const STRING file_path_string
    )
{
    Assert( file_path_string != 0 );
    Assert( Program != 0 );

    if ( *file_path_string )
    {
        Program->FilePathString = file_path_string;

        yyin = fopen( file_path_string, "rt" );

        if ( yyin == 0 )
        {
            PrintProgramError( "file not found", file_path_string );
        }
    }
    else
    {
        Program->FilePathString = "stdin";
    }

    yylineno = 1;
    yyparse();
}

// ~~

void CompileProgram(
    const STRING file_path_string
    )
{
    Assert( file_path_string != 0 );

    Program = MakeProgram();

    PrintMask = PRINT_MASK_Debug;
    MakeProgramRule( file_path_string );
    Program->Code = MakeCode();
    ParseProgramRule( Program->Rule, Program->Code, Program );

    PrintMask = PRINT_MASK_ErrorDebug;
    PrintString( "OK\n" );

    PrintMask = PRINT_MASK_OutputDebug;
    PrintCode( Program->Code );
    PrintRule( Program->Rule, 0, -1 );

    FreeProgram( Program );
}
