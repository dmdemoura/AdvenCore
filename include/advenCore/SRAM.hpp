/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_SRAM
#define DM_ADVENCORE_SRAM

namespace AdvenCore
{
    class SRAM
    {
    private:
        #ifdef ADVENCORE_USE_SRAM
            volatile static const char* magicNumber;
        #endif
    public:
        volatile static void* start;
    };
}

#endif