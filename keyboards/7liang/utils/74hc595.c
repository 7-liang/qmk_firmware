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

#include "74hc595.h"
#include "gpio.h"
#include "wait.h"
#include "util.h"

#ifdef DIRECT_PINS
#   error "invalid DIRECT_PINS for 74hc595 matrix"
#elif (DIODE_DIRECTION == COL2ROW)
#   error "DIODE_DIRECTION must be defined as ROW2COL"
#elif (DIODE_DIRECTION == ROW2COL)
#   ifdef HC595_AND_GPIO_BOTH_USED
const pin_t col_pins[MATRIX_COLS]                   = MATRIX_COL_PINS;
#   endif
const pin_t row_pins[MATRIX_ROWS]                   = MATRIX_ROW_PINS;
const uint8_t mask_of_595[HC595_NUMS][MATRIX_COLS]  = HC595_MATRIX_DATA;
#else
#   error "DIODE_DIRECTION must be defined"
#endif

// 向移位寄存器写入一个字节，从低往高
static void hc595_write_byte(uint8_t data)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        writePinLow(HC595_SCK_PIN);
        writePin(HC595_SER_PIN, (data >> i) & 1);
        writePinHigh(HC595_SCK_PIN);
    }
}

// 将行设置为上拉输入
static void unselect_rows(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) setPinInputHigh(row_pins[i]);
}

// 拉高所有列
static void unselect_cols(void)
{
#   ifdef HC595_AND_GPIO_BOTH_USED
    for (uint8_t i = 0; i < MATRIX_COLS; i++)
    {
        if (col_pins[i] != NO_PIN) writePinHigh(col_pins[i]);
    }
#   endif

    writePinLow(HC595_RCK_PIN);
    for (uint8_t i = 0; i < HC595_NUMS; i++) hc595_write_byte(0xFF);
    writePinHigh(HC595_RCK_PIN);
}

// 拉低指定列
static void select_cols(uint8_t col)
{
#   ifdef HC595_AND_GPIO_BOTH_USED
    if (col_pins[col] != NO_PIN)
    {
        writePinLow(col_pins[col]);
        return;
    }
#   endif

    writePinLow(HC595_RCK_PIN);                         // 拉低存储寄存器时钟
    for (uint8_t i = HC595_NUMS; i > 0; i--)            // 向移位寄存器写入数据，拉低相应列，其余列拉高
    {
        hc595_write_byte(mask_of_595[i - 1][col]);
    }
    writePinHigh(HC595_RCK_PIN);                        // 拉高存储寄存器时钟，并行输出写入的数据
}

// 初始化 74hc595 io 输出并拉高，行引脚上拉输入，列输出高
void matrix_pins_init(void)
{
    setPinOutput(HC595_SCK_PIN);
    setPinOutput(HC595_SER_PIN);
    setPinOutput(HC595_RCK_PIN);
    writePinHigh(HC595_SCK_PIN);
    writePinHigh(HC595_SER_PIN);
    writePinHigh(HC595_RCK_PIN);
    
#   ifdef HC595_AND_GPIO_BOTH_USED
    for (uint8_t i = 0; i < MATRIX_COLS; i++)
    {
        if (col_pins[i] != NO_PIN)
        {
            setPinOutput(col_pins[i]);
            writePinHigh(col_pins[i]);
        }
    }
#   endif

    unselect_rows();
    unselect_cols();
}

// 扫描，循环拉低所有列
bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col)
{
    bool matrix_changed = false;

    select_cols(current_col);
    matrix_output_select_delay();

    for (uint8_t row_idx = 0; row_idx < MATRIX_ROWS; row_idx++)
    {
        matrix_row_t last_val       = current_matrix[row_idx];
        matrix_row_t current_val    = last_val;

        if (readPin(row_pins[row_idx]) == 0)
        {
            current_val |= (MATRIX_ROW_SHIFTER << current_col);
        }
        else
        {
            current_val &= ~(MATRIX_ROW_SHIFTER << current_col);
        }

        if (last_val != current_val)
        {
            matrix_changed          |= true;
            current_matrix[row_idx] = current_val;
        }
    }

    unselect_cols();
    matrix_output_unselect_delay(current_col, matrix_changed);

    return matrix_changed;
}
