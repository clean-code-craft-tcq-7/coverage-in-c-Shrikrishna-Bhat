#pragma once

typedef enum {
  PASSIVE_COOLING = 0,
  HI_ACTIVE_COOLING = 1,
  MED_ACTIVE_COOLING = 2
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef struct{
  int lowerLimit;
  int upperLimit;
}coolingLimitType;

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
extern coolingLimitType TypesOfLimitCooling(CoolingType coolingType);
