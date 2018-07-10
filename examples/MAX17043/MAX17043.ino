#include <Wire.h>
#include <MAX17043.h>

MAX17043 fuelGauge(20,4);

void setup(){
  Serial.begin(9600);
   
  Serial.println("Starting up... Alert Threshold should be 20");
  Serial.println("");
  fuelGauge.begin();
  output();
  Serial.println("Setting Alert Threshold to 3");
  fuelGauge.setAlertThreshold(3);
  output();
  Serial.println("Sleeping...");
  fuelGauge.sleep();
  output();
  Serial.println("Waking...");
  fuelGauge.wake();
  output();
  Serial.println("Setting Alert Threshold to 33");
  fuelGauge.setAlertThreshold(33);
  output();
  Serial.println("Setting Alert Threshold to 0");
  fuelGauge.setAlertThreshold(0);
  output();
  Serial.println("Tests Complete");
}

void loop(){
}

void output() {
  Serial.print("Version: ");
  Serial.println(fuelGauge.getVersion());
  Serial.print("Alert Threshold: ");
  Serial.println(fuelGauge.getAlertThreshold());
  Serial.print("Alert Threshold Register Version: ");
  Serial.println(fuelGauge.getAlertThresholdRegister());
  Serial.print("Battery Voltage: ");
  Serial.println(fuelGauge.getBatteryVoltage());
  Serial.print("Battery Percentage: ");
  Serial.println(fuelGauge.getBatteryPercentage());
  Serial.print("Is Alerting? ");
  Serial.println(fuelGauge.isAlerting());
  Serial.print("Is Sleeping? ");
  Serial.println(fuelGauge.isSleeping());
  Serial.print("Is Sleeping Register Version? ");
  Serial.println(fuelGauge.isSleepingRegister()); 
  Serial.println("");
}
