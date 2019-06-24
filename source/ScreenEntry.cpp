/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "ScreenEntry.hpp"
#include "HwUtils.hpp"

using namespace AdvenCore;

ScreenEntry::ScreenEntry(int tileID, bool horizontalFlip, bool verticalFlip, int paletteBank)
{
    HwUtils::SetBit(entry, tileID, ScreenEntry::SEOffsets::TileID, ScreenEntry::SEMasks::TileID);
    HwUtils::SetBit(entry, horizontalFlip, ScreenEntry::SEOffsets::HorizontalFlip, ScreenEntry::SEMasks::HorizontalFlip);
    HwUtils::SetBit(entry, verticalFlip, ScreenEntry::SEOffsets::VerticalFlip, ScreenEntry::SEMasks::VerticalFlip);
    HwUtils::SetBit(entry, paletteBank, ScreenEntry::SEOffsets::PalleteBank, ScreenEntry::SEMasks::PalleteBank);
}

ScreenEntry::operator const unsigned short()
{
    return entry;
}
