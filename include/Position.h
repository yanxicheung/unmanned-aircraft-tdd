#ifndef _INCL_POSITION_H_
#define _INCL_POSITION_H_

enum orientation {N, E, S, W};

struct Position
{
    Position(int x, int y, int z, orientation d);
    
    bool operator==(const Position& rhs) const;

    void up();
    void down();
    void forward();
    void turnLeft();
    void turnRight();
    void turnRound();

private:
    bool onTheGround() const;

private:
    int x;
    int y;
    int z;
    orientation d;
};

#endif