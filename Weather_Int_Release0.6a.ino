// wrightmac Labs 2016
// Peter Hein
// version 0.6

#include <LCD5110_Basic.h>
#include <Wire.h>
#include "SPI.h"
#include "DHT.h"
#include "SparkFunBME280.h"
#include <stdint.h>

// DHT22 Connection
// Pin 1   Pin 2   Pin 3   Pin 4
//  Vcc    Data    --      Gnd
//  3.3    10k     --       
//        Resistor  
#define DHTPIN 2
#define DHTTYPE DHT22

// Initialize DHT22 sensor.
DHT dht(DHTPIN, DHTTYPE);
BME280 myBMP;

//The Nokia 5110 LCD
LCD5110 myGLCD(8,9,10,11,12);
    extern uint8_t SmallFont[];
    extern uint8_t MediumNumbers[];
    extern uint8_t BigNumbers[];
    const int bckLghtPin =  7;
    int bckLghtState = LOW;

// High - Low Temps
float highTemp = 0;
float lowTemp = 999;

void setup() {
  Serial.begin(57600);
  // Configure the BME
  myBMP.settings.runMode = 3; //  3, Normal mode
  myBMP.settings.tStandby = 5; //  0, 0.5ms
  myBMP.settings.filter = 0; //  0, filter off
  myBMP.settings.tempOverSample = 2;
  myBMP.settings.pressOverSample = 2;
  myBMP.settings.I2CAddress = 0x76;
  
  delay(250); // allow sensor time to come up with new settings

  // Start the sensors
  dht.begin();
  myBMP.begin();

  // set the digital pin as output:
  pinMode(bckLghtState, OUTPUT);
  pinMode(bckLghtPin, OUTPUT);
   
  // Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.setContrast(60);
}

void loop() {
  analogWrite(bckLghtPin, 255);
  
  // Wait a few seconds between measurements.
  delay(5000);

  // Sensor readings can take up to 250ms
  float dhum = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float dtemp = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float dtfar = dht.readTemperature(true);
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(dtfar, dhum);
  // float hic = dht.computeHeatIndex(t, h, false);
  
  // Vars for BME280 Sensor readings
  int btempf = myBMP.readTempF();
  float bpres = myBMP.readFloatPressure();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(dhum) || isnan(dtfar)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print data reading to the LCD
  myGLCD.clrScr();
  myGLCD.setFont(SmallFont);
  myGLCD.print("TFM Labs Weather", 0, 0);
  myGLCD.print("Temp= ", 0, 16);
  myGLCD.printNumI(dtfar, 37, 16);
  myGLCD.print("*F", 55, 16);
  myGLCD.print("Hum= ", 0, 26);
  myGLCD.printNumI(dhum, 37, 26);
  myGLCD.print("%", 55, 26);
  myGLCD.print("Pres= ", 0, 36);
  myGLCD.printNumI(bpres, 37, 36);
  myGLCD.print(" atm", 54, 36);

  // Check High-Low
  if (dtfar > highTemp) {
    highTemp = dtfar;
  }
  if (dtfar < lowTemp) {
    lowTemp=dtfar;
  }
  // Project idea, add an LED to the board
  // turn it on if a max or min temp is reached

  // wait before changing screens
  delay(5000);
  myGLCD.clrScr();
  myGLCD.print("High Temp", CENTER, 0);
  myGLCD.printNumI(highTemp, CENTER, 16);
  myGLCD.print("Low Temp", CENTER, 26);
  myGLCD.printNumI(lowTemp, CENTER, 36);

  // Wait for it . . . 
  delay(5000);
  
  // Print data to serial using CVS format
  // for later analysis
  // save to SD card or ship over WiFI
  Serial.print(dtemp);
  Serial.print(",");
  Serial.print(dtfar);
  Serial.print(",");
  Serial.print(dhum);
  Serial.print(",");
  Serial.print(bpres);
  Serial.print(",");
  Serial.println(highTemp);
  Serial.print(",");
}
