/******************************************************************************
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Joseph Kroesche
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 *****************************************************************************/

#ifndef __THERMISTOR_TABLE_H__
#define __THERMISTOR_TABLE_H__

/** @addtogroup therm Thermistor
 *
 * This file was generated by https://github.com/kroesche/thermistor_lookup
 *
 * Generated on 2023-03-22 11:58:59.037387,<br/>
 * for a thermistor circuit with the following parameters:
 *
 * |Parameter |Value                         |
 * |----------|------------------------------|
 * |Input File|example.json                  |
 * |Board     |ATtiny85 geyserwise           |
 * |Thermistor|unknown                       |
 * |Tstart    |40                            |
 * |Tstop     |100                           |
 * |Tstep     |5                             |
 * |Tnominal  |25                            |
 * |Rnominal  |10000                         |
 * |Rpulldown |10000                         |
 * |beta      |4200                          |
 * |counts    |1023                          |
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get temperature in C from ADC input.
 *
 * @param adc ADC counts for the temperature sensor
 *
 * Calculates the temperature in C from a temperature sensor ADC value.
 * The calculation uses a lookup table generated for a specific thermistor
 * circuit. If the input is outside the range of the pre-computed lookup table,
 * it interpolates linearly beyond the table, with an increasing amount of
 * error the further outside the table range.
 */
extern int16_t adc_to_temp(uint16_t adc);

#ifdef __cplusplus
}
#endif

#endif

/** @} */
