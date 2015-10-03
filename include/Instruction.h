#ifndef _INCL_INSTRUCTION_H_
#define _INCL_INSTRUCTION_H_

struct Position;

struct Instruction
{
    virtual void exec(Position&) const = 0; 
    virtual ~Instruction() {}
};

struct Instructions
{
    static Instruction& up();
    static Instruction& down();
    static Instruction& forward();
    static Instruction& left();
    static Instruction& right();
    static Instruction& round();
};

#define UP Instructions::up()
#define DOWN Instructions::down()
#define FORWARD Instructions::forward()
#define LEFT Instructions::left()
#define RIGHT Instructions::right()
#define ROUND Instructions::round()

#endif
