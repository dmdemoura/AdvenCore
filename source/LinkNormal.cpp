/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "LinkNormal.hpp"

using namespace AdvenCore;

volatile unsigned short * const LinkNormal::serialIORegister = (volatile unsigned short*) 0x04000128;
volatile unsigned int * const LinkNormal::serialIOData32 = (volatile unsigned int*) 0x04000120;

BitField<unsigned short, 0, 0> LinkNormal::shiftClockType {serialIORegister};
BitField<unsigned short, 1, 1> LinkNormal::internalShiftClockSpeed {serialIORegister};
BitField<bool, 2, 2> LinkNormal::serialInputState {serialIORegister};
BitField<bool, 3, 3> LinkNormal::serialOutputState {serialIORegister};
BitField<bool, 7, 7> LinkNormal::start {serialIORegister};
BitField<LinkNormal::TransferLength , 12, 12> LinkNormal::transferLength {serialIORegister};
BitField<bool, 14, 14> LinkNormal::enableIRQ {serialIORegister};