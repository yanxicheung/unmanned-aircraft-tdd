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

namespace
{
#define _TEST(scence_description) TEST_F(UnmannedAircraftTest, scence_description)
}

_TEST(at_the_beginning_aircraft_should_at_0_0_0_N)
{
    ASSERT_TRUE(Position(0,0,0,N) == aircraft.getPosition());
}

_TEST(aircraft_should_up_a_step_when_receive_instruction_UP)
{
    WHEN_I_RECEIVE_INSTRUCTION(UP);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,1,N));
}

_TEST(aircraft_should_down_a_step_when_receive_instruction_DOWN)
{
    WHEN_I_RECEIVE_INSTRUCTION(UP);
    THEN_RECEIVE_INSTRUCTION(DOWN);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

_TEST(aircraft_should_not_move_when_receive_instruction_DOWN_on_the_ground)
{
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
    WHEN_I_RECEIVE_INSTRUCTION(DOWN);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

_TEST(aircraft_should_forward_a_step_when_receive_instruction_FORWARD)
{
    WHEN_I_RECEIVE_INSTRUCTION(FORWARD);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,1,0,N));
}

_TEST(aircraft_should_turn_to_WEST_when_receive_instruction_LEFT)
{
    WHEN_I_RECEIVE_INSTRUCTION(LEFT);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,W));
}

_TEST(aircraft_should_turn_to_SOUTH_when_receive_instruction_LEFT_2_times)
{
    WHEN_I_RECEIVE_INSTRUCTION(LEFT);
    THEN_RECEIVE_INSTRUCTION(LEFT);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,S));
}

_TEST(aircraft_should_turn_to_EAST_when_receive_instruction_LEFT_3_times)
{
    WHEN_I_RECEIVE_INSTRUCTION(LEFT);
    THEN_RECEIVE_INSTRUCTION(LEFT);
    THEN_RECEIVE_INSTRUCTION(LEFT);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,E));
}

_TEST(aircraft_should_back_to_original_direction_when_receive_instruction_LEFT_4_times)
{
    WHEN_I_RECEIVE_INSTRUCTION(LEFT);
    THEN_RECEIVE_INSTRUCTION(LEFT);
    THEN_RECEIVE_INSTRUCTION(LEFT);
    THEN_RECEIVE_INSTRUCTION(LEFT);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}
