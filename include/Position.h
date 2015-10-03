#ifndef _INCL_POSITION_H_
#define _INCL_POSITION_H_

enum orientation {N, E, S, W};

struct Position
{
    Position(int x, int y, int z, orientation d);
    
    bool operator==(const Position& rhs) const;

private:
    int x;
    int y;
    int z;
    orientation d;
};

#endif