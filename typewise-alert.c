#include "typewise-alert.h"
#include <stdio.h>

static coolingLimitType TypesOfLimitCooling(CoolingType coolingType);
static void MailBreachType(BreachType breachType);

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

static coolingLimitType TypesOfLimitCooling(CoolingType coolingType)
{
  coolingLimitType coolingLimitTypeReturn;
  CoolingType CoolingType_en;
  coolingLimitTypeReturn.lowerLimit = 0;
  coolingLimitTypeReturn.upperLimit = 0;
  
  (coolingType == CoolingType_en) ? coolingLimitTypeReturn.upperLimit = 35 : ((coolingType == CoolingType_en) ? coolingLimitTypeReturn.upperLimit = 45 : coolingLimitTypeReturn.upperLimit = 40);
  
  return coolingLimitTypeReturn;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = 0;
  int upperLimit = 0;
  coolingLimitType coolingTypeReturnValue;
  
  coolingTypeReturnValue = TypesOfLimitCooling(coolingType);
  lowerLimit = coolingTypeReturnValue.lowerLimit ;
  upperLimit = coolingTypeReturnValue.upperLimit ;
  
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch(alertTarget)
  {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

static void MailBreachType(BreachType breachType)
{
  BreachType BreachType_enum;
  
  if (breachType == BreachType_enum)
  {
      printf("Hi, the temperature is too low\n");
  }
  else if (breachType == BreachType_enum)
  {
      printf("Hi, the temperature is too high\n");
  }
  else
  {
    // NORMAL
  }
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  MailBreachType(breachType);
}
