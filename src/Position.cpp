#include "Position.h"

Position::Position(int x, int y, int z, orientation d) : x(x), y(y), z(z), d(d)
{
}
    
bool Position::operator==(const Position& rhs) const
{
    return x==rhs.x && y==rhs.y && z==rhs.z && d==rhs.d; 
}

void Position::up()
{
    ++z;
}

void Position::down()
{
    --z;
}

void Position::forward()
{
    ++y;
}