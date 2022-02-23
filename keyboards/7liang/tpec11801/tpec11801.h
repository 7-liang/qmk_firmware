// Copyright 2022 7liang (@skyjun)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define ___     KC_NO

#define LAYOUT_ortho_7x18( \
    K00,      K02, K03, K04, K05, K06, K07,      K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H,   \
              K12, K13, K14, K15, K16, K17,      K19, K1A, K1B, K1C,      K1E, K1F, K1G, K1H,   \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G,        \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H,   \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C,      K4E,      K4G,        \
    K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B,      K5D,                       \
    K60, K61, K62,           K65,                K69, K6A, K6B, K6C, K6D, K6E                   \
    ) { \
/*         0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17  */  \
/* 0 */ { K00, ___, K02, K03, K04, K05, K06, K07, ___, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H },   \
/* 1 */ { ___, ___, K12, K13, K14, K15, K16, K17, ___, K19, K1A, K1B, K1C, ___, K1E, K1F, K1G, K1H },   \
/* 2 */ { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G, ___ },   \
/* 3 */ { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H },   \
/* 4 */ { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, ___, K4E, ___, K4G, ___ },   \
/* 5.*/ { K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, ___, K5D, ___, ___, ___, ___ },   \
/* 6.*/ { K60, K61, K62, ___, ___, K65, ___, ___, ___, K69, K6A, K6B, K6C, K6D, K6E }                   \
    }