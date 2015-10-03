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
