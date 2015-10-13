/*
  Example demonstrating reading and printing all 8 channels of a MCP3008 ADC using
  the MCP3008 Energia library for Texas Instruments LaunchPads.

  Pin Connections
  ---------------
  Pins 1 - 8 are connected to the analog inputs.  Pins 9 - 16 can be connected to the LaunchPad as
  shown below:
  
  MCP3008            LaunchPad
     ___ 
  1 | u | 16   -->   3V3
  2 |   | 15   -->   3V3
  3 |   | 14   -->   GND
  4 |   | 13   -->   7      (CLK)
  5 |   | 12   -->   14     (MISO)
  6 |   | 11   -->   15     (MOSI)
  7 |   | 10   -->   8      (CS)
  8 |___| 9    -->   GND

  Tested with Energia 0101E0016
  * CC3200-LAUNCHXL Rev 4.1 (80 MHz) EMT
  * CC3200-LAUNCHXL Rev 4.1 (80 MHz)
  * MSP-EXP432P401R (48 MHz) EMT
  * MSP430F5529 Rev 1.5 (25 MHz)
  * MSP-EXP430FR5969 Rev 2.0 (16 MHz)
  * MSP-EXP430G2553 Rev 1.5 (16 MHz)
  
  Usage
  -----
  - Instantiate with the chip select pin
  - Call **begin()** when starting up
  - Call **read(pin)** with a single MCP3008 pin to be read when a conversion to digital is desired
  - Call **end()** to end SPI
  
  Created by Frank Milburn October 2015
  Released into the public domain

*/
#include <SPI.h>
#include "MCP3008.h"

const int  chipSelectPin = 8;            // chip select pin - can be changed
const float vRef = 3.23;                 // voltage reference
                                         // change vRef as needed (e.g. 3.52 V for MSP-EXP430G2) 

MCP3008 adc(chipSelectPin);              // instantiate with chip select pin

void setup()
{    
  Serial.begin  (9600);
  adc.begin();                           // start the MCP3008
  Serial.println("Pin Readings (V):");
  Serial.println("  1     2     3     4     5     6     7     8");
  Serial.println("----  ----  ----  ----  ----  ----  ----  ----");
}
 
void loop()
{
// Loop through the MCP3008 pins and print the voltages associated with them  
for (int i = 1; i < 9; i++)
  {
    int adcValue = adc.read(i);           // read a value from the current MCP3008 pin
    float v = adcValue * vRef / 1023;     // convert to voltage
    Serial.print(v, 2);
    Serial.print("  ");
  }
  Serial.println("");
 
  delay(1000);  
}
