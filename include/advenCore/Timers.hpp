/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_TIMERS_HPP
#define DM_ADVENCORE_TIMERS_HPP

namespace AdvenCore
{
    class Timers
    {
    private:
        enum class TimerControlMasks
        {
            Frequency           = 0b0000000000000011,
            Cascade             = 0b0000000000000100,
            InterruptOnOveflow  = 0b0000000001000000,
            Enable              = 0b0000000010000000
        };
        enum class TimerControlOffsets
        {
            Frequency           = 0,
            Cascade             = 2,
            InterruptOnOverflow = 6,
            Enable              = 7
        };
    public:
        enum class Frequency
        {
            Cycles1     = 0,
            Cycles64    = 1,
            Cycles256   = 2,
            Cycles1024  = 3
        };
    private:
        struct TimerRegisters
        {
            short Data;
            short Control;
        };
    private:
        volatile static TimerRegisters* timerRegisters;
    public:
        static void Enable(int timerID, bool enable);
        static void EnableCascading(int timerID, bool enable);
        static void EnableInterruptOnOverflow(int timerID, bool enable);
        static void SetFrequency(int timerID, Frequency frequency);
        static void SetInitialValue(int timerID, int cycles);
        static int GetCurrentValue(int timerID);
    };
};

#endif