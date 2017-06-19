
/*********************************************************************
ESP32 (SunDuino board) with temperature/humidity sensor Si7021 and OLED 128x64 (I2C) 

Websites (EN) https://time4ee.com
(CZ/SK) https://chiptron.cz

ESP32 by https://www.dfrobot.com/product-1559.html 
SunDuino ESP32 by http://www.sunduino.pl/wordpress/esp-wroom-32-czesc-4-esp32-sunduino/ 

Si7021 arduino library by https://learn.sparkfun.com/tutorials/si7021-humidity-and-temperature-sensor-hookup-guide 
OLED 128x64px arduino library by https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples
*********************************************************************/

#include "SparkFun_Si7021_Breakout_Library.h"
#include <Wire.h>

float humidity = 0;
float tempC = 0;

//Create Instance of HTU21D or SI7021 temp and humidity sensor and MPL3115A2 barrometric sensor
Weather sensor;

//---------------------------------------------------------------
void setup()
{
    Serial.begin(9600);   // open serial at 9600 baud

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
  tempC = sensor.getTemp();

  Serial.print("Temp:");
  Serial.print(tempC);
  Serial.print(" °C, ");

  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.println(" %");
  
  delay(1000);

}

