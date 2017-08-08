%{

// -- IMPORTS

#include "program.h"
#include "rule.h"
#include "string.h"
#include "system.h"
#include "token.h"

// ~~

int yylex(
    void
    );

// -- FUNCTIONS

int yyerror(
    STRING string
    )
{
    PrintProgramError( string, yytext );

    return 0;
}

%}

%union
{
    char
        * String;
    struct _TOKEN
        * Token;
    struct _RULE
        * Rule;
}

// ~~

%token TOKEN_TYPE_And
%token TOKEN_TYPE_Bool
%token TOKEN_TYPE_Colon
%token TOKEN_TYPE_Comma
%token TOKEN_TYPE_Else
%token TOKEN_TYPE_ClosingBrace
%token TOKEN_TYPE_ClosingParenthesis
%token TOKEN_TYPE_Equal
%token TOKEN_TYPE_EqualEqual
%token TOKEN_TYPE_False
%token TOKEN_TYPE_For
%token TOKEN_TYPE_Func
%token TOKEN_TYPE_Identifier
%token TOKEN_TYPE_If
%token TOKEN_TYPE_Int
%token TOKEN_TYPE_Minus
%token TOKEN_TYPE_Integer
%token TOKEN_TYPE_Not
%token TOKEN_TYPE_OpeningBrace
%token TOKEN_TYPE_OpeningParenthesis
%token TOKEN_TYPE_Or
%token TOKEN_TYPE_Plus
%token TOKEN_TYPE_Read
%token TOKEN_TYPE_Ref
%token TOKEN_TYPE_Return
%token TOKEN_TYPE_Semicolon
%token TOKEN_TYPE_Slash
%token TOKEN_TYPE_SmallerEqual
%token TOKEN_TYPE_Smaller
%token TOKEN_TYPE_Star
%token TOKEN_TYPE_To
%token TOKEN_TYPE_True
%token TOKEN_TYPE_Var
%token TOKEN_TYPE_Void
%token TOKEN_TYPE_While
%token TOKEN_TYPE_Write

// ~~

%left TOKEN_TYPE_And TOKEN_TYPE_Or
%left TOKEN_TYPE_Not
%left TOKEN_TYPE_EqualEqual TOKEN_TYPE_SmallerEqual TOKEN_TYPE_Smaller
%left TOKEN_TYPE_Plus TOKEN_TYPE_Minus
%left TOKEN_TYPE_Star TOKEN_TYPE_Slash


// ~~


%type <Token> BoolToken
%type <Token> ClosingBraceToken
%type <Token> ClosingParenthesisToken
%type <Token> ColonToken
%type <Token> CommaToken
%type <Token> ElseToken
%type <Token> EqualToken
%type <Token> FalseToken
%type <Token> ForToken
%type <Token> FuncToken
%type <Token> IdentifierToken
%type <Token> IfToken
%type <Token> IntToken
%type <Token> IntegerToken
%type <Token> OpeningBraceToken
%type <Token> OpeningParenthesisToken
%type <Token> ReadToken
%type <Token> RefToken
%type <Token> ReturnToken
%type <Token> SemicolonToken
%type <Token> ToToken
%type <Token> TrueToken
%type <Token> VarToken
%type <Token> VoidToken
%type <Token> WhileToken
%type <Token> WriteToken

// ~~

%type <Rule> BooleanConstantRule
%type <Rule> IntegerConstantRule
%type <Rule> FunctionNameRule
%type <Rule> VariableNameRule
%type <Rule> FunctionTypeRule
%type <Rule> VariableTypeRule
%type <Rule> FunctionArgumentRule
%type <Rule> NextFunctionArgumentRule
%type <Rule> FunctionArgumentListRule
%type <Rule> FunctionCallRule
%type <Rule> VariableExpressionRule
%type <Rule> ExpressionRule
%type <Rule> FunctionParameterRule
%type <Rule> NextFunctionParameterRule
%type <Rule> FunctionParameterListRule
%type <Rule> VariableRule
%type <Rule> NextVariableRule
%type <Rule> VariableListRule
%type <Rule> VariableDeclarationRule
%type <Rule> LocalDeclarationRule
%type <Rule> LocalDeclarationListRule
%type <Rule> AssignmentStatementRule
%type <Rule> ElseStatementRule
%type <Rule> IfStatementRule
%type <Rule> WhileStatementRule
%type <Rule> ForStatementRule
%type <Rule> WriteStatementRule
%type <Rule> ReadStatementRule
%type <Rule> ReturnStatementRule
%type <Rule> ExpressionStatementRule
%type <Rule> StatementRule
%type <Rule> StatementListRule
%type <Rule> FunctionBlockRule
%type <Rule> FunctionDeclarationRule
%type <Rule> ProgramRule

// ~~

%start ProgramRule

%%


BoolToken :

    TOKEN_TYPE_Bool
    {
        $$ = MakeToken( TOKEN_TYPE_Bool );
    }
    ;

EqualToken :

    TOKEN_TYPE_Equal
    {
        $$ = MakeToken( TOKEN_TYPE_Equal );
    }
    ;

ClosingBraceToken :

    TOKEN_TYPE_ClosingBrace
    {
        $$ = MakeToken( TOKEN_TYPE_ClosingBrace );
    }
    ;

ClosingParenthesisToken :

    TOKEN_TYPE_ClosingParenthesis
    {
        $$ = MakeToken( TOKEN_TYPE_ClosingParenthesis );
    }
    ;

ColonToken :

    TOKEN_TYPE_Colon
    {
        $$ = MakeToken( TOKEN_TYPE_Colon );
    }
    ;

CommaToken :

    TOKEN_TYPE_Comma
    {
        $$ = MakeToken( TOKEN_TYPE_Comma );
    }
    ;

ElseToken :

    TOKEN_TYPE_Else
    {
        $$ = MakeToken( TOKEN_TYPE_Else );
    }
    ;

FalseToken :

    TOKEN_TYPE_False
    {
        $$ = MakeToken( TOKEN_TYPE_False );
    }
    ;

ForToken :

    TOKEN_TYPE_For
    {
        $$ = MakeToken( TOKEN_TYPE_For );
    }
    ;
	
FuncToken :

    TOKEN_TYPE_Func
    {
        $$ = MakeToken( TOKEN_TYPE_Func );
    }
    ;

IdentifierToken :

    TOKEN_TYPE_Identifier
    {
        char
            * string;

        string = yyval.String;
        $$ = MakeToken( TOKEN_TYPE_Identifier );
        $$->String = string;
    }
    ;

IfToken :

    TOKEN_TYPE_If
    {
        $$ = MakeToken( TOKEN_TYPE_If );
    }
    ;

IntToken :

    TOKEN_TYPE_Int
    {
        $$ = MakeToken( TOKEN_TYPE_Int );
    }
    ;

IntegerToken :

    TOKEN_TYPE_Integer
    {
        char
            * string;

        string = yyval.String;
        $$ = MakeToken( TOKEN_TYPE_Integer );
        $$->String = string;
    }
    ;

OpeningBraceToken :

    TOKEN_TYPE_OpeningBrace
    {
        $$ = MakeToken( TOKEN_TYPE_OpeningBrace );
    }
    ;

OpeningParenthesisToken :

    TOKEN_TYPE_OpeningParenthesis
    {
        $$ = MakeToken( TOKEN_TYPE_OpeningParenthesis );
    }
    ;

ReadToken :

    TOKEN_TYPE_Read
    {
        $$ = MakeToken( TOKEN_TYPE_Read );
    }
    ;

RefToken :

    TOKEN_TYPE_Ref
    {
        $$ = MakeToken( TOKEN_TYPE_Ref );
    }
    ;
ReturnToken :

    TOKEN_TYPE_Return
    {
        $$ = MakeToken( TOKEN_TYPE_Return );
    }
    ;

SemicolonToken :

    TOKEN_TYPE_Semicolon
    {
        $$ = MakeToken( TOKEN_TYPE_Semicolon );
    }
    ;

ToToken :

    TOKEN_TYPE_To
    {
        $$ = MakeToken( TOKEN_TYPE_To );
    }
    ;

TrueToken :

    TOKEN_TYPE_True
    {
        $$ = MakeToken( TOKEN_TYPE_True );
    }
    ;

VarToken :

    TOKEN_TYPE_Var
    {
        $$ = MakeToken( TOKEN_TYPE_Var );
    }
    ;

VoidToken :

    TOKEN_TYPE_Void
    {
        $$ = MakeToken( TOKEN_TYPE_Void );
    }
    ;

WhileToken :

    TOKEN_TYPE_While
    {
        $$ = MakeToken( TOKEN_TYPE_While );
    }
    ;

WriteToken :

    TOKEN_TYPE_Write
    {
        $$ = MakeToken( TOKEN_TYPE_Write );
    }
    ;

BooleanConstantRule :

    FalseToken
    {
        $$ = MakeRule( RULE_TYPE_BooleanConstant );
        AddLastToken( $$, $1 );
    }
    |
    TrueToken
    {
        $$ = MakeRule( RULE_TYPE_BooleanConstant );
        AddLastToken( $$, $1 );
    }
    ;

IntegerConstantRule :

    IntegerToken
    {
        $$ = MakeRule( RULE_TYPE_IntegerConstant );
        AddLastToken( $$, $1 );
    }
    |
    TOKEN_TYPE_Minus
    IntegerToken
    {
        $$ = MakeRule( RULE_TYPE_IntegerConstant );
        AddLastToken( $$, MakeToken( TOKEN_TYPE_Integer ) );
        $$->FirstToken->String = MakeString2( "-", $2->String );
        FreeToken( $2 );
    }
    ;

FunctionNameRule :

    IdentifierToken
    {
        $$ = MakeRule( RULE_TYPE_FunctionName );
        AddLastToken( $$, $1 );
    }
    ;

VariableNameRule :

    IdentifierToken
    {
        $$ = MakeRule( RULE_TYPE_VariableName );
        AddLastToken( $$, $1 );
    }
    ;

FunctionTypeRule :

    VoidToken
    {
        $$ = MakeRule( RULE_TYPE_FunctionType );
        AddLastToken( $$, $1 );
    }
    |
    BoolToken
    {
        $$ = MakeRule( RULE_TYPE_FunctionType );
        AddLastToken( $$, $1 );
    }
    |
    IntToken
    {
        $$ = MakeRule( RULE_TYPE_FunctionType );
        AddLastToken( $$, $1 );
    }
    ;

VariableTypeRule :

    BoolToken
    {
        $$ = MakeRule( RULE_TYPE_VariableType );
        AddLastToken( $$, $1 );
    }
    |
    IntToken
    {
        $$ = MakeRule( RULE_TYPE_VariableType );
        AddLastToken( $$, $1 );
    }
    ;

FunctionArgumentRule :

    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_FunctionArgument );
        AddLastSubRule( $$, $1 );
    }
    ;

NextFunctionArgumentRule :

    CommaToken
    FunctionArgumentListRule
    {
        $$ = MakeRule( RULE_TYPE_NextFunctionArgument );
        AddLastToken( $$, $1 );
        AddSkippedSubRule( $$, $2 );
    }
    |
    {
        $$ = MakeRule( RULE_TYPE_NextFunctionArgument );
    }
    ;

FunctionArgumentListRule :

    FunctionArgumentRule
    NextFunctionArgumentRule
    {
        $$ = MakeRule( RULE_TYPE_FunctionArgumentList );
        AddLastSubRule( $$, $1 );
        AddSkippedSubRule( $$, $2 );
    }
    |
    {
        $$ = MakeRule( RULE_TYPE_FunctionArgumentList );
    }
    ;

FunctionCallRule :

    FunctionNameRule
    OpeningParenthesisToken
    FunctionArgumentListRule
    ClosingParenthesisToken
    {
        $$ = MakeRule( RULE_TYPE_FunctionCall );
        AddLastSubRule( $$, $1 );
        AddLastToken( $$, $2 );
        AddLastSubRule( $$, $3 );
        AddLastToken( $$, $4 );
    }
    ;

VariableExpressionRule :

    VariableNameRule
    {
        $$ = MakeRule( RULE_TYPE_VariableExpression );
        AddLastSubRule( $$, $1 );
    }
    ;

ExpressionRule :

    ExpressionRule
    TOKEN_TYPE_Star
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_StarExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_Star );
        AddLastSubRule( $$, $3 );
    }
    |
    ExpressionRule
    TOKEN_TYPE_Slash
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_SlashExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_Slash );
        AddLastSubRule( $$, $3 );
    }
    |
    ExpressionRule
    TOKEN_TYPE_Plus
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_PlusExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_Plus );
        AddLastSubRule( $$, $3 );
    }
    |
    ExpressionRule
    TOKEN_TYPE_Minus
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_MinusExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_Minus );
        AddLastSubRule( $$, $3 );
    }
    |
    ExpressionRule
    TOKEN_TYPE_EqualEqual
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_EqualEqualExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_EqualEqual );
        AddLastSubRule( $$, $3 );
    }
    |
    ExpressionRule
    TOKEN_TYPE_SmallerEqual
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_SmallerEqualExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_SmallerEqual );
        AddLastSubRule( $$, $3 );
    }
    |
    ExpressionRule
    TOKEN_TYPE_Smaller
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_SmallerExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_Smaller );
        AddLastSubRule( $$, $3 );
    }
    |
    TOKEN_TYPE_Not
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_NotExpression );
        AddLastTokenType( $$, TOKEN_TYPE_Not );
        AddLastSubRule( $$, $2 );
    }
    |
    ExpressionRule
    TOKEN_TYPE_And
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_AndExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_And );
        AddLastSubRule( $$, $3 );
    }
    |
    ExpressionRule
    TOKEN_TYPE_Or
    ExpressionRule
    {
        $$ = MakeRule( RULE_TYPE_OrExpression );
        AddLastSubRule( $$, $1 );
        AddLastTokenType( $$, TOKEN_TYPE_Or );
        AddLastSubRule( $$, $3 );
    }
    |
    BooleanConstantRule
    {
        $$ = MakeRule( RULE_TYPE_BooleanConstantExpression );
        AddLastSubRule( $$, $1 );
    }
    |
    IntegerConstantRule
    {
        $$ = MakeRule( RULE_TYPE_IntegerConstantExpression );
        AddLastSubRule( $$, $1 );
    }
    |
    OpeningParenthesisToken
    ExpressionRule
    ClosingParenthesisToken
    {
        $$ = MakeRule( RULE_TYPE_ParenthesisExpression );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
    }
    |
    FunctionCallRule
    {
        $$ = MakeRule( RULE_TYPE_FunctionCallExpression );
        AddLastSubRule( $$, $1 );
    }
    |
    VariableExpressionRule
    {
        $$ = $1;
    }
    ;

FunctionParameterRule :

    RefToken
    VariableNameRule
    ColonToken
    VariableTypeRule
    {
        $$ = MakeRule( RULE_TYPE_FunctionParameter );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
        AddLastSubRule( $$, $4 );
    }
    |
    VariableNameRule
    ColonToken
    VariableTypeRule
    {
        $$ = MakeRule( RULE_TYPE_FunctionParameter );
        AddLastSubRule( $$, $1 );
        AddLastToken( $$, $2 );
        AddLastSubRule( $$, $3 );
    }
    ;

NextFunctionParameterRule :

    CommaToken
    FunctionParameterListRule
    {
        $$ = MakeRule( RULE_TYPE_NextFunctionParameter );
        AddLastToken( $$, $1 );
        AddSkippedSubRule( $$, $2 );
    }
    |
    {
        $$ = MakeRule( RULE_TYPE_NextFunctionParameter );
    }
    ;

FunctionParameterListRule :

    FunctionParameterRule
    NextFunctionParameterRule
    {
        $$ = MakeRule( RULE_TYPE_FunctionParameterList );
        AddLastSubRule( $$, $1 );
        AddSkippedSubRule( $$, $2 );
    }
    |
    {
        $$ = MakeRule( RULE_TYPE_FunctionParameterList );
    }
    ;

VariableRule :

    VariableNameRule
    ColonToken
    VariableTypeRule
    {
        $$ = MakeRule( RULE_TYPE_Variable );
        AddLastSubRule( $$, $1 );
        AddLastToken( $$, $2 );
        AddLastSubRule( $$, $3 );
    }
    ;

NextVariableRule :

    CommaToken
    VariableListRule
    {
        $$ = MakeRule( RULE_TYPE_NextVariable );
        AddLastToken( $$, $1 );
        AddSkippedSubRule( $$, $2 );
    }
    |
    {
        $$ = MakeRule( RULE_TYPE_NextVariable );
    }
    ;

VariableListRule :

    VariableRule
    NextVariableRule
    {
        $$ = MakeRule( RULE_TYPE_VariableList );
        AddLastSubRule( $$, $1 );
        AddSkippedSubRule( $$, $2 );
    }
    ;
    
VariableDeclarationRule :

    VarToken
    VariableRule
    NextVariableRule
    SemicolonToken
    {
        $$ = MakeRule( RULE_TYPE_VariableDeclaration );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddSkippedSubRule( $$, $3 );
        AddLastToken( $$, $4 );
    }
    ;

LocalDeclarationRule :

    VariableDeclarationRule
    {
        $$ = MakeRule( RULE_TYPE_LocalDeclaration );
        AddLastSubRule( $$, $1 );
    }
    |
    FunctionDeclarationRule
    {
        $$ = MakeRule( RULE_TYPE_LocalDeclaration );
        AddLastSubRule( $$, $1 );
    }
    ;

LocalDeclarationListRule :

    LocalDeclarationRule
    LocalDeclarationListRule
    {
        $$ = MakeRule( RULE_TYPE_LocalDeclarationList );
        AddLastSubRule( $$, $1 );
        AddSkippedSubRule( $$, $2 );
    }
    |
    {
        $$ = MakeRule( RULE_TYPE_LocalDeclarationList );
    }
    ;

AssignmentStatementRule :

    VariableExpressionRule
    EqualToken
    ExpressionRule
    SemicolonToken
    {
        $$ = MakeRule( RULE_TYPE_AssignmentStatement );
        AddLastSubRule( $$, $1 );
        AddLastToken( $$, $2 );
        AddLastSubRule( $$, $3 );
        AddLastToken( $$, $4 );
    }
    ;

ElseStatementRule :

    ElseToken
    OpeningBraceToken
    StatementListRule
    ClosingBraceToken
    {
        $$ = MakeRule( RULE_TYPE_ElseStatement );
        AddLastToken( $$, $1 );
        AddLastToken( $$, $2 );
        AddLastSubRule( $$, $3 );
        AddLastToken( $$, $4 );
    }
    |
    {
        $$ = MakeRule( RULE_TYPE_ElseStatement );
    }
    ;

IfStatementRule :

    IfToken
    ExpressionRule
    OpeningBraceToken
    StatementListRule
    ClosingBraceToken
    ElseStatementRule
    {
        $$ = MakeRule( RULE_TYPE_IfStatement );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
        AddLastSubRule( $$, $4 );
        AddLastToken( $$, $5 );
        AddLastSubRule( $$, $6 );
    };

WhileStatementRule :

    WhileToken
    ExpressionRule
    OpeningBraceToken
    StatementListRule
    ClosingBraceToken
    {
        $$ = MakeRule( RULE_TYPE_WhileStatement );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
        AddLastSubRule( $$, $4 );
        AddLastToken( $$, $5 );
    }
    ;

ForStatementRule :

    ForToken
    VariableExpressionRule
    EqualToken
    ExpressionRule
    ToToken
    ExpressionRule
    OpeningBraceToken
    StatementListRule
    ClosingBraceToken
    {
        $$ = MakeRule( RULE_TYPE_ForStatement );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
        AddLastSubRule( $$, $4 );
        AddLastToken( $$, $5 );
		AddLastSubRule( $$, $6 );
        AddLastToken( $$, $7 );       
		AddLastSubRule( $$, $8 );
        AddLastToken( $$, $9 );
    }
    ;
	
WriteStatementRule :

    WriteToken
    ExpressionRule
    SemicolonToken
    {
        $$ = MakeRule( RULE_TYPE_WriteStatement );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
    }
    ;

ReadStatementRule :

    ReadToken
    VariableExpressionRule
    SemicolonToken
    {
        $$ = MakeRule( RULE_TYPE_ReadStatement );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
    }
    ;

ReturnStatementRule :

    ReturnToken
    ExpressionRule
    SemicolonToken
    {
        $$ = MakeRule( RULE_TYPE_ReturnStatement );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
    }
    ;

ExpressionStatementRule :

    ExpressionRule
    SemicolonToken
    {
        $$ = MakeRule( RULE_TYPE_ExpressionStatement );
        AddLastSubRule( $$, $1 );
        AddLastToken( $$, $2 );
    }
    ;

StatementRule :

    AssignmentStatementRule
    {
        $$ = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( $$, $1 );
    }
    |
    IfStatementRule
    {
        $$ = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( $$, $1 );
    }
    |
    WhileStatementRule
    {
        $$ = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( $$, $1 );
    }
	|
    ForStatementRule
    {
        $$ = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( $$, $1 );
    }
    |
    WriteStatementRule
    {
        $$ = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( $$, $1 );
    }
    |
    ReadStatementRule
    {
        $$ = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( $$, $1 );
    }
    |
    ReturnStatementRule
    {
        $$ = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( $$, $1 );
    }
    |
    ExpressionStatementRule
    {
        $$ = MakeRule( RULE_TYPE_Statement );
        AddLastSubRule( $$, $1 );
    }
    ;

StatementListRule :

    StatementRule
    StatementListRule
    {
        $$ = MakeRule( RULE_TYPE_StatementList );
        AddLastSubRule( $$, $1 );
        AddSkippedSubRule( $$, $2 );
    }
    |
    {
        $$ = MakeRule( RULE_TYPE_StatementList );
    }
    ;

FunctionBlockRule :

    OpeningBraceToken
    LocalDeclarationListRule
    StatementListRule
    ClosingBraceToken
    {
        $$ = MakeRule( RULE_TYPE_FunctionBlock );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastSubRule( $$, $3 );
        AddLastToken( $$, $4 );
    }
    |
    SemicolonToken
    {
        $$ = MakeRule( RULE_TYPE_FunctionBlock );
        AddLastToken( $$, $1 );
    }
    ;

FunctionDeclarationRule :

    FuncToken
    FunctionNameRule
    OpeningParenthesisToken
    FunctionParameterListRule
    ClosingParenthesisToken
    ColonToken
    FunctionTypeRule
    FunctionBlockRule
    {
        $$ = MakeRule( RULE_TYPE_FunctionDeclaration );
        AddLastToken( $$, $1 );
        AddLastSubRule( $$, $2 );
        AddLastToken( $$, $3 );
        AddLastSubRule( $$, $4 );
        AddLastToken( $$, $5 );
        AddLastToken( $$, $6 );
        AddLastSubRule( $$, $7 );
        AddSkippedSubRule( $$, $8 );
    }
    ;

ProgramRule :

    FunctionDeclarationRule
    {
        $$ = MakeRule( RULE_TYPE_Program );
        AddLastSubRule( $$, $1 );
        Program->Rule = $$;
    }
    ;

%%
