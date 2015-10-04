#ifndef _INCL_POSITION_H_
#define _INCL_POSITION_H_

#include "Coordinate.h"
#include "Orientation.h"
#include "base/Role.h"

struct Position : Coordinate, Orientation
{
    Position(int x, int y, int z, const Orientation& d);
    bool operator==(const Position& rhs) const;

    IMPL_ROLE(Coordinate);
    IMPL_ROLE(Orientation);
};

#endif