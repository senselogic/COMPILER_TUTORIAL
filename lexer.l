/*
 *
 */

%{

// -- IMPORTS

#include "program.h"
#include "rule.h"
#include "system.h"
#include "token_type.h"

// -- CONSTANTS

#ifdef _MSC_VER
    #define YY_NO_UNISTD_H
    #define fileno    _fileno
#endif

%}

%option noyywrap yylineno

%%

"&&"    {
    return TOKEN_TYPE_And;
}

"bool"    {
    return TOKEN_TYPE_Bool;
}

"="    {
    return TOKEN_TYPE_Equal;
}

"=="    {
    return TOKEN_TYPE_EqualEqual;
}

"}"    {
    return TOKEN_TYPE_ClosingBrace;
}

")"    {
    return TOKEN_TYPE_ClosingParenthesis;
}

":"    {
    return TOKEN_TYPE_Colon;
}

","    {
    return TOKEN_TYPE_Comma;
}

"else"    {
    return TOKEN_TYPE_Else;
}

"false"    {
    return TOKEN_TYPE_False;
}

"for"    {
    return TOKEN_TYPE_For;
}

"func"    {
    return TOKEN_TYPE_Func;
}

"if"    {
    return TOKEN_TYPE_If;
}

"int"    {
    return TOKEN_TYPE_Int;
}

"-"    {
    return TOKEN_TYPE_Minus;
}

"!"    {
    return TOKEN_TYPE_Not;
}

"{"    {
    return TOKEN_TYPE_OpeningBrace;
}

"("    {
    return TOKEN_TYPE_OpeningParenthesis;
}

"||"    {
    return TOKEN_TYPE_Or;
}

"+"    {
    return TOKEN_TYPE_Plus;
}

"read"    {
    return TOKEN_TYPE_Read;
}

"ref"    {
    return TOKEN_TYPE_Ref;
}

"return"    {
    return TOKEN_TYPE_Return;
}

";"    {
    return TOKEN_TYPE_Semicolon;
}

"/"    {
    return TOKEN_TYPE_Slash;
}

"<="    {
    return TOKEN_TYPE_SmallerEqual;
}

"<"    {
    return TOKEN_TYPE_Smaller;
}

"*"    {
    return TOKEN_TYPE_Star;
}

"to"    {
    return TOKEN_TYPE_To;
}

"true"    {
    return TOKEN_TYPE_True;
}

"var"    {
    return TOKEN_TYPE_Var;
}

"void"    {
    return TOKEN_TYPE_Void;
}

"while"    {
    return TOKEN_TYPE_While;
}

"write"    {
    return TOKEN_TYPE_Write;
}

[a-zA-Z][a-zA-Z0-9]*    {
    yylval.String = MakeString( yytext );

    return TOKEN_TYPE_Identifier;
}

(0|[1-9][0-9]*)    {
    yylval.String = MakeString( yytext );

    return TOKEN_TYPE_Integer;
}

"/*"    {
    int
        prior_character,
        character;

    character = 0;
    
    do
    {
        prior_character = character;
        character = input();

        if ( character <= 0 )
        {
            PrintProgramError( "end of file inside comment", 0 );
        }
    }
    while ( prior_character != '*' || character != '/' );

    Program->FileLineIndex = yylineno;
}

"\n"    {
    Program->FileLineIndex = yylineno;
}

[ \t\f\r]+    {
}

.    {
        PrintProgramError( "invalid character", yytext );
    }

%%
