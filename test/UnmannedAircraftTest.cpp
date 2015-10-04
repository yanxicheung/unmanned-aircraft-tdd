#include "gtest/gtest.h"
#include "UnmannedAircraft.h"
#include "Instruction.h"

struct UnmannedAircraftTest : testing::Test
{
    void WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(const Instruction& instruction)
    {
        aircraft.on(instruction);
    }

    void THEN_AIRCRAFT_EXECUTE_INSTRUCTION(const Instruction& instruction)
    {
        WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(instruction);
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
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(UP);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,1,N));
}

_TEST(aircraft_should_down_a_step_when_receive_instruction_DOWN)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(UP);
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(DOWN);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

_TEST(aircraft_should_not_move_when_receive_instruction_DOWN_on_the_ground)
{
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(DOWN);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

_TEST(aircraft_should_forward_a_step_when_receive_instruction_FORWARD)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(FORWARD);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,1,0,N));
}

_TEST(aircraft_should_turn_to_WEST_when_receive_instruction_LEFT)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(LEFT);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,W));
}

_TEST(aircraft_should_turn_to_SOUTH_when_receive_instruction_LEFT_2_times)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(LEFT,2));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,S));
}

_TEST(aircraft_should_turn_to_EAST_when_receive_instruction_LEFT_3_times)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(LEFT,3));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,E));
}

_TEST(aircraft_should_back_to_original_direction_when_receive_instruction_LEFT_4_times)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(LEFT,4));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

_TEST(aircraft_should_turn_to_WEST_when_receive_instruction_RIGHT)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(RIGHT);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,E));
}

_TEST(aircraft_should_turn_to_SOUTH_when_receive_instruction_RIGHT_2_times)
{
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(RIGHT,2));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,S));
}

_TEST(aircraft_should_turn_to_EAST_when_receive_instruction_RIGHT_3_times)
{
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(RIGHT,3));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,W));
}

_TEST(aircraft_should_back_to_original_direction_when_receive_instruction_RIGHT_4_times)
{
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(RIGHT,4));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

_TEST(aircraft_should_turn_to_SOUTH_when_receive_instruction_ROUND)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(ROUND);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,S));
}

_TEST(aircraft_should_back_to_original_direction_when_receive_instruction_ROUND_2_times)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(ROUND,2));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

_TEST(aircraft_should_forward_a_step_in_EAST_when_receive_instruction_RIGHT_AND_FORWARD)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(RIGHT);
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(FORWARD);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(1,0,0,E));
}

_TEST(aircraft_should_forward_a_step_in_WEST_when_receive_instruction_LEFT_AND_FORWARD)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(LEFT);
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(FORWARD);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(-1,0,0,W));
}

_TEST(aircraft_should_forward_a_step_in_SOUTH_when_receive_instruction_ROUND_AND_FORWARD)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(ROUND);
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(FORWARD);
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,-1,0,S));
}

_TEST(aircraft_should_forward_n_step_when_receive_instruction_FORWARD_N)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(FORWARD_N(10));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,10,0,N));
}

_TEST(aircraft_should_up_n_step_when_receive_instruction_UP_N)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(UP_N(10));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,10,N));
}

_TEST(aircraft_should_down_n_step_when_receive_instruction_DOWN_N)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(UP_N(10));
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(DOWN_N(10));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

_TEST(aircraft_should_execute_instructions_repeative_when_receive_REPEAT_INSTRUCTION_N)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(FORWARD,5));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,5,0,N));
    
    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(LEFT,1));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,5,0,W));

    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(FORWARD,5));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(-5,5,0,W));

    THEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(UP,5));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(-5,5,5,W));
}

_TEST(aircraft_should_stay_on_original_position_when_receive_repeat_n_out_of_bound)
{
    WHEN_AIRCRAFT_EXECUTE_INSTRUCTION(REPEAT(UP,11));
    THE_AIRCRAFT_SHOULD_BE_AT(Position(0,0,0,N));
}

