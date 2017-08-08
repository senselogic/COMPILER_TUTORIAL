#ifndef __PROGRAM__
    #define __PROGRAM__

    // -- IMPORTS

    struct _CODE;
    struct _FUNCTION;
    struct _RULE;
    #include "string.h"
    #include "system.h"

    // -- TYPES

    typedef struct _PROGRAM
    {
        const STRING
            FilePathString;
        int
            FileLineIndex;
        struct _RULE
            * Rule;
        struct _FUNCTION
            * Function;
        struct _CODE
            * Code;
        int
            LabelIndex;
    } PROGRAM;

    // -- VARIABLES

    extern FILE
        * yyin;
    extern int
        yylineno;
    extern STRING
        yytext;
    extern PROGRAM
        * Program;

    // -- IMPORTS

    #include "code.h"
    #include "rule.h"

    // -- FUNCTIONS

    PROGRAM * MakeProgram(
        void
        );

    // ~~

    void FreeProgram(
        PROGRAM * program
        );

    // ~~

    int MakeLabelIndex(
        void
        );

    // ~~

    void PrintProgramError(
        const STRING error_string,
        const STRING token_string
        );

    // ~~

    void MakeProgramRule(
        const STRING file_path_string
        );

    // ~~

    void CompileProgram(
        const STRING file_path_string
        );
#endif
