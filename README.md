Ra8876LiteTeeensy WIP

Teensy RA8876 Driver using BuyDisplay's ER-TFTM101-1 10.1 inch lcd module tft display w/touch
https://www.buydisplay.com/default/serial-spi-i2c-10-1-inch-tft-lcd-module-dislay-w-ra8876-optl-touch-panel

RAIO RA8876 support documentation can be found here:
http://www.raio.com.tw/en/Support_RA887677.html

Tested and working with PJRC Teensy's T36 and T40.

And possibly with modification for TechToy's HDMI Shield.
Not Tested.

http://www.techtoys.com.hk/BoardsKits/HDMIshield/HDMIshield.htm

Documentation and drivers for this device can be found
at the bottom of the BuyDisplay WEB page for this display.

The TFT panel I have was ordered setup with:
 - SPI 4 wire 40 pin interface
 - 5V Power Supply
 - 10.1" Resistive Touch Controller
 - SD Card Pin interface
 - ER3304-1 Font Chip
 
The current Price is about $74.00 not including shipping.

Teensy connections are through a 4 wire SPI port. Other interface options are available.
The RA8876 TFT controller has the same MISO tri-state problem as the RA8875 has. It needs a 74HCT125 or similar
chip if using more than one device on the same SPI port.

Check out Sumotoy's WEB page for a solution to this problem.
https://github.com/sumotoy/RA8875/wiki/Fix-compatibility-with-other-SPI-devices

*** CONNECTING THE TEENSY TO THE ER-TFTM101-1 ***

40 pin connector pinouts can be found here:
https://www.buydisplay.com/download/interfacing/ER-TFTM101-1_RTP_Interfacing.pdf

More info to come. Working on Docs. Check out the files for more info till then.
