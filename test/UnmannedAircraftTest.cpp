#include "gtest/gtest.h"
#include "UnmannedAircraft.h"

struct UnmannedAircraftTest : testing::Test
{

protected:
    UnmannedAircraft aircraft;
};

TEST_F(UnmannedAircraftTest, at_the_beginning_aircraft_should_at_0_0_0_N)
{
    ASSERT_TRUE(Position(0,0,0,N) == aircraft.getPosition());
}

TEST_F(UnmannedAircraftTest, when_receive_instruction_UP_aircraft_should_up_a_step)
{
    aircraft.on(UP);

    ASSERT_TRUE(Position(0,0,1,N) == aircraft.getPosition());   
}

TEST_F(UnmannedAircraftTest, when_receive_instruction_DOWN_aircraft_should_down_a_step)
{
    aircraft.on(UP);
    aircraft.on(DOWN);

    ASSERT_TRUE(Position(0,0,0,N) == aircraft.getPosition());   
}

TEST_F(UnmannedAircraftTest, when_receive_instruction_FORWARD_aircraft_should_forward_a_step)
{
    aircraft.on(FORWARD);

    ASSERT_TRUE(Position(0,1,0,N) == aircraft.getPosition());   
}
