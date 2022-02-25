/* Copyright 2022 7Liang(@7-liang)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * 适用于两定位一脉冲编码器
 * the encoder model is ALPS SRGP 200200
 * two positioning only one pulse
 */

#include "ring_encoder.h"

#if !defined(ENCODERS_PAD_A) || !defined(ENCODERS_PAD_B)
#   error "No encoder pads defined by ENCODERS_PAD_A and ENCODERS_PAD_B"
#endif

static pin_t EC_A_Pins[]    = ENCODERS_PAD_A;
static pin_t EC_B_Pins[]    = ENCODERS_PAD_B;
#define EC_NUMS (sizeof(EC_A_Pins) / sizeof(pin_t))

static uint8_t EC_A_Curr[EC_NUMS]   = {0};      // 当前电平
static uint8_t EC_B_Curr[EC_NUMS]   = {0};
static uint8_t EC_A_Last[EC_NUMS]   = {0};      // 上次电平
static uint8_t EC_B_Last[EC_NUMS]   = {0};

__attribute__((weak)) bool encoder_update_user(uint8_t index, bool clockwise) { return true; }

__attribute__((weak)) bool encoder_update_kb(uint8_t index, bool clockwise) { return encoder_update_user(index, clockwise); }


void encoder_init(void)
{
    for (uint8_t i = 0; i < EC_NUMS; i++)
    {
        setPinInputHigh(EC_A_Pins[i]);
        setPinInputHigh(EC_B_Pins[i]);
    }
}

bool encoder_scan(void)
{
    bool changed                = false;
    int8_t scan_result[EC_NUMS] = {0};

    for (uint8_t i = 0; i < EC_NUMS; i++)
    {
        EC_A_Curr[i]    = readPin(EC_A_Pins[i]);
        EC_B_Curr[i]    = readPin(EC_B_Pins[i]);

        // 编码器旋转方向判断依据当前电平和上次电平的正反相
        //    last   curr        last   curr        last   curr        last   curr
        // A (  0  ->  1  ) & B (  1  ->  0  ) | A (  1  ->  0  ) & B (  0  ->  1  ), 正转 forward
        // A (  0  ->  1  ) & B (  0  ->  1  ) | A (  1  ->  0  ) & B (  1  ->  0  ), 反转 reverse
        if (EC_A_Curr[i] != EC_A_Last[i])
        {
            if (EC_A_Curr[i] == 1)
            {
                if (EC_B_Last[i] && !EC_B_Curr[i]) scan_result[i] = 1;          // b last = 1 and curr = 0, forward
                else if (!EC_B_Last[i] && EC_B_Curr[i]) scan_result[i] = -1;    // b last = 0 and curr = 1, reverse
                else if (EC_B_Curr[i] == EC_B_Last[i])                          // last == curr, encoder quick reversal
                {
                    if (!EC_B_Curr[i]) scan_result[i] = 1;                      // curr == 0, forward
                    else scan_result[i] = -1;                                   // curr == 1, reverse
                }
            }
            else
            {
                if (EC_B_Last[i] && !EC_B_Curr[i]) scan_result[i] = -1;         // b last = 1 and curr = 0, reverse
                else if (!EC_B_Last[i] && EC_B_Curr[i]) scan_result[i] = 1;     // b last = 0 and curr = 1, forward
                else if (EC_B_Curr[i] == EC_B_Last[i])                          // encoder quick reversal
                {
                    if (!EC_B_Curr[i]) scan_result[i] = -1;                     // curr == 0, reverse
                    else scan_result[i] = 1;                                    // curr == 1, forward
                }
            }

            // update last
            EC_A_Last[i]    = EC_A_Curr[i];
            EC_B_Last[i]    = EC_B_Curr[i];

            if (scan_result[i] == 1)
            {
                changed |= encoder_update_kb(i, true);
            }
            else if (scan_result[i] == -1)
            {
                changed |= encoder_update_kb(i, false);
            }
        }
    }    

    return changed;
}
