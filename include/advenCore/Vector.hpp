/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVENCORE_VECTOR_HPP
#define DM_ADVENCORE_VECTOR_HPP

namespace AdvenCore
{
    class Vector {
    public:
        int x;
        int y;
        Vector();
        Vector(int x, int y);
        Vector operator+=(Vector a);
        Vector operator-=(Vector a);
        Vector operator-();
    };

    Vector operator+(Vector a, Vector b);
    Vector operator-(Vector a, Vector b);
    Vector operator*(Vector a, int b);
    Vector operator*(int a, Vector b);
    bool operator==(Vector a, Vector b);
    bool operator!=(Vector a, Vector b);

}

#endif