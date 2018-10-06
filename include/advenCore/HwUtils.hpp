/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_HWUTILS_HPP
#define DM_ADVENCORE_HWUTILS_HPP

namespace AdvenCore
{
    class HwUtils
    {
    public:
        template <typename T, typename T1, typename T2, typename T3>
        static void SetBit(T& dest, T1 value, T2 bitOffset, T3 bitMask)
        {
            dest = (dest & ~((int) bitMask)) | ((int) value << (int) bitOffset & (int) bitMask);
        }
    };
}

#endif