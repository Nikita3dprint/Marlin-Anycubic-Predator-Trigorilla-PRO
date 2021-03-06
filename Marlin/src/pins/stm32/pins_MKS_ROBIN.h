/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin (STM32F130ZET6) board pin assignments
 *
 * https://github.com/makerbase-mks/MKS-Robin/tree/master/MKS%20Robin/Hardware
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#elif HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS Robin supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "MKS Robin"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_JTAG

//#define SLOW_SOFT_I2C_MASTER_H
//#define I2C_EEPROM   // AT24C64
//#define E2END 0x7FFF // 64KB
//#define FLASH_EEPROM_EMULATION
//#define E2END 0xFFF // 4KB
//#define E2END uint32(EEPROM_START_ADDRESS + (EEPROM_PAGE_SIZE * 2) - 1)
//#define EEPROM_CHITCHAT
#define DEBUG_EEPROM_READWRITE

//
// Servos
//
//#define SERVO0_PIN         PC3   // XS1 - 5
//#define SERVO1_PIN         PA1   // XS1 - 6
//#define SERVO2_PIN         PF9   // XS2 - 5
//#define SERVO3_PIN         PF8   // XS2 - 6

//
// Limit Switches

//#define X_MIN_PIN          PG10 //ok
//#define Y_MIN_PIN          PA12 //ok
//#define Z_MAX_PIN          PA13 //ok
//#define Z_MIN_PIN          PA14 //ok

#define X_MAX_PIN          PG10 //ok
#define Y_MAX_PIN          PA12 //ok
#define Z_MAX_PIN          PA14 //ok
#define Z_MIN_PIN          PA13 //ok

//
// Steppers
//
#define X_ENABLE_PIN       PC13
#define X_STEP_PIN         PE5
#define X_DIR_PIN          PE6

#define Y_ENABLE_PIN       PE4
#define Y_STEP_PIN         PE2
#define Y_DIR_PIN          PE3

#define Z_ENABLE_PIN       PE1
#define Z_STEP_PIN         PB9
#define Z_DIR_PIN          PE0

#define E0_ENABLE_PIN      PB8
#define E0_STEP_PIN        PB4
#define E0_DIR_PIN         PB5

#define E1_ENABLE_PIN      PG8
#define E1_STEP_PIN        PC7
#define E1_DIR_PIN         PC6

//
// Temperature Sensors
//
#define TEMP_0_PIN         PA1   // TH1
#define TEMP_BED_PIN       PA0   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN       PG12   // HEATER1
#define HEATER_BED_PIN     PG11   // HOT BED
#define HEATER_BED_INVERTING true
#define CONTROLLER_FAN_PIN PD6   // FAN ok
#define E0_AUTO_FAN_PIN    PG14  // FAN ok
#define FAN_PIN            PG13  // FAN ok

#define POWER_LOSS_PIN     PA2   // PW_DET
#define PS_ON_PIN          PA3   // PW_OFF
#define FIL_RUNOUT_PIN     PA15  // MT_DET ok

#define BEEPER_PIN         PB0  //ok
#define LED_PIN            PD3  //ok

/**
 * Note: MKS Robin TFT screens use various TFT controllers
 * Supported screens are based on the ILI9341, ST7789V and ILI9328 (320x240)
 * ILI9488 is not supported
 * Define init sequences for other screens in u8g_dev_tft_320x240_upscale_from_128x64.cpp
 *
 * If the screen stays white, disable 'LCD_RESET_PIN'
 * to let the bootloader init the screen.
 *
 * Setting an 'LCD_RESET_PIN' may cause a flicker when entering the LCD menu
 * because Marlin uses the reset as a failsafe to revive a glitchy LCD.
 */
#define LCD_RESET_PIN      PF11
#define LCD_BACKLIGHT_PIN  PD13
#define FSMC_CS_PIN        PD7  // NE4
#define FSMC_RS_PIN        PD11  // A0

#define LCD_USE_DMA_FSMC   // Use DMA transfers to send data to the TFT
#define FSMC_DMA_DEV       DMA2
#define FSMC_DMA_CHANNEL   DMA_CH5

#if ENABLED(TOUCH_BUTTONS)
  #define TOUCH_CS_PIN     PB7   // SPI2_NSS
  #define TOUCH_SCK_PIN    PA5  // SPI2_SCK
  #define TOUCH_MISO_PIN   PA6  // SPI2_MISO
  #define TOUCH_MOSI_PIN   PA7  // SPI2_MOSI
#endif

// SPI1(PA7) & SPI3(PB5) not available
#define ENABLE_SPI2

#if ENABLED(SDIO_SUPPORT)
  #define SCK_PIN           PB13 // SPI2 ok
  #define MISO_PIN          PB14 // SPI2 ok
  #define MOSI_PIN          PB15 // SPI2 ok
  #define SS_PIN            PC11   // PB12 is X- ok
  #define SD_DETECT_PIN     -1 // SD_CD ok
#else
  // SD as custom software SPI (SDIO pins)
  #define SCK_PIN           PC12
  #define MISO_PIN          PC8
  #define MOSI_PIN          PD2
  #define SS_PIN            -1
  #define ONBOARD_SD_CS_PIN PC11
  #define SDSS              PD2
  #define SD_DETECT_PIN     -1
#endif
