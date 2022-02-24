/*
 * @Description    : 
 * @version        : 
 * @Author         : JunLee
 * @Date           : 2022-02-24 11:44:13
 * @LastEditTime   : 2022-02-24 17:25:02
 * @FilePath       : \qmk_firmware\keyboards\7liang\tpec11801\matrix.c
 */

#include "matrix.h"
#include "wait.h"
#include "gpio.h"
#include "quantum.h"
#include "util.h"

#ifdef DIRECT_PINS
#   error invalid DIRECT_PINS for 74hc595 matrix
#elif (DIODE_DIRECTION == COL2ROW)
const pin_t col_pins[MATRIX_COLS]                   = MATRIX_COL_PINS;
const pin_t row_pins[MATRIX_ROWS]                   = MATRIX_ROW_PINS;
const uint8_t mask_of_595[HC595_NUMS][MATRIX_COLS]  = HC595_MATRIX_DATA;
#endif


static void hc595_shift_data(uint8_t data)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        writePinLow(HC595_SCK_PIN);
        writePin(HC595_SER_PIN, (data >> i) & 1);
        writePinHigh(HC595_SCK_PIN);
    }
}

static void unselect_rows(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++)
    {
        setPinInputHigh(row_pins[i]);
    }
}

static void unselect_cols(void)
{
    for (uint8_t i = 0; i < MATRIX_COLS; i++)
    {
        if (col_pins[i] != NO_PIN) writePinLow(col_pins[i]);
    }

    writePinLow(HC595_RCK_PIN);
    for (uint8_t i = 0; i < HC595_NUMS; i++)
    {
        hc595_shift_data(0x00);
    }
    writePinHigh(HC595_RCK_PIN);
}

static void select_col(uint8_t col)
{
    if (col_pins[col] != NO_PIN)
    {
        writePinHigh(col_pins[col]);
        return;
    }

    writePinLow(HC595_RCK_PIN);
    for (uint8_t i = 0; i < HC595_NUMS; i++)
    {
        hc595_shift_data(mask_of_595[i][col]);
    }
    writePinHigh(HC595_RCK_PIN);
}

static void pins_init(void)
{
    setPinOutput(HC595_SCK_PIN);
    setPinOutput(HC595_SER_PIN);
    setPinOutput(HC595_RCK_PIN);
    writePinHigh(HC595_SCK_PIN);
    writePinHigh(HC595_SER_PIN);
    writePinHigh(HC595_RCK_PIN);

    for (uint8_t i = 0; i < MATRIX_COLS; i++)
    {
        if (col_pins[i] != NO_PIN) setPinOutput(col_pins[i]);
    }

    unselect_rows();
    unselect_cols();
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col)
{
    bool matrix_changed = false;

    select_col(current_col);
    matrix_output_select_delay();

    for (uint8_t row_idx = 0; row_idx < MATRIX_ROWS; row_idx++)
    {
        matrix_row_t last_row_value     = current_matrix[row_idx];
        matrix_row_t current_row_value  = last_row_value;

        if (readPin(row_pins[row_idx]) == 1)
        {
            current_row_value   |= (MATRIX_ROW_SHIFTER << current_col);
        }
        else
        {
            current_row_value   &= (MATRIX_ROW_SHIFTER << current_col);
        }

        if ((last_row_value != current_row_value))
        {
            matrix_changed          |= true;
            current_matrix[row_idx] = current_row_value;
        }
    }

    unselect_cols();
    matrix_output_unselect_delay(current_col, matrix_changed);

    return matrix_changed;
}

void matrix_init_custom(void)
{
    pins_init();
}

uint8_t matrix_scan_custom(matrix_row_t current_matrix[])
{
    bool changed    = false;

    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++)
    {
        changed |= read_rows_on_col(current_matrix, current_col);
    }

    return (uint8_t)changed;
}