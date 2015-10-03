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

bool Position::onTheGround() const
{
    return z == 0;
}

void Position::down()
{
    if(onTheGround()) return;

    --z;
}

void Position::forward()
{
    ++y;
}

void Position::turnLeft()
{
    d = static_cast<orientation>((d+3)%4);
}