#include "UnmannedAircraft.h"

UnmannedAircraft::UnmannedAircraft() : position(0,0,0,N)
{
}    

const Position& UnmannedAircraft::getPosition() const
{
    return position;
}

void UnmannedAircraft::on(const Instruction& instruction)
{
    if(instruction == UP)
    {
        position.up();
    }

    if(instruction == DOWN)
    {
        position.down();
    }

    if(instruction == FORWARD)
    {
        position.forward();
    }
}