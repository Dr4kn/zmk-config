/*
    a lot of things are copied or heavily inspired by https://github.com/urob/zmk-config#timeless-homerow-mods
*/
#pragma once

#define QWERTZ_HELPER_STRINGIFY(x) #x

#define QWERTZ_MODMORPH(name, uc_binding, shifted_uc_binding) \
    / { \
        behaviors { \
            name: name { \
                compatible = "zmk,behavior-mod-morph"; \
                label = QWERTZ_HELPER_STRINGIFY(UC_MORPH_ ## name); \
                #binding-cells = <0>; \
                bindings = <&kp uc_binding>, <&kp shifted_uc_binding>; \
                mods = <(MOD_LSFT|MOD_RSFT)>; \
            }; \
        }; \
    };

/*
KEYCODES


NORMAL KEYS

QWRTZ_SEMI
QWRTZ_SQT
QWRTZ_COMMA
QWRTZ_DOT
QWRTZ_FLSH


SYMBOLS ON NUMBER ROW

QWRTZ_AT
QWRTZ_HASH
QWRTZ_CARET
QWRTZ_AMPS
QWRTZ_STAR
QWRTZ_EQUAL
QWRTZ_MINUS
QWRTZ_PLUS


BRACKETS

QWRTZ_LBKT
QWRTZ_RBKT
QWRTZ_LBRC
QWRTZ_RBRC
QWRTZ_LPAR
QWRTZ_RPAR
QWRTZ_FSLH
QWRTZ_BSLH
QWRTZ_TILDE
QWRTZ_UNDER
QWRTZ_SQT
QWRTZ_DQT
QWRTZ_GRAVE
QWRTZ_PIPE
*/



/*
    NORMAL KEYS
*/
// ; and :
QWERTZ_MODMORPH(QWRTZ_SEMI, LS(COMMA), LS(DOT))
// ' and "
QWERTZ_MODMORPH(QWRTZ_SQT, LS(BSLH), LS(N2))
// , and <
QWERTZ_MODMORPH(QWRTZ_COMMA, COMMA, NON_US_BACKSLASH)
// . and >
QWERTZ_MODMORPH(QWRTZ_DOT, DOT, LS(NON_US_BACKSLASH))
// / and ?
QWERTZ_MODMORPH(QWRTZ_FLSH, LS(7), LS(MINUS))
/*
    SYMBOLS ON NUMBER ROW
*/
// ! is the same
// @
#define QWRTZ_AT &kp RA(Q)
// #
#define QWRTZ_HASH &kp NON_US_HASH
// $ is the same
// % is the same
// ^ is the same
// ^
#define QWRTZ_CARET &kp GRAVE
// &
#define QWRTZ_AMPS &kp CARET
// *
#define QWRTZ_STAR &kp LS(RBKT)
// =
#define QWRTZ_EQUAL &kp LS(N0)
// -
#define QWRTZ_MINUS &kp FSLH
// +
#define QWRTZ_PLUS &kp RBKT

/*
    BRACKETS
*/
// [
#define QWRTZ_LBKT &kp RA(N8)
// ]
#define QWRTZ_RBKT &kp RA(N9)
// {
#define QWRTZ_LBRC &kp RA(N7)
// }
#define QWRTZ_RBRC &kp RA(N0)
// (
#define QWRTZ_LPAR &kp LS(N8)
// )
#define QWRTZ_RPAR &kp LS(N9)
// /
#define QWRTZ_FSLH &kp RBKT
// "\"
#define QWRTZ_BSLH &kp RA(MINUS)


/*
    OTHER SYMBOLS
*/
// ~
#define QWRTZ_TILDE &kp LS(NON_US_HASH)
// _
#define QWRTZ_UNDER &kp LS(MINUS)
// '
#define QWRTZ_SQT &kp LS(BSLH)
// "
#define QWRTZ_DQT &kp LS(N2)
// `
#define QWRTZ_GRAVE &kp LS(EQUAL)
// |
#define QWRTZ_PIPE &kp RA(NON_US_BACKSLASH)



