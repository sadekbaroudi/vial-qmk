#define EECONFIG_KB_DATA_SIZE 8

// If we're using a pointing device, define the PMW CPI just in case
#ifdef POINTING_DEVICE_ENABLE
#define PMW33XX_CPI 1000
#endif