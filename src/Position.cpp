#include "Position.h"

Position::Position(int x, int y, int z, const Orientation& d) 
    : Coordinate(x,y,z), Orientation(d)
{
}
    
bool Position::operator==(const Position& rhs) const
{
    return ROLE(Coordinate) == rhs.ROLE(Coordinate) &&
           ROLE(Orientation) == rhs.ROLE(Orientation);
}
