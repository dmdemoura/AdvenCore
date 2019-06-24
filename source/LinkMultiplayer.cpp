/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <advenCore/LinkMultiplayer.hpp>

using namespace AdvenCore;

volatile unsigned short * const LinkMultiplayer::communicationControl = (volatile unsigned short*) 0x04000134;
volatile unsigned short * const LinkMultiplayer::serialIOControl = (volatile unsigned short*) 0x04000128;
volatile unsigned short * const LinkMultiplayer::multiplayerSend = (volatile unsigned short*) 0x0400012A;
volatile unsigned short (* const LinkMultiplayer::multiplayerData)[LinkMultiplayer::UnitCount]
    = (volatile unsigned short (*)[LinkMultiplayer::UnitCount]) 0x04000120;

LinkMultiplayer::LinkMultiplayer() :
    shouldBeZero(serialIOControl),
    shouldBeOne(serialIOControl),
    baudRate(serialIOControl),
    isFollower(serialIOControl),
    allUnitsReady(serialIOControl),
    unitID(serialIOControl),
    error(serialIOControl),
    start(serialIOControl),
    enableInterrupt(serialIOControl)
{
    //TODO: Handle switching communication modes.
    *communicationControl = 0;
    shouldBeZero = 0;
    shouldBeOne = 1;
}
