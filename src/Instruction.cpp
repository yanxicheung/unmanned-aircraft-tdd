#include "Instruction.h"
#include "Position.h"

namespace
{
    struct UpInstruction : Instruction
    {
    private:
        virtual void exec(Position& position) const
        {
            position.up();
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
        virtual void exec(Position& position) const
        {
            position.down();
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
        virtual void exec(Position& position) const
        {
            position.forward();
        } 
    };
}

Instruction& Instructions::forward()
{
    static ForwardInstruction forward;
    return forward;
}

