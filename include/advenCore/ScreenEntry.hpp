/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_SCREEN_ENTRY_HPP
#define DM_ADVENCORE_SCREEN_ENTRY_HPP

namespace AdvenCore
{
    class ScreenEntry
    {
    private:
        enum class SEMasks
        {
            TileID          = 0b0000001111111111,
            HorizontalFlip  = 0b0000010000000000,
            VerticalFlip    = 0b0000100000000000,
            PalleteBank     = 0b1111000000000000
        };
        enum class SEOffsets
        {
            TileID          = 0,
            HorizontalFlip  = 10,
            VerticalFlip    = 11,
            PalleteBank     = 12
        };
    private:
        unsigned short entry;
    public:
        explicit ScreenEntry(int tileID, bool horizontalFlip = false, bool verticalFlip = false, int paletteBank = 0);
        operator const unsigned short(); //NOLINT
    };
}

#endif