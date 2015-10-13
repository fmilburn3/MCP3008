# MCP3008
MCP3008 Analog to Digital Conversion library for Energia

The MCP3208 is a 10bit, 8 channel, Serial Peripheral Interface (SPI) Analog to Digital Converter that can used in single or double ended operation.  This library is for single ended operation only.  The library uses hardware SPI.

Pin Connections
---------------
Pins 1 - 8 are connected to the analog inputs.  Pins 9 - 16 can be connected to the LaunchPad as shown below:
  
MCP3008   LaunchPad
16   -->   3V3
15   -->   3V3
14   -->   GND
13   -->   7      (CLK)
12   -->   14     (MISO)
11   -->   15     (MOSI)
10   -->   8      (CS)
9    -->   GND

Tested on the following boards using Energia 0101E0016

* CC3200-LAUNCHXL Rev 4.1 (80 MHz) EMT
* CC3200-LAUNCHXL Rev 4.1 (80 MHz)
* MSP-EXP432P401R (48 MHz) EMT
* MSP430F5529 Rev 1.5 (25 MHz)
* MSP-EXP430FR5969 Rev 2.0 (16 MHz)
* MSP-EXP430G2553 Rev 1.5 (16 MHz)

Usage
  
- Instantiate with the chip select pin
- Call **begin()** when starting up
- Call **read(pin)** with a single MCP3008 pin to be read when a conversion to digital is desired
- Call **end()** to end SPI

Created by Frank Milburn October 2015 and released into the public domain

