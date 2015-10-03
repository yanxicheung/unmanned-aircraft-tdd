#include "Position.h"

Position::Position(int x, int y, int z, const Orientation& d) 
    : Coordinate(x,y,z), Orientation(d)
{
}
    
bool Position::operator==(const Position& rhs) const
{
    return static_cast<const Coordinate&>(*this) == rhs &&
           static_cast<const Orientation&>(*this) == rhs;
}
