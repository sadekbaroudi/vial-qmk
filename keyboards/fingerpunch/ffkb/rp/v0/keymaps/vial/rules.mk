VIA_ENABLE = yes
VIAL_ENABLE = yes
#VIAL_INSECURE = yes
ifeq ($(strip $(ENCODER_ENABLE)), yes)
  ENCODER_MAP_ENABLE = yes
  VIAL_ENCODERS_ENABLE = yes
endif
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   VIALRGB_ENABLE := yes  # not required, but enabling for mouse button keys
endif
QMK_SETTINGS = yes
