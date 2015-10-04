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
};

struct RepeatableInstruction : Instruction
{
    RepeatableInstruction(const Instruction&, int n);   
private:
    virtual void exec(Coordinate&, Orientation&) const; 
    bool isOutOfBound() const;
private:
    const Instruction& ins;
    const int n;
};

#define REPEAT(instruction, n) RepeatableInstruction(instruction, n)
#define UP Instructions::up()
#define DOWN Instructions::down()
#define FORWARD Instructions::forward()
#define LEFT Instructions::left()
#define RIGHT REPEAT(LEFT, 3)
#define ROUND REPEAT(LEFT, 2)
#define FORWARD_N(n) REPEAT(FORWARD, n)
#define UP_N(n) REPEAT(UP, n)
#define DOWN_N(n) REPEAT(DOWN, n)

#endif
