#include "UnmannedAircraft.h"

UnmannedAircraft::UnmannedAircraft() : position(0,0,0,N)
{
}    

const Position& UnmannedAircraft::getPosition() const
{
    return position;
}
