VIA_ENABLE = yes
VIAL_ENABLE = yes
#VIAL_INSECURE = yes
VIAL_ENCODERS_ENABLE = yes
ENCODER_MAP_ENABLE = yes
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   VIALRGB_ENABLE := yes  # not required, but enabling for mouse button keys
endif
LTO_ENABLE = yes
QMK_SETTINGS = yes
CASEMODES_ENABLE = yes

ifeq ($(strip $(CASEMODES_ENABLE)), yes)
	OPT_DEFS += -DCASEMODES_ENABLE
    SRC += users/sadekbaroudi/casemodes.c
endif
