/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_PROPERTY_HPP
#define DM_ADVENCORE_PROPERTY_HPP

#include <functional>

namespace AdvenCore
{
    template<typename T>
    class Property
    {
    private:
        std::function<T&()> get;
        std::function<T&(const T&)> set;
    public:
        Property<T>(std::function<T&()> get, std::function<T&(const T&)> set) : get(get), set(set) {}
        T& operator= (const T& other)
        {
            return set(other);
        }
        operator const T&()
        {
            return get();
        };
    };
}

#endif