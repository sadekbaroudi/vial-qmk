# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

# Either do RGBLIGHT_ENABLE or RGB_MATRIX_ENABLE and RGB_MATRIX_DRIVER
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = no
OLED_ENABLE = no            # this can be yes or no depending on if you have an OLED
EXTRAFLAGS     += -flto     # macros disabled, as a lot of barobord features require more space, can move this line into all the individual rules.mk, only where needed
                            # for instance, if you build "no_features", it's very unlikely you'll need to disable macros
MOUSEKEY_ENABLE = no

PIMORONI_TRACKBALL_ENABLE = no

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    POINTING_DEVICE_DRIVER := pimoroni_trackball
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
endif

ifeq ($(strip $(FP_EC11_CENTER)), yes)
   ENCODER_ENABLE := yes
   OPT_DEFS += -DFP_EC11_CENTER
endif

ifeq ($(strip $(FP_EC11_UNDER_PALMS)), yes)
   ENCODER_ENABLE := yes
   OPT_DEFS += -DFP_EC11_UNDER_PALMS
endif

ifeq ($(strip $(FP_EVQ_UNDER_PALMS)), yes)
   ENCODER_ENABLE := yes
   OPT_DEFS += -DFP_EVQ_UNDER_PALMS
endif
