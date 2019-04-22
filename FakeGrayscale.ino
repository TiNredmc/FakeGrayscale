/* THIS CODE IS DESIGNED FOR ESP-01S. Other MCU might works */
/* This idea is seems useful but not tested. If you see this code. please help to contribute and test this code */

#include <GU7000_Interface.h> // include the Interface header
#include <GU7000_Serial_Async.h> // include the Async interface header
#include <Noritake_VFD_GU7000.h> // include the main header
#include "BMPs.h" // include our bitmaps hex code (this will put in the MCU's flash)

GU7000_Serial_Async interface(115200,1, 4, 3); // BAUD RATE,SIN(pin TX),BUSY(pin GPOIO2 or pin 4),RESET(pin RX)

Noritake_VFD_GU7000 vfd; 

void setup() {
  pinMode(1, FUNCTION_3); // set pinMode for the TX as GPIO1
  pinMode(3, FUNCTION_3); // set pinMode for the RX as GPIO3
  _delay_ms(700);           // wait for device to power up
  vfd.begin(280, 16);       // In this case. I use GU280X16G-7000 VFD module.
  vfd.interface(interface); // select which interface to use. In this case I use Async interface (It's actually RS232)
  vfd.isModelClass(7000); // My display is -7000. GU7000 series have a lots of 
  //vfd.isGeneration('B');    // Uncomment this for B generation
  vfd.GU7000_reset();       // reset module. to clear everthing remain on the memory and display.
  vfd.GU7000_init();        // initialize module
}

void loop() {
  //start loop for our FakeGreyScale
  
  vfd.command(0x0c); // clear Display before next bitmap
  vfd.command(0x1f, 0x58, 2); // set brightness for the first frame at 2nd level
  vfd.GU7000_drawImage_p(280, 16, d10); // send out the first frame bitmap to the display 
  
  vfd.command(0x0c); //clear Display before next bitmap
  vfd.command(0x1f, 0x58, 4); // set brightness for the sencond frame at 4th level
  vfd.GU7000_drawImage_p(280, 16, d20); // send out the second frame bitmap to the display
  
  vfd.command(0x0c); // clear Display before next bitmap
  vfd.command(0x1f, 0x58, 6); // set brightness for the third frame at 6th level
  vfd.GU7000_drawImage_p(280, 16, d33); // send out the thrid frame bitmap to the display
  
  vfd.command(0x0c); // clear Display before next bitmap 
  vfd.command(0x1f, 0x58, 8); // set brightness for the fourth frame at 8th level
  vfd.GU7000_drawImage_p(280, 16, d56); // send out the fourth frame bitmap to the display
  
}
