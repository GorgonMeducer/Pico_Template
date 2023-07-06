/****************************************************************************
*  Copyright 2023 Gorgon Meducer (Email:embedded_zhuoran@hotmail.com)       *
*                                                                           *
*  Licensed under the Apache License, Version 2.0 (the "License");          *
*  you may not use this file except in compliance with the License.         *
*  You may obtain a copy of the License at                                  *
*                                                                           *
*     http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                           *
*  Unless required by applicable law or agreed to in writing, software      *
*  distributed under the License is distributed on an "AS IS" BASIS,        *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
*  See the License for the specific language governing permissions and      *
*  limitations under the License.                                           *
*                                                                           *
****************************************************************************/
/*============================ INCLUDES ======================================*/
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#ifndef __RP2040_BSP_H__
#define __RP2040_BSP_H__

#if defined(__PICO_USE_LCD_1IN3__) && __PICO_USE_LCD_1IN3__
#   include "./pico_lcd_1in3/Config/Dev_Config.h"
#   include "./pico_lcd_1in3/LCD/LCD_1In3.h"
#   include "./pico_lcd_1in3/GLCD_Config.h"
#else
#endif

/*============================ MACROS ========================================*/


#if defined(__PICO_USE_LCD_1IN3__) && __PICO_USE_LCD_1IN3__


#else


#   define __PICO_USE_STANDARD__        1
#endif

/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/

extern void bsp_init(void);

extern void breath_led(void);




#endif
