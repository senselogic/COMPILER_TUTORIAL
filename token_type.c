// -- IMPORTS

#include "string.h"
#include "token_type.h"
#include "system.h"

// -- FUNCTIONS

const STRING GetTokenTypeString(
    const TOKEN_TYPE token_type
    )
{
    Assert( token_type >= TOKEN_TYPE_ClosingBracerst && token_type <= TOKEN_TYPE_Last );

    switch ( token_type )
    {
        case TOKEN_TYPE_And : return "And";
        case TOKEN_TYPE_Bool : return "Bool";
        case TOKEN_TYPE_ClosingBrace : return "ClosingBrace";
        case TOKEN_TYPE_ClosingParenthesis : return "ClosingParenthesis";
        case TOKEN_TYPE_Colon : return "Colon";
        case TOKEN_TYPE_Comma : return "Comma";
        case TOKEN_TYPE_Else : return "Else";
        case TOKEN_TYPE_Equal : return "Equal";
        case TOKEN_TYPE_EqualEqual : return "EqualEqual";
        case TOKEN_TYPE_False : return "False";
        case TOKEN_TYPE_For : return "For";
        case TOKEN_TYPE_Func : return "Func";
        case TOKEN_TYPE_Identifier : return "Identifier";
        case TOKEN_TYPE_If : return "If";
        case TOKEN_TYPE_Int : return "Int";
        case TOKEN_TYPE_Minus : return "Minus";
        case TOKEN_TYPE_Integer : return "Integer";
        case TOKEN_TYPE_Not : return "Not";
        case TOKEN_TYPE_OpeningBrace : return "OpeningBrace";
        case TOKEN_TYPE_OpeningParenthesis : return "OpeningParenthesis";
        case TOKEN_TYPE_Or : return "Or";
        case TOKEN_TYPE_Plus : return "Plus";
        case TOKEN_TYPE_Read : return "Read";
        case TOKEN_TYPE_Ref : return "Ref";
        case TOKEN_TYPE_Return : return "Return";
        case TOKEN_TYPE_Semicolon : return "Semicolon";
        case TOKEN_TYPE_Slash : return "Slash";
        case TOKEN_TYPE_SmallerEqual : return "SmallerEqual";
        case TOKEN_TYPE_Smaller : return "Smaller";
        case TOKEN_TYPE_Star : return "Star";
        case TOKEN_TYPE_To : return "To";
        case TOKEN_TYPE_True : return "True";
        case TOKEN_TYPE_Var : return "Var";
        case TOKEN_TYPE_Void : return "Void";
        case TOKEN_TYPE_While : return "While";
        case TOKEN_TYPE_Write : return "Write";
    }

    Stop();

    return "";
}

// ~~

const STRING GetTokenString(
    const TOKEN_TYPE token_type
    )
{
    Assert( token_type >= TOKEN_TYPE_ClosingBracerst && token_type <= TOKEN_TYPE_Last );

    switch ( token_type )
    {
        case TOKEN_TYPE_And : return "&&";
        case TOKEN_TYPE_Bool : return "bool";
        case TOKEN_TYPE_ClosingBrace : return "}";
        case TOKEN_TYPE_ClosingParenthesis : return ")";
        case TOKEN_TYPE_Colon : return ":";
        case TOKEN_TYPE_Comma : return ",";
        case TOKEN_TYPE_Else : return "else";
        case TOKEN_TYPE_Equal : return "=";
        case TOKEN_TYPE_EqualEqual : return "==";
        case TOKEN_TYPE_False : return "false";
        case TOKEN_TYPE_For : return "for";
        case TOKEN_TYPE_Func : return "func";
        case TOKEN_TYPE_Identifier : return "identifier";
        case TOKEN_TYPE_If : return "if";
        case TOKEN_TYPE_Int : return "int";
        case TOKEN_TYPE_Minus : return "-";
        case TOKEN_TYPE_Integer : return "integer";
        case TOKEN_TYPE_Not : return "!";
        case TOKEN_TYPE_OpeningBrace : return "{";
        case TOKEN_TYPE_OpeningParenthesis : return "(";
        case TOKEN_TYPE_Or : return "||";
        case TOKEN_TYPE_Plus : return "+";
        case TOKEN_TYPE_Read : return "read";
        case TOKEN_TYPE_Ref : return "ref";
        case TOKEN_TYPE_Return : return "return";
        case TOKEN_TYPE_Semicolon : return ";";
        case TOKEN_TYPE_Slash : return "/";
        case TOKEN_TYPE_SmallerEqual : return "<=";
        case TOKEN_TYPE_Smaller : return "<";
        case TOKEN_TYPE_Star : return "*";
        case TOKEN_TYPE_To : return "to";
        case TOKEN_TYPE_True : return "true";
        case TOKEN_TYPE_Var : return "var";
        case TOKEN_TYPE_Void : return "void";
        case TOKEN_TYPE_While : return "while";
        case TOKEN_TYPE_Write : return "write";
    }

    Stop();

    return "";
}
