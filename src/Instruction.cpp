#include "Instruction.h"
#include "Coordinate.h"
#include "Orientation.h"

namespace
{
    struct UpInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate& coor, Orientation&) const
        {
            coor = coor.up();
        } 
    };
}

Instruction& Instructions::up()
{
    static UpInstruction up;
    return up;
}

namespace
{
    struct DownInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate& coor, Orientation&) const
        {
            coor = coor.down();
        } 
    };
}

Instruction& Instructions::down()
{
    static DownInstruction down;
    return down;
}

namespace
{
    struct ForwardInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate& coor, Orientation& ori) const
        {
            coor = coor.forward(ori);
        } 
    };
}

Instruction& Instructions::forward()
{
    static ForwardInstruction forward;
    return forward;
}

namespace
{
    struct LeftInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate&, Orientation& ori) const
        {
            ori = ori.turnLeft();
        } 
    };
}

Instruction& Instructions::left()
{
    static LeftInstruction left;
    return left;
}

RepeatableInstruction::RepeatableInstruction(const Instruction& ins, int n) 
    : ins(ins), n(n)
{
}

bool RepeatableInstruction::isOutOfBound() const
{
    return n<0 || n>10;
}

void RepeatableInstruction::exec(Coordinate& coor, Orientation& ori) const
{
    if(isOutOfBound()) return;

    for(int i = 0; i < n; ++i)
    {
        ins.exec(coor, ori);
    }
}
