#include "UnmannedAircraft.h"
#include "Instruction.h"

UnmannedAircraft::UnmannedAircraft() : position(0,0,0,N)
{
}    

const Position& UnmannedAircraft::getPosition() const
{
    return position;
}

void UnmannedAircraft::on(const Instruction& instruction)
{
    instruction.exec(position.ROLE(Coordinate), position.ROLE(Orientation));
}
