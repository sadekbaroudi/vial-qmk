VIA_ENABLE = yes
VIAL_ENABLE = yes
#VIAL_INSECURE = yes
VIAL_ENCODERS_ENABLE = no
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   VIALRGB_ENABLE := yes  # not required, but enabling for mouse button keys
endif
LTO_ENABLE = yes
QMK_SETTINGS = yes
TAP_DANCE_ENABLE = no

