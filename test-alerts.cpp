#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "string.h"

BatteryCharacter batteryCharacter1;
BatteryCharacter batteryCharacter2;

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
  /* sendToController testcases */
TEST_CASE("sendToController NORMAL")
{
  sendToController(NORMAL);
}
TEST_CASE("sendToController TOO_LOW")
{
  sendToController(TOO_LOW);
}
TEST_CASE("sendToController TOO_HIGH")
{
  sendToController(TOO_HIGH);
}

/* checkAndAlert testcases */
/* TO_EMAIL PASSIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH */
TEST_CASE("send email alert high -> TO_EMAIL PASSIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH")
{
  batteryCharacter1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, 50);
}
/* TO_EMAIL PASSIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW */
TEST_CASE("send email alert low -> TO_EMAIL PASSIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW")
{
  batteryCharacter1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, -1);
}
/* TO_EMAIL PASSIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL */
TEST_CASE("send email alert low -> TO_EMAIL PASSIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL")
{
  batteryCharacter1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, 0);
}

/* TO_CONTROLLER PASSIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH */
TEST_CASE("To controller alert high -> TO_CONTROLLER PASSIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH")
{
  batteryCharacter1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, 50);
}
/* TO_CONTROLLER PASSIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW */
TEST_CASE("To controller alert low -> TO_CONTROLLER PASSIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW")
{
  batteryCharacter1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, -1);
}
/* TO_CONTROLLER PASSIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL */
TEST_CASE("To controller alert low -> TO_CONTROLLER PASSIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL")
{
  batteryCharacter1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, 0);
}

/* TO_EMAIL HI_ACTIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH */
TEST_CASE("send email alert high -> TO_EMAIL HI_ACTIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH")
{
  batteryCharacter1.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, 50);
}
/* TO_EMAIL HI_ACTIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW */
TEST_CASE("send email alert low -> TO_EMAIL HI_ACTIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW")
{
  batteryCharacter1.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, -1);
}
/* TO_EMAIL HI_ACTIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL */
TEST_CASE("send email alert low -> TO_EMAIL HI_ACTIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL")
{
  batteryCharacter1.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, 0);
}

/* TO_CONTROLLER HI_ACTIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH */
TEST_CASE("To controller alert high -> TO_CONTROLLER HI_ACTIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH")
{
  batteryCharacter1.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, 50);
}
/* TO_CONTROLLER HI_ACTIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW */
TEST_CASE("To controller alert low -> TO_CONTROLLER HI_ACTIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW")
{
  batteryCharacter1.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, -1);
}
/* TO_CONTROLLER HI_ACTIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL */
TEST_CASE("To controller alert low -> TO_CONTROLLER HI_ACTIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL")
{
  batteryCharacter1.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, 0);
}

/* TO_EMAIL MED_ACTIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH */
TEST_CASE("send email alert high -> TO_EMAIL MED_ACTIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH")
{
  batteryCharacter1.coolingType = MED_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, 50);
}
/* TO_EMAIL MED_ACTIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW */
TEST_CASE("send email alert low -> TO_EMAIL MED_ACTIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW")
{
  batteryCharacter1.coolingType = MED_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, -1);
}
/* TO_EMAIL MED_ACTIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL */
TEST_CASE("send email alert low -> TO_EMAIL MED_ACTIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL")
{
  batteryCharacter1.coolingType = MED_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL, batteryCharacter1, 0);
}

/* TO_CONTROLLER MED_ACTIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH */
TEST_CASE("To controller alert high -> TO_CONTROLLER MED_ACTIVE_COOLING inferBreach:TOO_HIGH sendToEmail:TOO_HIGH")
{
  batteryCharacter1.coolingType = MED_ACTIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, 50);
}
/* TO_CONTROLLER MED_ACTIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW */
TEST_CASE("To controller alert low -> TO_CONTROLLER MED_ACTIVE_COOLING inferBreach:TOO_LOW sendToEmail:TOO_LOW")
{
  batteryCharacter1.coolingType = MED_ACTIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, -1);
}
/* TO_CONTROLLER MED_ACTIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL */
TEST_CASE("To controller alert low -> TO_CONTROLLER MED_ACTIVE_COOLING inferBreach:NORMAL sendToEmail:NORMAL")
{
  batteryCharacter1.coolingType = MED_ACTIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryCharacter1, 0);
}
