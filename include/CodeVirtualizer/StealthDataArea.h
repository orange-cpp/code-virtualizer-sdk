/*****************************************************************************
; Header: StealthDataArea.h
; Description: Header to create a "dummy" data area to insert the protection 
;              code
;****************************************************************************/


/******************************************************************************
;                                Defines
;*****************************************************************************/

#define STEALTH_DATA_AREA(wordcount) \
    typedef struct { \
        uint32_t start[4]; \
        uint32_t stealth[wordcount]; \
        uint32_t end[4]; \
    } __stealthmarker_t; \
    \
    __stealthmarker_t __stealthmarker = { \
        { 0xa1a2a3a4, 0xa4a3a2a1, 0xb1a1b2a2, 0xb8a8a1a1 }, \
        { 0 }, \
        { 0xb6b5b3b6, 0xa2b2c2d2, 0xa9a8a2a2, 0xa0a9b9b8 } \
    };

#define REFERENCE_STEALTH_DATA_AREA __stealthmarker.stealth[0] = 1