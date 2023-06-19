/*
    a lot of things are copied or heavily inspired by https://github.com/urob/zmk-config#timeless-homerow-mods
*/
#pragma once
#include "keys_helper.h"


#define UNICODE_COMBO_TIMEOUT 150 // ca. 10500/(relaxed typing speed)

// key presses to activate unicode entry on the operating systems
#define LINUX_UNICODE_LEAD &macro_tap &kp LS(LC(U))
#define LINUX_UNICODE_TRAIL &macro_tap &kp SPACE
// needs windows compose to work
#define COMPOSE_UNICODE_LEAD &macro_tap &kp RALT &kp U
#define COMPOSE_UNICODE_TRAIL &macro_tap &kp RET
// macOS and Windows-Alt-Codes
#define ALT_CODE_LEAD &macro_press &kp LALT
#define ALT_CODE_TRAIL &macro_release &kp LALT

#define UNICODE_EURO &kp N2 &kp N0 &kp A &kp C

#define ZMK_HELPER_STRINGIFY(x) #x

#define UC_MACRO(name, unicode_lead, unicode_bindings, unicode_trail) \
    / { \
        macros { \
            name: name { \
                compatible = "zmk,behavior-macro"; \
                label = ZMK_HELPER_STRINGIFY(UC_MACRO_ ## name); \
                wait-ms = <0>; \
                tap-ms = <0>; \
                #binding-cells = <0>; \
                bindings  \
                    = <unicode_lead> \
                    , <&macro_tap unicode_bindings> \
                    , <unicode_trail> \
                    ; \
            }; \
        }; \
    };

#define UC_MODMORPH(name, uc_binding, shifted_uc_binding) \
    / { \
        behaviors { \
            name: name { \
                compatible = "zmk,behavior-mod-morph"; \
                label = ZMK_HELPER_STRINGIFY(UC_MORPH_ ## name); \
                #binding-cells = <0>; \
                bindings = <uc_binding>, <shifted_uc_binding>; \
                mods = <(MOD_LSFT|MOD_RSFT)>; \
            }; \
        }; \
    };


#define UC_COMBO(name, key_position_one, key_position_two, layer) \
    / { \
        combos { \
            compatible = "zmk,combos"; \
            name { \
                timeout-ms = <UNICODE_COMBO_TIMEOUT>; \
                key-positions = <key_position_one key_position_two>; \
                bindings = <&name>; \
                layers = <layer>; \
            }; \
        }; \
    };

#define ZMK_UNICODE_PAIR(name, unicode_lead, unicode_trail, L0, L1, L2, L3, U0, U1, U2, U3) \
    UC_MACRO(name ## _lower, unicode_lead, &kp L0 &kp L1 &kp L2 &kp L3, unicode_trail) \
    UC_MACRO(name ## _upper, unicode_lead, &kp U0 &kp U1 &kp U2 &kp U3, unicode_trail) \
    UC_MODMORPH(name, &name ## _lower, &name ## _upper)

// German umlauts in Unicode for Linux
ZMK_UNICODE_PAIR(   ln_ae, LINUX_UNICODE_LEAD, LINUX_UNICODE_TRAIL, N0, N0,  E, N4,    N0, N0,  C, N4)
ZMK_UNICODE_PAIR(   ln_oe, LINUX_UNICODE_LEAD, LINUX_UNICODE_TRAIL, N0, N0,  F, N6,    N0, N0,  D, N6)
ZMK_UNICODE_PAIR(   ln_ue, LINUX_UNICODE_LEAD, LINUX_UNICODE_TRAIL, N0, N0,  F,  C,    N0, N0,  D,  C)
ZMK_UNICODE_PAIR(   ln_sz, LINUX_UNICODE_LEAD, LINUX_UNICODE_TRAIL, N0, N0,  D,  F,    N1, E,  N9,  E)

// For Windows-Alt-Codes
ZMK_UNICODE_PAIR(   wna_ae, ALT_CODE_LEAD, ALT_CODE_TRAIL, KP_N0, KP_N2, KP_N2, KP_N8,    KP_N0, KP_N1, KP_N9, KP_N6)
ZMK_UNICODE_PAIR(   wna_oe, ALT_CODE_LEAD, ALT_CODE_TRAIL, KP_N0, KP_N2, KP_N4, KP_N6,    KP_N0, KP_N2, KP_N1, KP_N4)
ZMK_UNICODE_PAIR(   wna_ue, ALT_CODE_LEAD, ALT_CODE_TRAIL, KP_N0, KP_N2, KP_N5, KP_N2,    KP_N0, KP_N2, KP_N2, KP_N0)
ZMK_UNICODE_PAIR(   wna_sz, ALT_CODE_LEAD, ALT_CODE_TRAIL, KP_N0, KP_N2, KP_N2, KP_N3,    KP_N7, KP_N8, KP_N3, KP_N8)

// German umlauts in Unicode for Windows Compose
ZMK_UNICODE_PAIR(   wnc_ae, COMPOSE_UNICODE_LEAD, COMPOSE_UNICODE_TRAIL, N0, N0,  E, N4,    N0, N0,  C, N4)
ZMK_UNICODE_PAIR(   wnc_oe, COMPOSE_UNICODE_LEAD, COMPOSE_UNICODE_TRAIL, N0, N0,  F, N6,    N0, N0,  D, N6)
ZMK_UNICODE_PAIR(   wnc_ue, COMPOSE_UNICODE_LEAD, COMPOSE_UNICODE_TRAIL, N0, N0,  F,  C,    N0, N0,  D,  C)
ZMK_UNICODE_PAIR(   wnc_sz, COMPOSE_UNICODE_LEAD, COMPOSE_UNICODE_TRAIL, N0, N0,  D,  F,    N1, E,  N9,  E)

UC_COMBO(ln_ae, UC_A, UC_E, SYM)
UC_COMBO(ln_oe, UC_O, UC_E, SYM)
UC_COMBO(ln_ue, UC_U, UC_E, SYM)
UC_COMBO(ln_sz, UC_S, UC_Z, SYM)

UC_COMBO(wna_ae, UC_A, UC_E, ALT_C)
UC_COMBO(wna_oe, UC_O, UC_E, ALT_C)
UC_COMBO(wna_ue, UC_U, UC_E, ALT_C)
UC_COMBO(wna_sz, UC_S, UC_Z, ALT_C)

UC_COMBO(wnc_ae, UC_A, UC_E, WN_C)
UC_COMBO(wnc_oe, UC_O, UC_E, WN_C)
UC_COMBO(wnc_ue, UC_U, UC_E, WN_C)
UC_COMBO(wnc_sz, UC_S, UC_Z, WN_C)
