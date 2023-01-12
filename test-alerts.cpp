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
TEST_CASE("classifyTemperatureBreach")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 12) == NORMAL);
}
