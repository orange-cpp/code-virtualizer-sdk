//
// Created by Orange on 11/7/2024.
//
#pragma once
#include <CodeVirtualizer/VirtualizerSDK.h>
#ifdef _MSC_VER
#   define CV_MACROS_FORCEINLINE __forceinline
#else
#   define CV_MACROS_FORCEINLINE __attribute__((always_inline)) inline
#endif


#define CV_MAKE_MACROS_GUARD_DEF(name) \
class MarcosGuard##name \
{ \
    public: \
    CV_MACROS_FORCEINLINE MarcosGuard##name() \
    {\
         VIRTUALIZER_##name##_START\
    }\
\
    CV_MACROS_FORCEINLINE ~MarcosGuard##name() \
    {\
        VIRTUALIZER_##name##_END\
    }\
};

namespace CodeVirtualizer
{
    CV_MAKE_MACROS_GUARD_DEF(TIGER_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(TIGER_RED)
    CV_MAKE_MACROS_GUARD_DEF(TIGER_BLACK)

    // Fish
    CV_MAKE_MACROS_GUARD_DEF(FISH_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(FISH_RED)
    CV_MAKE_MACROS_GUARD_DEF(FISH_BLACK)

    // Puma
    CV_MAKE_MACROS_GUARD_DEF(PUMA_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(PUMA_RED)
    CV_MAKE_MACROS_GUARD_DEF(PUMA_BLACK)

    // Shark
    CV_MAKE_MACROS_GUARD_DEF(SHARK_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(SHARK_RED)
    CV_MAKE_MACROS_GUARD_DEF(SHARK_BLACK)

    // Dolphin
    CV_MAKE_MACROS_GUARD_DEF(DOLPHIN_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(DOLPHIN_RED)
    CV_MAKE_MACROS_GUARD_DEF(DOLPHIN_BLACK)

    // Eagle
    CV_MAKE_MACROS_GUARD_DEF(EAGLE_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(EAGLE_RED)
    CV_MAKE_MACROS_GUARD_DEF(EAGLE_BLACK)

    // Lion
    CV_MAKE_MACROS_GUARD_DEF(LION_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(LION_RED)
    CV_MAKE_MACROS_GUARD_DEF(LION_BLACK)

    // Cobra
    CV_MAKE_MACROS_GUARD_DEF(COBRA_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(COBRA_RED)
    CV_MAKE_MACROS_GUARD_DEF(COBRA_BLACK)

    // Wolf
    CV_MAKE_MACROS_GUARD_DEF(WOLF_WHITE)
    CV_MAKE_MACROS_GUARD_DEF(WOLF_RED)
    CV_MAKE_MACROS_GUARD_DEF(WOLF_BLACK)

    // Special types
    CV_MAKE_MACROS_GUARD_DEF(MUTATE_ONLY)
    CV_MAKE_MACROS_GUARD_DEF(FALCON_TINY)
}

// Main Macro for Creating Unique Guard Macros
#define CV_PLACE_GUARD_MACROS(name) CV_PLACE_GUARD_MACROS_IMPL(name, __COUNTER__)

// Helper Macro for Implementing the Unique Guard Macros
#define CV_PLACE_GUARD_MACROS_IMPL(name, index) CV_PLACE_GUARD_MACROS_IMPL2(name, index)

// Additional Level of Indirection to Force Expansion
#define CV_PLACE_GUARD_MACROS_IMPL2(name, index) CodeVirtualizer::MarcosGuard##name cv_guard##index;

