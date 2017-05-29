#include "SparkFun_Si7021_Breakout_Library.h"
#include <Wire.h>

float humidity = 0;
float tempf = 0;
float tempC = 0;

//Create Instance of HTU21D or SI7021 temp and humidity sensor and MPL3115A2 barrometric sensor
Weather sensor;

//---------------------------------------------------------------
void setup()
{
    Serial.begin(9600);   // open serial over USB at 9600 baud

    Serial.println("setup");

    //Initialize the I2C sensors and ping them
    sensor.begin();

}
//---------------------------------------------------------------
void loop()
{
  //Get readings from all sensors
  //Measure Relative Humidity from the HTU21D or Si7021
  humidity = sensor.getRH();

  //Measure Temperature from the HTU21D or Si7021
  tempf = sensor.getTempF();

  //Calc to Celsius
  tempC = (tempf-32)/1.8;

  Serial.print("Temp:");
  Serial.print(tempC);
  Serial.print(" °C, ");

  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.println(" %");
  
  delay(1000);

}

