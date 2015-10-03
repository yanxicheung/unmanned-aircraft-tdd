#include "gtest/gtest.h"
#include "UnmannedAircraft.h"
#include "Instruction.h"

struct UnmannedAircraftTest : testing::Test
{
    void WHEN_I_RECEIVE_INSTRUCTION(const Instruction& instruction)
    {
        aircraft.on(instruction);
    }

    void THEN_RECEIVE_INSTRUCTION(const Instruction& instruction)
    {
        WHEN_I_RECEIVE_INSTRUCTION(instruction);
    }

    void THE_AIRCRAFT_SHOULD_BE_AT(const Position& position)
    {
        ASSERT_TRUE(position == aircraft.getPosition());
    }

protected:
    UnmannedAircraft aircraft;
};

TEST_F(UnmannedAircraftTest, at_the_beginning_aircraft_should_at_0_0_0_N)
{
    ASSERT_TRUE(Position(0,0,0,N) == aircraft.getPosition());
}

TEST_F(UnmannedAircraftTest, when_receive_instruction_UP_aircraft_should_up_a_step)
{
    WHEN_I_RECEIVE_INSTRUCTION(UP);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,1,N));
}

TEST_F(UnmannedAircraftTest, when_receive_instruction_DOWN_aircraft_should_down_a_step)
{
    WHEN_I_RECEIVE_INSTRUCTION(UP);
    THEN_RECEIVE_INSTRUCTION(DOWN);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

TEST_F(UnmannedAircraftTest, aircraft_should_not_move_when_receive_instruction_DOWN_on_the_ground)
{
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
    WHEN_I_RECEIVE_INSTRUCTION(DOWN);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

TEST_F(UnmannedAircraftTest, when_receive_instruction_FORWARD_aircraft_should_forward_a_step)
{
    WHEN_I_RECEIVE_INSTRUCTION(FORWARD);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,1,0,N));
}
