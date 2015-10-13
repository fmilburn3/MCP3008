/*
  MCP3008 is an Energia library for the MCP3008 ADC.
  
  The MCP3208 is a 10bit, 8 channel, Serial Peripheral Interface (SPI) Analog to Digital Converter
  that can used in single or double ended operation.  This library is for single ended operation
  only.  The library uses hardware SPI.

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

#ifndef MCP3008_h
#define MCP3008_h

#include <Energia.h>
#include <SPI.h>

// MCP3008 channel addresses and instructions
const byte adcChannelAddresses[] =
{
  (0x08),                                // channel 0
  (0x09),                                // channel 1
  (0x0A),                                // channel 2  
  (0x0B),                                // channel 3             
  (0x0C),                                // channel 4             
  (0x0D),                                // channel 5             
  (0x0E),                                // channel 6             
  (0x0F)                                 // channel 7
};

class MCP3008
{
  public:
    MCP3008(int chipSelectPin);
    int begin();
    int read(int adcPin);
    int end();
  private:
    int _chipSelectPin;
    int _adcPin;
};

#endif  // MCP3008_h
