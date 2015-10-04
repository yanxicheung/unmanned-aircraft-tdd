#ifndef _INCL_COORDINATE_H_
#define _INCL_COORDINATE_H_

struct Orientation;

struct Coordinate
{
    Coordinate(int x, int y, int z);

    Coordinate up() const;
    Coordinate down() const;
    Coordinate forward(const Orientation&) const;
    bool operator==(const Coordinate& rhs) const;

private:
    int x;
    int y;
    int z;
};

#endif