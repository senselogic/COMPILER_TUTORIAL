#ifndef __CODE__
    #define __CODE__

    // -- IMPORTS

    #include "string.h"
    struct _TEXT;

    // -- TYPES

    typedef struct _CODE
    {
        struct _TEXT
            * FirstText,
            * LastText;
    } CODE;

    // -- IMPORTS

    #include "function.h"
    #include "rule.h"
    #include "text.h"
    #include "value_type.h"
    #include "variable.h"

    // -- FUNCTIONS

    CODE * MakeCode(
        void
        );

    // ~~

    void FreeCode(
        CODE * code
        );

    // ~~

    void PrintCode(
        const CODE * code
        );

    // ~~

    void AddLastTexts(
        CODE * code,
        TEXT * first_last_text,
        TEXT * last_last_text
        );

    // ~~

    void AddCodeText(
        CODE * code,
        CODE * last_code
        );

    // ~~

    void AddText(
        CODE * code,
        const STRING string
        );

    // ~~

    void AddText2(
        CODE * code,
        const STRING first_string,
        const STRING second_string
        );

    // ~~

    void AddText3(
        CODE * code,
        const STRING first_string,
        const STRING second_string,
        const STRING third_string
        );

    // ~~

    void AddIntegerText(
        CODE * code,
        const int integer
        );

    // ~~

    void AddIntegerText2(
        CODE * code,
        const STRING first_string,
        const int integer
        );

    // ~~

    void AddIntegerText3(
        CODE * code,
        const STRING first_string,
        const int integer,
        const STRING last_string
        );

    // ~~

    void AddFunctionIdentifierText(
        CODE * code,
        const FUNCTION * function
        );


    // ~~

    void AddFunctionIdentifierText2(
        CODE * code,
        const STRING first_string,
        const FUNCTION * function
        );

    // ~~

    void AddFunctionIdentifierText3(
        CODE * code,
        const STRING first_string,
        const FUNCTION * function,
        const STRING last_string
        );

    // ~~

    void AddValueTypeText(
        CODE * code,
        const VALUE_TYPE value_type
        );

    // ~~

    void AddValueTypeText2(
        CODE * code,
        const STRING first_string,
        const VALUE_TYPE value_type
        );

    // ~~

    void AddValueTypeText3(
        CODE * code,
        const STRING first_string,
        const VALUE_TYPE value_type,
        const STRING last_string
        );

    // ~~

    void AddVariableAddressText(
        CODE * code,
        const VARIABLE * variable,
        const FUNCTION * function
        );

    // ~~

    void AddVariableValueText(
        CODE * code,
        const VARIABLE * variable,
        const FUNCTION * function
        );

    // ~~

    void AddRuleLocationText(
        CODE * code,
        const RULE * rule
        );

    // ~~

    void AddRuleLocationText2(
        CODE * code,
        const STRING first_string,
        const RULE * rule
        );

    // ~~

    void AddRuleLocationText3(
        CODE * code,
        const STRING first_string,
        const RULE * rule,
        const STRING last_string
        );

    // ~~

    void AddRuleText(
        CODE * code,
        const RULE * rule,
        int token_count
        );

    // ~~

    void AddRuleText2(
        CODE * code,
        const STRING first_string,
        const RULE * rule,
        int token_count
        );

    // ~~

    void AddRuleText3(
        CODE * code,
        const STRING first_string,
        const RULE * rule,
        int token_count,
        const STRING last_string
        );
#endif
