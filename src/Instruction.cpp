#include "Instruction.h"
#include "Coordinate.h"
#include "Orientation.h"
#include "base/Singleton.h"
#include "base/Keywords.h"

Instruction& Instructions::up()
{
    DEF_SINGLETON(UpInstruction) EXTENDS(Instruction)
    {
    private:
        virtual void exec(Coordinate& coor, Orientation&) const
        {
            coor = coor.up();
        } 
    };

    return UpInstruction::getInstance();
}

Instruction& Instructions::down()
{
    DEF_SINGLETON(DownInstruction) EXTENDS(Instruction)
    {
    private:
        virtual void exec(Coordinate& coor, Orientation&) const
        {
            coor = coor.down();
        } 
    };

    return DownInstruction::getInstance();
}

Instruction& Instructions::forward()
{
    DEF_SINGLETON(ForwardInstruction) EXTENDS(Instruction)
    {
    private:
        virtual void exec(Coordinate& coor, Orientation& ori) const
        {
            coor = coor.forward(ori);
        } 
    };

    return ForwardInstruction::getInstance();
}

Instruction& Instructions::left()
{
    DEF_SINGLETON(LeftInstruction) EXTENDS(Instruction)
    {
    private:
        virtual void exec(Coordinate&, Orientation& ori) const
        {
            ori = ori.turnLeft();
        } 
    };

    return LeftInstruction::getInstance();
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
