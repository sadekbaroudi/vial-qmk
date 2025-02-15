/*
 * Copyright 2023 Sadek Baroudi <sadekbaroudi@gmail.com> (@sadekbaroudi)
 */

#pragma once

#define HAL_USE_I2C TRUE
#define HAL_USE_PWM TRUE
#define HAL_USE_PAL TRUE
// #define HAL_USE_SERIAL TRUE // not supported on rp2040, as it seems
#define HAL_USE_SPI TRUE

#include_next <halconf.h>
