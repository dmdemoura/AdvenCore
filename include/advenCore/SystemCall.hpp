/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_SYSTEMCALL_HPP
#define DM_ADVENCORE_SYSTEMCALL_HPP

#include <cstddef>

namespace AdvenCore
{
    namespace SystemCall
    {
        struct MultiBootParameters
        {
            char padding[0x14];
            char handshakeData;
            char padding2[0x4];
            char clientData[0x3];
            char paletteData;
            char padding3;
            char clientBit;
            char padding4;
            const void *bootImageStart;
            const void *bootImageEnd;
            char padding5[0x24];
        };

        //Make sure MultiBootParameters is within specifications.
        static_assert(sizeof(MultiBootParameters) == 0x4C, "MultiBoot parameters does not have correct size: 0x4C");
        static_assert(offsetof(MultiBootParameters, handshakeData) == 0x14);
        static_assert(offsetof(MultiBootParameters, clientData) == 0x19);
        static_assert(offsetof(MultiBootParameters, paletteData) == 0x1C);
        static_assert(offsetof(MultiBootParameters, clientBit) == 0x1e);
        static_assert(offsetof(MultiBootParameters, bootImageStart) == 0x20);
        static_assert(offsetof(MultiBootParameters, bootImageEnd) == 0x24);

        enum class MultiBootTransferMode
        {
            NormalMode = 0,
            MultiplayerMode =1,
            FastNormalMode = 2
        };


//            void VBlankIntrWait
        bool MultiBoot(MultiBootParameters* paramaters, MultiBootTransferMode transferMode);
    };
}

#endif