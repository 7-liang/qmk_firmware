/* Copyright 2022 7Liang(@skyjun)
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

#include "matrix.h"
#include "wait.h"
#include "gpio.h"
#include "quantum.h"
#include "util.h"
#include "utils/74hc595.h"

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}

void matrix_init_custom(void)
{
    matrix_pins_init();
}

bool matrix_scan_custom(matrix_row_t current_matrix[])
{
    bool changed    = false;

    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++)
    {
        changed |= read_rows_on_col(current_matrix, current_col);
    }

    return changed;
}