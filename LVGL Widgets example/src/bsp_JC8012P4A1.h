/*******************************************************************************
Created by profi-max (Oleg Linnik) 2026
https://profimaxblog.ru
https://github.com/profi-max

*******************************************************************************/
#pragma once

#include <stdint.h>

#include "esp_err.h"
#include "esp_lcd_types.h"
#include "touch/esp_lcd_touch.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

//#define LCD_H_RES 1280
//#define LCD_V_RES 800

#define LCD_RST 27
#define LCD_LED 23

#define TP_I2C_SDA 7
#define TP_I2C_SCL 8
#define TP_RST 22
#define TP_INT 21


void bsp_lvgl_init(void);


#ifdef __cplusplus
}
#endif