/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_LINK_MULTIPLAYER_HPP
#define DM_ADVENCORE_LINK_MULTIPLAYER_HPP

#include "BitField.hpp"

namespace AdvenCore
{
    class LinkMultiplayer
    {
    private:
        static constexpr int UnitCount = 4;
        static volatile unsigned short * const communicationControl;
        static volatile unsigned short * const serialIOControl;
    public:
        static volatile unsigned short * const multiplayerSend;
        static volatile unsigned short (* const multiplayerData)[UnitCount];
    public:
        enum class BaudRate
        {
            bps9600 = 0,
            bps38400 = 1,
            bps57600 = 2,
            bps115200 = 3,
        };
    public:
        BitField<BaudRate, 0, 1> baudRate;
        BitField<bool, 2, 2> isFollower;
        BitField<bool, 3, 3> allUnitsReady;
        BitField<int, 4, 5> unitID;
        BitField<bool, 6, 6> error;
        BitField<bool, 7, 7> start;
        BitField<int, 8, 12> shouldBeZero;
        BitField<int, 13, 13> shouldBeOne;
        BitField<bool, 14, 14> enableInterrupt;
    public:
        LinkMultiplayer();
    };
}

#endif
