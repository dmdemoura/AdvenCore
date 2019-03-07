/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SRAM.hpp"

using namespace AdvenCore;

#ifdef ADVENCORE_USE_SRAM
    volatile const char* SRAM::magicNumber = "SRAM_Vnnn";
#endif
volatile void* SRAM::start = (volatile void*) 0x0E000000;