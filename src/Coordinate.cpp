#include "Coordinate.h"
#include "Orientation.h"

Coordinate::Coordinate(int x, int y, int z) : x(x), y(y), z(z)
{
}

Coordinate Coordinate::up() const
{
    return Coordinate(x,y,z+1);
}

Coordinate Coordinate::down() const
{
    if(z == 0) return Coordinate(x,y,z);
    return Coordinate(x,y,z-1);
}
 
Coordinate Coordinate::forward(const Orientation& ori) const
{
    return ori.moveOn(x,y,z);
}

bool Coordinate::operator==(const Coordinate& rhs) const
{
    return x==rhs.x && y==rhs.y && z==rhs.z;
}
