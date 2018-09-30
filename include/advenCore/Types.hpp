#ifndef DM_ADVENCORE_TYPES_HPP
#define DM_ADVENCORE_TYPES_HPP

namespace AdvenCore
{
    struct Tile8 { char pixel[8][8]; };
    struct Tile4 { char pixelPair[4][8]; };
    using Charblock8 = Tile8[256];
    using Charblock4 = Tile4[512];
    union Charblock
    {
        Charblock4 tile4;
        Charblock8 tile8;
    };
}

#endif