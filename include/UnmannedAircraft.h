#ifndef _INCL_UNMANNED_AIRCRAFT_H_
#define _INCL_UNMANNED_AIRCRAFT_H_

#include "Position.h"

struct UnmannedAircraft
{
    UnmannedAircraft();

    const Position& getPosition() const;

private:
    Position position;
};

#endif