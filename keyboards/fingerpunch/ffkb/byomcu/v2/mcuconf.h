#pragma once

#include_next "mcuconf.h"

#undef STM32_ST_USE_TIMER
#define STM32_ST_USE_TIMER 5

#undef STM32_GPT_USE_TIM4
#define STM32_GPT_USE_TIM4 TRUE

#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE
