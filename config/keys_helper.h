// bluetooth short handels
#pragma once

#define BT1 BT_SEL 0
#define BT2 BT_SEL 1
#define BT3 BT_SEL 2
#define BT4 BT_SEL 3
#define BT5 BT_SEL 4
#define BTC BT_CLR

/*
    |  0  |  1  |  2  |  3  |  4  |  5  |   |  6  |  7  |  8  |  9  | 10  |  11  |
    | 12  | 13  | 14  | 15  | 16  | 17  |   | 18  | 19  | 20  | 21  | 22  |  23  |
    | 24  | 25  | 26  | 27  | 28  | 29  |   | 30  | 31  | 32  | 33  | 34  |  35  |
                     | 36  | 37  | 38  |   | 39  | 40  | 41  |
Shorterhandels for keyrow mods
    with multiple different layouts you mostly need to change the definitions.
*/
#define L1 0 1 2 3 4 5
#define L2 12 13 14 15 16 17
#define L3 24 25 26 27 28 29

#define R1 6 7 8 9 10 11
#define R2 18 19 20 21 22 23
#define R3 30 31 32 33 34 35

#define TL 36 37 38
#define TR 39 40 41

#define LSIDE L1 L2 L3
#define RSIDE R1 R2 R3
#define THUMBS TL TR

// homerows in the layout
#define LHR L2
#define RHR R2

// keycodes used in unicode combos
#define UC_A 13
#define UC_O 9
#define UC_U 7
#define UC_E 3
#define UC_S 14
#define UC_Z 25
