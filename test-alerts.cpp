#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "string.h"

TEST_CASE("infers the breach according to limits TOO_LOW")
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
  /* InferBreach testcases */
TEST_CASE("infers the breach according to limits TOO_HIGH")
{
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
}
TEST_CASE("infers the breach according to limits NORMAL")
{
  REQUIRE(inferBreach(20, 20, 20) == NORMAL);
}
  /* classifyTemperatureBreach testcases */
TEST_CASE("classifyTemperatureBreach PASSIVE_COOLING")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 12) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach HI_ACTIVE_COOLING")
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 12) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach MED_ACTIVE_COOLING")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 12) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach TOO_LOW")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
}
TEST_CASE("classifyTemperatureBreach TOO_HIGH")
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 41) == TOO_HIGH);
}
TEST_CASE("classifyTemperatureBreach MED_ACTIVE_COOLING NORMAL")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 12) == NORMAL);
}
