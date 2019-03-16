/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_LINK_PORT_HPP
#define DM_ADVENCORE_LINK_PORT_HPP

#include "BitField.hpp"

namespace AdvenCore
{
    class LinkNormal
    {
    private:
        //It seems you can't write to this without being linked, at least on VBM-M
        static volatile unsigned short * const serialIORegister;
    public:
        static volatile unsigned int * const serialIOData32;
    public:


        enum class ShiftClockType
        {
            external = 0,
            internal = 1
        };
        enum class InternalShiftClockSpeed
        {
            khz256 = 0,
            mhz2 = 1
        };
        enum class TransferLength
        {
            bit8 = 0,
            bit32 = 1
        };
    public:
        static BitField<unsigned short, 0, 0> shiftClockType;
        static BitField<unsigned short, 1, 1> internalShiftClockSpeed;
        static BitField<bool, 2, 2> serialInputState;
        static BitField<bool, 3, 3> serialOutputState;
        static BitField<bool, 7, 7> start;
        static BitField<TransferLength , 12, 12> transferLength;
        static BitField<bool, 14, 14> enableIRQ;
    };
}

#endif