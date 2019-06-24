/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_BITFIELD_HPP
#define DM_ADVENCORE_BITFIELD_HPP

#include "HwUtils.hpp"

namespace AdvenCore
{
    template<typename T, unsigned int start, unsigned int end>
    class BitField
    {
    private:
        volatile unsigned short * const registerPtr; //register is a reserved keyword.
    public:
        explicit BitField() = delete;
        explicit BitField(volatile unsigned short * registerPtr) : registerPtr(registerPtr) {}
        explicit BitField(volatile unsigned short * registerPtr, T value) : registerPtr(registerPtr)
        {
            HwUtils::SetBit(*registerPtr, value, start, HwUtils::Mask<unsigned short>(start, end));
        }
        T operator= (const T other)
        {
            HwUtils::SetBit(*registerPtr, other, start, HwUtils::Mask<unsigned short>(start, end));
            return (T) HwUtils::GetBit(*registerPtr, start, HwUtils::Mask<unsigned short>(start, end));
        }
        operator const T() //NOLINT
        {
            return (T) HwUtils::GetBit(*registerPtr, start, HwUtils::Mask<unsigned short>(start, end));
        };
    };
}

#endif