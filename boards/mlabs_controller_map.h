/*
  mlabs_controller_map.h - driver code for STM32F4xx (Blackpill) breakout board

  Part of GrblHAL

  Copyright (c) 2021 rvalotta

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/


#if N_ABC_MOTORS > 2
#error "MLABS Controller supports 5 motors max."
#endif

#define BOARD_NAME "Mlabs Controller"

#define USB_SERIAL_CDC 1
#undef I2C_ENABLE
#undef EEPROM_ENABLE

#define I2C_ENABLE 1
#define I2C_PORT 1
/*
* Tested 24c02, 24c32 => not working
* Tested 24c04, 24c08, 24c256 => working
*/
#define EEPROM_ENABLE 1 

// Enable USART1 on PORTB pin3 for RX, PORTA pin15 for TX
#define SERIAL_MOD 1
#define SERIAL_MOD1_ALT_PINMAP

// Define step pulse output pins.
#define X_STEP_PORT                 GPIOA
#define X_STEP_PIN                  0
#define Y_STEP_PORT                 GPIOA
#define Y_STEP_PIN                  2
#define Z_STEP_PORT                 GPIOA
#define Z_STEP_PIN                  4
#define STEP_OUTMODE                GPIO_BITBAND

// Define step direction output pins.
#define X_DIRECTION_PORT            GPIOA
#define X_DIRECTION_PIN             1
#define Y_DIRECTION_PORT            GPIOA
#define Y_DIRECTION_PIN             3
#define Z_DIRECTION_PORT            GPIOA
#define Z_DIRECTION_PIN             5
#define DIRECTION_OUTMODE           GPIO_BITBAND

// Define stepper driver enable/disable output pin.
#define STEPPERS_ENABLE_PORT        GPIOB
#define STEPPERS_ENABLE_PIN         2
#define STEPPERS_ENABLE_MASK        STEPPERS_ENABLE_BIT

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT                GPIOB
#define X_LIMIT_PIN                 7
#define Y_LIMIT_PORT                GPIOB
#define Y_LIMIT_PIN                 6
#define Z_LIMIT_PORT                GPIOB
#define Z_LIMIT_PIN                 5
#define LIMIT_INMODE                GPIO_BITBAND

// Define ganged axis or A axis step pulse and step direction output pins.

//#define Y_GANGED            1
//#define Y_AUTO_SQUARE       1
//#define Y_GANGED_LIM_MAX    1

#if N_ABC_MOTORS > 0

#define M3_AVAILABLE
#define M3_STEP_PORT                GPIOB//GPIOA
#define M3_STEP_PIN                 0//6
#define M3_DIRECTION_PORT           GPIOB//GPIOA
#define M3_DIRECTION_PIN            1//7
#if N_AUTO_SQUARED
#define M3_LIMIT_PORT               GPIOB
#define M3_LIMIT_PIN                3//4
#define M3_ENABLE_PORT              GPIOB
#define M3_ENABLE_PIN               2
#endif
#endif

#if N_ABC_MOTORS == 2
#define M4_AVAILABLE
#define M4_STEP_PORT                GPIOA//GPIOB
#define M4_STEP_PIN                 6//0
#define M4_DIRECTION_PORT           GPIOA//GPIOB
#define M4_DIRECTION_PIN            7//1
#if N_AUTO_SQUARED
#define M4_LIMIT_PORT               GPIOB
#define M4_LIMIT_PIN                4//3
#define M4_ENABLE_PORT              GPIOB
#define M4_ENABLE_PIN               2
#endif
#endif

#define HAS_IOPORTS
#define AUXINPUT0_PORT              GPIOC
#define AUXINPUT0_PIN               14
#define AUXINPUT1_PORT              GPIOC
#define AUXINPUT1_PIN               13
#define AUXINPUT2_PORT              GPIOA //probe
#define AUXINPUT2_PIN               15

#define AUXOUTPUT0_PORT             GPIOB
#define AUXOUTPUT0_PIN              13
#define AUXOUTPUT1_PORT             GPIOB
#define AUXOUTPUT1_PIN              14
#define AUXOUTPUT2_PORT             GPIOB //spindle enable
#define AUXOUTPUT2_PIN              12
#define AUXOUTPUT3_PORT             GPIOB //spindle PWM
#define AUXOUTPUT3_PIN              10

// Define driver spindle pins
//Disable direction
#undef DRIVER_SPINDLE_DIR_ENABLE
#define DRIVER_SPINDLE_DIR_ENABLE 0

#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PORT     AUXOUTPUT2_PORT
#define SPINDLE_ENABLE_PIN      AUXOUTPUT2_PIN
#if DRIVER_SPINDLE_PWM_ENABLE
#define SPINDLE_PWM_PORT        AUXOUTPUT3_PORT
#define SPINDLE_PWM_PIN         AUXOUTPUT3_PIN
#endif
#if DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_DIRECTION_PORT  AUXOUTPUT4_PORT
#define SPINDLE_DIRECTION_PIN   AUXOUTPUT4_PIN
#endif
#endif //DRIVER_SPINDLE_ENABLE

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOC
#define COOLANT_FLOOD_PIN           15
// #define COOLANT_MIST_PORT           GPIOC
// #define COOLANT_MIST_PIN            14

// Define user-control controls (cycle start, reset, feed hold) input pins.
//#define CONTROL_PORT                GPIOC
#undef RESET_PORT
#define RESET_PORT                  GPIOA
#define RESET_PIN                   14

#undef FEED_HOLD_PORT
#define FEED_HOLD_PORT              GPIOA
#define FEED_HOLD_PIN               8

#undef CYCLE_START_PORT
#define CYCLE_START_PORT            GPIOB
#define CYCLE_START_PIN             15

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN             6
#endif
#define CONTROL_INMODE              GPIO_BITBAND

// Define probe switch input pin.
#undef PROBE_PORT
#define PROBE_PORT                  AUXINPUT2_PORT
#define PROBE_PIN                   AUXINPUT2_PIN




// NOT SUPPORTED
#if KEYPAD_ENABLE
#error Keypad not supported
#endif
// NOT SUPPORTED
#if SDCARD_ENABLE
//#error SDcard not supported
#endif

/* EOF */
