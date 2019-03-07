/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "ScreenEntry.hpp"
#include "HwUtils.hpp"

using namespace AdvenCore;

ScreenEntry::ScreenEntry(int tileID, bool horizontalFlip, bool verticalFlip)
{
    HwUtils::SetBit(entry, tileID, SEOffsets::TileID, SEMasks::TileID);
    HwUtils::SetBit(entry, horizontalFlip, SEOffsets::HorizontalFlip, SEMasks::HorizontalFlip);
    HwUtils::SetBit(entry, verticalFlip, SEOffsets::VerticalFlip, SEMasks::VerticalFlip);
    HwUtils::SetBit(entry, 0, SEOffsets::PalleteBank, SEMasks::PalleteBank);
}