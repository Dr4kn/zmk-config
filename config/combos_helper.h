#pragma once
/*
    |  0  |  1  |  2  |  3  |  4  |  5  |   |  6  |  7  |  8  |  9  | 10  |  11  |
    | 12  | 13  | 14  | 15  | 16  | 17  |   | 18  | 19  | 20  | 21  | 22  |  23  |
    | 24  | 25  | 26  | 27  | 28  | 29  |   | 30  | 31  | 32  | 33  | 34  |  35  |
                     | 36  | 37  | 38  |   | 39  | 40  | 41  |
Shorterhandels for keyrow mods
    with multiple different layouts you mostly need to change the definitions.
*/

#define COMBO_FAST 20
#define COMBO_SLOW 35

// helper function so that one can use the combo define. Without it the preprocessor wouldn't resolve it
#define SYMBOL_COMBO(name, timeing, keybinding, key_positions, layer) SYM_COMBO(name, timeing, keybinding, key_positions, layer)
#define SYM_COMBO(name, timeing, keybinding, key_positions, layer) \
    / { \
        combos { \
            compatible = "zmk,combos"; \
            name { \
                timeout-ms = <timeing>; \
                key-positions = <key_positions>; \
                bindings = <&kp keybinding>; \
                layers = <layer>; \
            }; \
        }; \
    };

// doesn't work at the moment
// combos on the typing layers for symbols
// SYMBOL_COMBO(lpar,     LPAR,   COMBO_FAST,     15 16,      DEF ALT_C WN_C)
// SYMBOL_COMBO(rpar,     RPAR,   COMBO_FAST,     20 19,      DEF ALT_C WN_C)
// SYMBOL_COMBO(lbrc,     LBRC,   COMBO_FAST,     14 15,      DEF ALT_C WN_C)
// SYMBOL_COMBO(rbrc,     RBRC,   COMBO_FAST,     21 20,      DEF ALT_C WN_C)
// SYMBOL_COMBO(lbkt,     LBKT,   COMBO_FAST,     14 15 16,   DEF ALT_C WN_C)
// SYMBOL_COMBO(rbkt,     RBKT,   COMBO_FAST,     21 20 19,   DEF ALT_C WN_C)
// SYMBOL_COMBO(tilde,    TILDE,  COMBO_FAST,     13 14,      DEF ALT_C WN_C)
// SYMBOL_COMBO(under,    UNDER,  COMBO_FAST,     22 21,      DEF ALT_C WN_C)
// SYMBOL_COMBO(plus,     PLUS,   COMBO_FAST,     25 26,      DEF ALT_C WN_C)
// SYMBOL_COMBO(minus,    MINUS,  COMBO_FAST,     26 27,      DEF ALT_C WN_C)
// SYMBOL_COMBO(equal,    EQUAL,  COMBO_FAST,     27 28,      DEF ALT_C WN_C)
// SYMBOL_COMBO(sqt,      SQT,    COMBO_FAST,     32 31,      DEF ALT_C WN_C)
// SYMBOL_COMBO(grave,    GRAVE,  COMBO_FAST,     33 32,      DEF ALT_C WN_C)
// SYMBOL_COMBO(blsh,     BSLH,   COMBO_FAST,     34 33,      DEF ALT_C WN_C)