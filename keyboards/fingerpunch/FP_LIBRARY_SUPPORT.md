# Adding fingerpunch feature support

The purpose of this doc is mostly to make note to myself on adding the fingerpunch library support, as described in the README.md in this directory.

That said, if you are looking to leverage the features, you may be able to follow these steps for your keyboard as well. Note that this is untested.

## Required additions to the keyboard codebase

1. Add the following line to your keyboard {keyboard_name}.h file, e.g. ffkb_byomcu.h

`#include "keyboards/fingerpunch/src/fp.h"`

2. Include the source files in your keyboard's `rules.mk` file

Note that below is an example. You should check for the latest version of this code block as found in `keyboards/fingerpunch/ffkb_byomcu/rules.mk`

### General file inclusion for feature support

```make
DEFERRED_EXEC_ENABLE = yes
SRC +=  keyboards/fingerpunch/src/fp.c \
        keyboards/fingerpunch/src/fp_haptic.c \
        keyboards/fingerpunch/src/fp_audio.c \
        keyboards/fingerpunch/src/fp_keyhandler.c \
        keyboards/fingerpunch/src/fp_encoder.c \
        keyboards/fingerpunch/src/fp_pointing.c \
        keyboards/fingerpunch/src/fp_rgb_common.c \
        keyboards/fingerpunch/src/fp_rgblight.c \
        keyboards/fingerpunch/src/fp_rgb_matrix.c

```

### Custom config.h

Add this to the keyboard's config.h to allow for custom fingerpunch config.h inclusions
`#include "keyboards/fingerpunch/src/config.h"`

### Audio startup sound

Take a look at `keyboards/fingerpunch/src/fp_audio.c`, and you'll note some startup sounds. Copy those into the `#ifdef AUDIO_ENABLE` section of your config.h and add them in.
For an example, see `keyboards/fingerpunch/ximi/config.h`, which uses the `FP_STARTUP_LIGHT` song

```c
#define FP_STARTUP_LIGHT HALF_NOTE(_E6), HALF_NOTE(_F6), HALF_NOTE(_C6), WHOLE_NOTE(_A5), WHOLE_DOT_NOTE(_F5),
#define FP_STARTUP_LIGHT_EXT HALF_NOTE(_E6), HALF_NOTE(_F6), HALF_NOTE(_C6), WHOLE_NOTE(_A5), WHOLE_DOT_NOTE(_F5), WHOLE_DOT_NOTE(_D5), WHOLE_DOT_NOTE(_G5), WHOLE_DOT_NOTE(_C5),
#define FP_STARTUP_DARK  HALF_DOT_NOTE(_B5), QUARTER_NOTE(_B5), HALF_NOTE(_E6), HALF_NOTE(_REST), QUARTER_NOTE(_C6), QUARTER_NOTE(_REST), QUARTER_NOTE(_G5), QUARTER_NOTE(_E5), QUARTER_NOTE(_F5), QUARTER_NOTE(_GS5), QUARTER_NOTE(_G5), QUARTER_NOTE(_F5), WHOLE_NOTE(_G5),
```

### Shared RGB effects

Add the general effect inclusion file

```C
// For RGB_MATRIX enabled boards, Create the file rgb_matrix_kb.inc in your keyboard directory, and put this code in the file

#include "keyboards/fingerpunch/src/rgb_matrix_effects/alpha_mod_homerow.inc"
#include "keyboards/fingerpunch/src/rgb_matrix_effects/alpha_mod_homerow_cycle.inc"
// There are more effects, add as many as you like
```

Make sure the  RGB_MATRIX_CUSTOM_KB is defined in rules.mk

```make
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   RGB_MATRIX_CUSTOM_KB = yes
   OPT_DEFS += -DRGB_MATRIX_CUSTOM_KB
endif
```

Note that you have to set the homerow values to 12 to support some of the features, see example below from `fingerpunch/fpm101/fpm101.c`

```C
}, {
    1, 4,  4,  4,  4,  4, 1,
    4, 4,  4,  4,  4,  1,
    1, 12, 12, 12, 12, 4, 1,
    1, 4,  4,  4,  4,  4, 1,
    1, 1,  1,  1,
    1, 1,  1,
    1, 1,  1,  1,
    1, 4,  4,  4,  4,  4,  1,
    1, 4,  12, 12, 12, 12, 1,
    1, 4,  4,  4,  4,  4,
    1, 4,  4,  4,  4,  4,  1
} };
```

## Personal notes for Sadek's keymaps

* Add the following to my keymap
    * `FP_SCROLL_TOG` (pointing)
    * `FP_SNIPE_TOG` (pointing)
    * `FP_ZOOM_TOG` (pointing)
    * `FP_SUPER_TAB` (replace `S_ALT_TAB` if it exists)
* Change keymap mouse layer for pointing keyboards with pointing devices
    * `__________________MOUSE_1__________________` to `_______________AUTO_MOUSE_1________________`
* Add the keyboard to my personal userspace `process_records.h` so that I can continue to use my own keycodes in addition to fingerpunch ones

```C
// Check to see which keyboard you're using, and define the PLACEHOLDER_SAFE_RANGE based on that.
#if defined(KEYBOARD_fingerpunch_arachnophobe) \
    || defined(KEYBOARD_fingerpunch_barobord) \
    || defined(KEYBOARD_fingerpunch_barobord_byomcu) \
    || defined(KEYBOARD_fingerpunch_bgkeeb) \
    || defined(KEYBOARD_fingerpunch_bigbarobord) \
    || defined(KEYBOARD_fingerpunch_euclid36) \
    || defined(KEYBOARD_fingerpunch_euclid36_proto) \
    || defined(KEYBOARD_fingerpunch_ffkb) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v2) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v3) \
    || defined(KEYBOARD_fingerpunch_luakeeb) \
    || defined(KEYBOARD_fingerpunch_pinkiesout) \
    || defined(KEYBOARD_fingerpunch_rockon_v1) \
    || defined(KEYBOARD_fingerpunch_rockon_v2) \
    || defined(KEYBOARD_fingerpunch_rockon_bp) \
    || defined(KEYBOARD_fingerpunch_sweeeeep) \
    || defined(KEYBOARD_fingerpunch_ximi)
#    define PLACEHOLDER_SAFE_RANGE FP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif
```
