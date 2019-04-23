/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_MACROS_PROPERTY_HPP
#define DM_ADVENCORE_MACROS_PROPERTY_HPP

#define get(T) [&]()->T&
#define set(T) [&](const T& value)->T&

#endif