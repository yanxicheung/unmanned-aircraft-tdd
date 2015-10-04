#ifndef _INCL_INSTRUCTION_H_
#define _INCL_INSTRUCTION_H_

struct Coordinate;
struct Orientation;

struct Instruction
{
    virtual void exec(Coordinate&, Orientation&) const = 0; 
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
    
    static Instruction& repeat(const Instruction&, int n);
};

#define REPEAT(instruction, n) Instructions::repeat(instruction, n)
#define UP Instructions::up()
#define DOWN Instructions::down()
#define FORWARD Instructions::forward()
#define LEFT Instructions::left()
#define RIGHT Instructions::right()
#define ROUND Instructions::round()
#define FORWARD_N(n) REPEAT(FORWARD, n)
#define UP_N(n) REPEAT(UP, n)
#define DOWN_N(n) REPEAT(DOWN, n)

#endif
