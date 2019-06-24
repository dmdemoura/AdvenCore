/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "Vector.hpp"

using namespace AdvenCore;

Vector::Vector() : Vector(0,0) {}
Vector::Vector(int x, int y) : x(x), y(y) {}

Vector Vector::operator+=(Vector a)
{
    x += a.x;
    y += a.y;
    return *this;
}
Vector Vector::operator-=(Vector a)
{
    x -= a.x;
    y -= a.y;
    return *this;
}
Vector Vector::operator-()
{
    return {-x, -y};
}
Vector Vector::operator>>(int a)
{
    return {x >> a, y >> a};
}
Vector Vector::operator<<(int a)
{
    return {x << a, y << a};
}
Vector AdvenCore::operator+(Vector a, Vector b)
{
    return {a.x + b.x, a.y + b.y};
}
Vector AdvenCore::operator-(Vector a, Vector b)
{
    return {a.x - b.x, a.y - b.y};
}
Vector AdvenCore::operator*(Vector a, int b)
{
    return {a.x * b, a.y * b};
}
Vector AdvenCore::operator*(int a, Vector b)
{
    return b * a;
}
bool AdvenCore::operator==(Vector a, Vector b)
{
    return a.x == b.x && a.y == b.y;
}
bool AdvenCore::operator!=(Vector a, Vector b)
{
    return !(a == b);
}