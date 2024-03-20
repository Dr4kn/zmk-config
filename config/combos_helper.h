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
