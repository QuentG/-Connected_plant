/*
 * Copyright (c) 2017, CATIE, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "mbed.h"

namespace {
#define PERIOD_MS 50
}

static DigitalOut led1(LED1);
static AnalogIn an(ADC_IN1);
static I2C i2c(I2C1_SDA, I2C1_SCL);

char cmd[2];

uint8_t lm75_adress = 0x48 << 1;

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for delays)
int main()
{
    while (true) 
    {
        cmd[0] = 0x00;
        i2c.write(lm75_adress, cmd, 1);
        i2c.read(lm75_adress, cmd, 2);

        float temperature = ((cmd[0] << 8 | cmd[1]) >> 7) * 0.5;

        printf("La temperature est de : %f \n", temperature);

        // Calcul % humidity
        float measure_percent = an.read()*3.3*100/3.3;

        printf("Percentage humidity: %f\n", measure_percent);

        Thread::wait(PERIOD_MS);
    }
}
