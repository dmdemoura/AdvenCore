/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

    .text
    .thumb
    .align 2
    .global _ZN9AdvenCore10SystemCall9MultiBootEPNS0_19MultiBootParametersENS0_21MultiBootTransferModeE
    .type _ZN9AdvenCore10SystemCall9MultiBootEPNS0_19MultiBootParametersENS0_21MultiBootTransferModeE STT_FUNC
_ZN9AdvenCore10SystemCall9MultiBootEPNS0_19MultiBootParametersENS0_21MultiBootTransferModeE:
    swi 0x25
    bx lr