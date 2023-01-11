#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  /* InferBreach testcases */
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(20, 20, 20) == NORMAL);
  /* classifyTemperatureBreach testcases */
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 12) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 12) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 12) == NORMAL);
  
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 41) == TOO_HIGH);
  /*
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 12) == NORMAL);
  */
  /* sendToController testcases */
  REQUIRE(sendToController(NORMAL) == NORMAL);
}
