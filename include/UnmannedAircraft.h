#ifndef _INCL_UNMANNED_AIRCRAFT_H_
#define _INCL_UNMANNED_AIRCRAFT_H_

#include "Position.h"

struct Instruction;

struct UnmannedAircraft
{
    UnmannedAircraft();

    void on(const Instruction&);

    const Position& getPosition() const;

private:
    Position position;
};

#endif