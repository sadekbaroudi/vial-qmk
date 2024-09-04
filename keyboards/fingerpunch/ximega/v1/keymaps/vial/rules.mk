VIA_ENABLE = yes
VIAL_ENABLE = yes
#VIAL_INSECURE = yes
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   VIALRGB_ENABLE := yes  # not required, but enabling for mouse button keys
endif
LTO_ENABLE = yes
QMK_SETTINGS = yes
