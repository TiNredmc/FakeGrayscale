/* THIS CODE IS DESIGNED FOR ESP-01S. Other MCU might works */

#include <GU7000_Interface.h>
//#include <GU7000_Parallel.h>
#include <GU7000_Serial_Async.h>
//#include <GU7000_Serial_Sync.h>
//#include <GU7000_Serial_SPI.h>
#include <Noritake_VFD_GU7000.h>
#include "BMPs.h"
// ****************************************************
// ****************************************************
// Uncomment one of the communication interfaces below.
//

GU7000_Serial_Async interface(115200,1, 2, 3); // BAUD RATE,SIN(pin TX),BUSY(pin GPOIO2),RESET(pin RX)
//GU7000_Serial_Sync interface(3, 5, 6, 7); // SIN,BUSY,SCK,RESET
//GU7000_Serial_SPI interface(3, 5, 6, 7, 8); // SIN,BUSY,SCK,RESET,CS
//GU7000_Parallel interface('R', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=RESET; BUSY,RESET,WR,RD,D0-D7
//GU7000_Parallel interface('B', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=BUSY; BUSY,RESET,WR,RD,D0-D7
//GU7000_Parallel interface('N', 8,9,10,11, 0,1,2,3,4,5,6,7); // Module Pin#3=nothing; BUSY,RESET,WR,RD,D0-D7
//
// ****************************************************
// ****************************************************

Noritake_VFD_GU7000 vfd;


void setup() {
  pinMode(1, FUNCTION_3);
  pinMode(3, FUNCTION_3);
  _delay_ms(700);           // wait for device to power up
  vfd.begin(280, 16);       // In this case. I use GU280X16G-7000 VFD module.
  vfd.interface(interface); // select which interface to use. In this case I use Async interface (It's actually RS232)
  vfd.isModelClass(7000);
  //vfd.isGeneration('B');    // Uncomment this for B generation
  vfd.GU7000_reset();       // reset module
  vfd.GU7000_init();        // initialize module
}

void loop() {
  //start loop for our FakeGreyScale
  
  vfd.GU7000_clearScreen(); // clear Display before next bitmap
  vfd.GU7000_setScreenBrightness(1); // set brightness for the first frame 
  vfd.GU7000_drawImage_p(280, 16, d13); // send out the first frame bitmap to the display 
  
  vfd.GU7000_clearScreen(); //clear Display before next bitmap
  vfd.GU7000_setScreenBrightness(2); // set brightness for the sencond frame
  vfd.GU7000_drawImage_p(280, 16, d30); // send out the second frame bitmap to the display
  
  vfd.GU7000_clearScreen(); // clear Display before next bitmap
  vfd.GU7000_setScreenBrightness(4); // set brightness for the third frame 
  vfd.GU7000_drawImage_p(280, 16, d46); // send out the thrid frame bitmap to the display
  
  vfd.GU7000_clearScreen(); // clear Display before next bitmap 
  vfd.GU7000_setScreenBrightness(8); // set brightness for the fourth frame
  vfd.GU7000_drawImage_p(280, 16, d61); // send out the fourth frame bitmap to the display
  
}
