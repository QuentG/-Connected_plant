/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2016, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */
#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#include "cmsis.h"
#include "PinNamesTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    PA_0  = 0x00,
    PA_1  = 0x01,
    PA_2  = 0x02,
    PA_3  = 0x03,
    PA_4  = 0x04,
    PA_5  = 0x05,
    PA_6  = 0x06,
    PA_7  = 0x07,
    PA_8  = 0x08,
    PA_9  = 0x09,
    PA_10 = 0x0A,
    PA_11 = 0x0B,
    PA_12 = 0x0C,
    PA_13 = 0x0D,
    PA_14 = 0x0E,
    PA_15 = 0x0F,

    PB_0  = 0x10,
    PB_1  = 0x11,
    PB_2  = 0x12,
    PB_3  = 0x13,
    PB_4  = 0x14,
    PB_5  = 0x15,
    PB_6  = 0x16,
    PB_7  = 0x17,
    PB_8  = 0x18,
    PB_9  = 0x19,
    PB_10 = 0x1A,
    PB_11 = 0x1B,
    PB_12 = 0x1C,
    PB_13 = 0x1D,
    PB_14 = 0x1E,
    PB_15 = 0x1F,

    PC_0  = 0x20,
    PC_1  = 0x21,
    PC_2  = 0x22,
    PC_3  = 0x23,
    PC_4  = 0x24,
    PC_5  = 0x25,
    PC_6  = 0x26,
    PC_7  = 0x27,
    PC_8  = 0x28,
    PC_9  = 0x29,
    PC_10 = 0x2A,
    PC_11 = 0x2B,
    PC_12 = 0x2C,
    PC_13 = 0x2D,
    PC_14 = 0x2E,
    PC_15 = 0x2F,

    PD_0  = 0x30,
    PD_1  = 0x31,
    PD_2  = 0x32,
    PD_3  = 0x33,
    PD_4  = 0x34,
    PD_5  = 0x35,
    PD_6  = 0x36,
    PD_7  = 0x37,
    PD_8  = 0x38,
    PD_9  = 0x39,
    PD_10 = 0x3A,
    PD_11 = 0x3B,
    PD_12 = 0x3C,
    PD_13 = 0x3D,
    PD_14 = 0x3E,
    PD_15 = 0x3F,

    PE_0  = 0x40,
    PE_1  = 0x41,
    PE_2  = 0x42,
    PE_3  = 0x43,
    PE_4  = 0x44,
    PE_5  = 0x45,
    PE_6  = 0x46,
    PE_7  = 0x47,
    PE_8  = 0x48,
    PE_9  = 0x49,
    PE_10 = 0x4A,
    PE_11 = 0x4B,
    PE_12 = 0x4C,
    PE_13 = 0x4D,
    PE_14 = 0x4E,
    PE_15 = 0x4F,

    PF_0  = 0x50,
    PF_1  = 0x51,
    PF_2  = 0x52,
    PF_3  = 0x53,
    PF_4  = 0x54,
    PF_5  = 0x55,
    PF_6  = 0x56,
    PF_7  = 0x57,
    PF_8  = 0x58,
    PF_9  = 0x59,
    PF_10 = 0x5A,
    PF_11 = 0x5B,
    PF_12 = 0x5C,
    PF_13 = 0x5D,
    PF_14 = 0x5E,
    PF_15 = 0x5F,

    PG_0  = 0x60,
    PG_1  = 0x61,
    PG_2  = 0x62,
    PG_3  = 0x63,
    PG_4  = 0x64,
    PG_5  = 0x65,
    PG_6  = 0x66,
    PG_7  = 0x67,
    PG_8  = 0x68,
    PG_9  = 0x69,
    PG_10 = 0x6A,
    PG_11 = 0x6B,
    PG_12 = 0x6C,
    PG_13 = 0x6D,
    PG_14 = 0x6E,
    PG_15 = 0x6F,

    PH_0  = 0x70,
    PH_1  = 0x71,
    PH_3  = 0x73,

    // ADC internal channels
    ADC_TEMP = 0xF0,
    ADC_VREF = 0xF1,
    ADC_VBAT = 0xF2,

#if MBED_CONF_TARGET_ARDUINO_ON_J3
    // Arduino on J3 connector namings
    A0          = PF_6,
    A1          = PF_7,
    A2          = PF_8,
    A3          = PF_9,
    A4          = PG_13, // No ADC function (ADC4)
    A5          = PG_14, // No ADC function (ADC5)
    D0          = PA_10,
    D1          = PB_6,
    D2          = PD_6,
    D3          = PB_4,
    D4          = PG_15, // No counter function (T0)
    D5          = PC_7,
    D6          = PA_8,  // No analog compare function (AIN0)
    D7          = PG_6,  // No analog compare function (AIN1)
    D8          = PC_6,  // No clock output function (CLKO)
    D9          = PA_9,
    D10         = PG_12, // No PWM output function (OC1B)
    D11         = PG_11,
    D12         = PG_10,
    D13         = PG_9,
    D14         = PG_13, // No ADC function (ADC4)
    D15         = PG_14, // No ADC function (ADC5)
#else // MBED_CONF_TARGET_ARDUINO_ON_J5
    // Arduino on J5 connector namings
    A0          = PC_2,
    A1          = PC_3,
    A2          = PC_4,
    A3          = PC_5,
    A4          = PC_1,
    A5          = PC_0,
    D0          = PG_8,
    D1          = PG_7,
    D2          = PH_0,
    D3          = PB_5, 
    D4          = PH_1,  // No counter function (T0)
    D5          = PA_0,
    D6          = PF_10, // No analog compare function (AIN0)
    D7          = PB_2,  // No analog compare function (AIN1)
    D8          = PA_1,  // No clock output function (CLKO)
    D9          = PB_7,
    D10         = PB_12, // No PWM output function (OC1B)
    D11         = PB_15,
    D12         = PB_14,
    D13         = PB_13,
    D14         = PC_1,
    D15         = PC_0,
#endif // MBED_CONF_TARGET_ARDUINO_ON_J3

	// Zest connector J3 - J5 shared signals
    CAN1_RX     = PB_8,
    CAN1_TX     = PB_9,
    WKUP        = PC_13,

    // Zest connector signal namings (J3)
    I2C1_SCL 	= PG_14,
    I2C1_SDA 	= PG_13,
    UART1_RX 	= PA_10,
    UART1_TX 	= PB_6,
    SPI1_MOSI   = PG_11,
    SPI1_MISO   = PG_10,
    SPI1_SCK    = PG_9,
    SPI1_CS     = PG_12,
    PWM1_OUT    = PA_9,
    PWM2_OUT    = PA_8,
    PWM3_OUT    = PC_7,
    ICAPT1      = PC_6,
    DIO1        = PB_4,
    DIO2        = PG_6,
    DIO3        = PG_15,
    DIO4        = PD_6,
    ADC_IN1     = PF_6,
    ADC_IN2     = PF_7,
    ADC_IN3     = PF_8,
    ADC_IN4     = PF_9,
    DAC_OUT1    = PA_5,

    // Zest connector signal namings (J5)
    I2C2_SCL    = PC_0,
    I2C2_SDA    = PC_1,
    UART2_RX    = PG_8, // Low-power UART
    UART2_TX    = PG_7, // Low-power UART
    SPI2_MOSI   = PB_15,
    SPI2_MISO   = PB_14,
    SPI2_SCK    = PB_13,
    SPI2_CS     = PB_12,
    PWM4_OUT    = PB_7,
    PWM5_OUT    = PF_10,
    PWM6_OUT    = PA_0,
    ICAPT2      = PA_1,
    DIO5        = PB_5,
    DIO6        = PB_2,
    DIO7        = PH_1,
    DIO8        = PH_0,
    ADC_IN5     = PC_2,
    ADC_IN6     = PC_3,
    ADC_IN7     = PC_4,
    ADC_IN8     = PC_5,
    DAC_OUT2    = PA_4,

    // On board signal namings
    // USB signals
    USB_DP      = PA_12,
    USB_DM      = PA_11,

    // User I/Os
    USER_LED    = PF_11,
    USER_BUTTON = PH_3,

    // Generic signals namings
    LED1        = USER_LED,
    LED2        = USER_LED,
    LED3        = USER_LED,
    LED4        = USER_LED,
    BUTTON1     = USER_BUTTON,
    SERIAL_TX   = PA_2,
    SERIAL_RX   = PA_3,
    USBTX       = PA_2,
    USBRX       = PA_3,
    I2C_SCL     = I2C1_SCL,
    I2C_SDA     = I2C1_SDA,
    SPI_MOSI    = SPI1_MOSI,
    SPI_MISO    = SPI1_MISO,
    SPI_SCK     = SPI1_SCK,
    SPI_CS      = SPI1_CS,
    PWM_OUT     = PWM1_OUT,

    // SRAM signals
    SRAM_CE     = PG_9,
    SRAM_OE     = PD_4,
    SRAM_WE     = PD_5,
    SRAM_LB     = PE_0,
    SRAM_UB     = PE_1,
    SRAM_A0     = PF_0,
    SRAM_A1     = PF_1,
    SRAM_A2     = PF_2,
    SRAM_A3     = PF_3,
    SRAM_A4     = PF_4,
    SRAM_A5     = PF_5,
    SRAM_A6     = PF_12,
    SRAM_A7     = PF_13,
    SRAM_A8     = PF_14,
    SRAM_A9     = PF_15,
    SRAM_A10    = PG_1,
    SRAM_A11    = PG_0,
    SRAM_A12    = PG_2,
    SRAM_A13    = PG_3,
    SRAM_A14    = PG_4,
    SRAM_A15    = PG_5,
    SRAM_A16    = PD_11,
    SRAM_A17    = PD_12,
    SRAM_A18    = PD_13,
    SRAM_D0     = PD_14,
    SRAM_D1     = PD_15,
    SRAM_D2     = PD_0,
    SRAM_D3     = PD_1,
    SRAM_D4     = PE_7,
    SRAM_D5     = PE_8,
    SRAM_D6     = PE_9,
    SRAM_D7     = PE_10,
    SRAM_D8     = PE_11,
    SRAM_D9     = PE_12,
    SRAM_D10    = PE_13,
    SRAM_D11    = PE_14,
    SRAM_D12    = PE_15,
    SRAM_D13    = PD_8,
    SRAM_D14    = PD_9,
    SRAM_D15    = PD_10,

    // SD-Card signals (4-bit SD bus mode)
    SDCARD_CLK      = PC_12,
    SDCARD_CMD      = PD_2,
    SDCARD_D0       = PC_8,
    SDCARD_D1       = PC_9,
    SDCARD_D2       = PC_10,
    SDCARD_D3       = PC_11,
    SDCARD_DETECT   = PD_3, // SD-Card detection

    // QSPI FLASH pins
    QSPI_FLASH1_IO0    = PB_1,
    QSPI_FLASH1_IO1    = PB_0,
    QSPI_FLASH1_IO2    = PA_7,
    QSPI_FLASH1_IO3    = PA_6,
    QSPI_FLASH1_SCK    = PB_10,
    QSPI_FLASH1_CSN    = PB_11,

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;

#ifdef __cplusplus
}
#endif

#endif
