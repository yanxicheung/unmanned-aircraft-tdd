#include "Orientation.h"
#include "Coordinate.h"

namespace
{
    Orientation* orientations[4];
}

Orientation::Orientation(int order, int xFactor, int yFactor) 
    : order(order), xFactor(xFactor), yFactor(yFactor)
{
    orientations[order] = this;
}

Orientation Orientation::turnLeft() const
{
    return *orientations[(order+3)%4];
}

Orientation Orientation::turnRight() const
{
    return *orientations[(order+1)%4];
}

Orientation Orientation::turnRound() const
{
    return *orientations[(order+2)%4];   
}

bool Orientation::operator==(const Orientation& rhs) const
{
    return order == rhs.order;
}

Coordinate Orientation::moveOn(int x, int y, int z) const
{
    return Coordinate(x+xFactor,y+yFactor,z);
}

const Orientation Orientation::north(0,  0,  1);
const Orientation Orientation::east( 1,  1,  0);
const Orientation Orientation::south(2,  0, -1);
const Orientation Orientation::west( 3, -1,  0);
