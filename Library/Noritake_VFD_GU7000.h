#ifndef NORITAKE_VFD_GU7000_H
#define NORITAKE_VFD_GU7000_H

#include <stdint.h>
#include <stddef.h>

#ifdef __AVR__
  #include <util/delay.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
  #define _delay_ms(ms) delayMicroseconds((ms) * 1000)
#endif


enum ImageMemoryArea {
    FlashImageArea = 1,
    ScreenImageArea = 2
};


class Noritake_VFD_GU7000 {

    void initialState();
    void printNumber(unsigned long number, uint8_t base);
    void printNumber(unsigned x, uint8_t y, unsigned long number, uint8_t base);
    void command(uint8_t data);
    void us_command(uint8_t group, uint8_t cmd);
    void command(uint8_t prefix, uint8_t group, uint8_t cmd);
    void command_xy(unsigned x, unsigned y);
    void command_xy1(unsigned x, unsigned y);
    void crlf();
    
    GU7000_Interface *io;    

public:
    uint8_t width;
    uint8_t height;
    uint8_t lines;
    unsigned modelClass;
    bool	generation; // GU-7***B = true
   

    Noritake_VFD_GU7000() {
        this->modelClass = 7000;
        this->generation = false;
    }

    void interface(GU7000_Interface &interface) {
        io = &interface;
		//io->init();
    }
    
    void begin(uint8_t width, uint8_t height) {
        this->width = width;
        this->height = height;
        this->lines = this->height / 8;
    }
    
    void isModelClass(unsigned modelClass) {
        this->modelClass = modelClass;
		io->getModelClass = modelClass;
    }

    
    void isGeneration(char c) {
        this->generation = toupper(c) == 'B';
    }

    void GU7000_clearScreen();
    void GU7000_init();
    void GU7000_reset();
    void GU7000_displayOn();
    void GU7000_displayOff();    
    void GU7000_setScreenBrightness(unsigned level);
    void GU7000_drawImage(unsigned width, uint8_t height, const uint8_t *data);
    void GU7000_drawImage_p(unsigned width, uint8_t height, const uint8_t *data);
    };
#endif
