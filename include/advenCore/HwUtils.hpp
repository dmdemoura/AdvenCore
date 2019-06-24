/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_HWUTILS_HPP
#define DM_ADVENCORE_HWUTILS_HPP

#include <limits>
#include <cstdint>

namespace AdvenCore
{
    class HwUtils {
    public:
        /**
         * Set any number of bits, anywhere in an integer-like value.
         * @details Should be at most sizeof(unsigned int)
         * @tparam T Destination integer-like type.
         * @tparam T1 Destination integer-like type.
         * @tparam T2 Destination integer-like type.
         * @tparam T3 Destination integer-like type.
         * @param destination Reference to destination. If you pass a pointer, this will set where it points to.
         * @param value Value to be set, it will be masked.
         * @param bitOffset Offset from 0 to start of bits to be set.
         * @param bitMask Mask of the region to be set. Should be absolute, not relative to offset.
         */
        template<typename T, typename T1, typename T2, typename T3>
        static void SetBit(T &destination, T1 value, T2 bitOffset, T3 bitMask)
        {
            destination = (destination & ~((T) bitMask)) |
                   ((T) value << (T) bitOffset & (T) bitMask);
        }
        /**
         * Get any number of bits from anywhere in an integer-like value.
         * @details Should be at most sizeof(unsigned int)
         * @tparam T Destination integer-like type.
         * @tparam T1 Destination integer-like type.
         * @tparam T2 Destination integer-like type.
         * @param source Source value to extract bit from.
         * @param bitOffset Offset from 0 to start of bits to be returned.
         * @param bitMask Mask of the region to be returned. Should be absolute, not relative to offset.
         * @return The bits matched by the masked, offset to start at bit 0.
         */
        template <typename T, typename T1, typename T2>
        static unsigned int GetBit(T source, T1 bitOffset, T2 bitMask)
        {
            return (source & (T) bitMask) >> (T) bitOffset;
        }
        /**
         * Generates a mask from a range of bits.
         * @tparam T Should be the type the mask is meant to be used on.
         * @param startBit The startBit index (0 = LeastSignificant), INCLUSIVE.
         * @param endBit The endBit index (0 = LeastSignificant), INCLUSIVE.
         * @return The generated mask.
         */
        template <typename T>
        static T Mask(unsigned int startBit, unsigned int endBit)
        {
            T max = std::numeric_limits<T>::max(); //Gets the biggest number for T type.
            T sizeofT = 8 * sizeof(T); //Size in bits of T.

            T upperShift = sizeofT - endBit - 1;
            T upperMask = ~(max >> upperShift);

            T lowerShift = sizeofT - startBit;
            T lowerMask = max >> lowerShift;

            T mask = ~(upperMask | lowerMask); //Combines the two parts and negates it.

            return mask;
        }

        template<typename T>
        static T* OffsetPointer(T* pointer, std::ptrdiff_t offset)
        {
            return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(pointer) + offset);
        }
    };
}

#endif