#include <stdlib.h>
#include <string.h>
#include <GU7000_Interface.h>
#include <Noritake_VFD_GU7000.h>
#include <alloca.h>
#if (defined(__AVR__))
#include <avr/pgmspace.h>
#else
#include <pgmspace.h>
#endif



void Noritake_VFD_GU7000::GU7000_clearScreen() {
    command(0x0c);
}

void Noritake_VFD_GU7000::GU7000_init() {
    io->init();
    command(0x1b);
    command('@');
}

void Noritake_VFD_GU7000::GU7000_reset() {
    io->hardReset();
}

void Noritake_VFD_GU7000::GU7000_setScreenBrightness(unsigned level) {
    if (level == 0)
        GU7000_displayOff();
    else if (level <= 100) {
        GU7000_displayOn();
        command(0x1f, 'X', (level*10 + 120)/125);
    }
}

void Noritake_VFD_GU7000::GU7000_displayOff() {
    us_command('a', 0x40);
    command(0);
}

void Noritake_VFD_GU7000::GU7000_displayOn() {
    us_command('a', 0x40);
    command(0x01);
}

void Noritake_VFD_GU7000::GU7000_drawImage(unsigned width, uint8_t height, const uint8_t *data) {
    if (height > this->height) return;
    us_command('f', 0x11);
    command_xy(width, height);
    command((uint8_t) 1);
    for (unsigned i = 0; i<(height/8)*width; i++)
        command(data[i]);
}

void Noritake_VFD_GU7000::command(uint8_t data) {
    io->write(data);
}
void Noritake_VFD_GU7000::command_xy(unsigned x, unsigned y) {
    command(x);
    command(x>>8);
    y /= 8;
    command(y);
    command(y>>8);
}
void Noritake_VFD_GU7000::command_xy1(unsigned x, unsigned y) {
    command(x);
    command(x>>8);
    command(y);
    command(y>>8);
}

void Noritake_VFD_GU7000::us_command(uint8_t group, uint8_t cmd) {
   command(0x1f);
   command(0x28);
   command(group);
   command(cmd);
}

void Noritake_VFD_GU7000::command(uint8_t prefix, uint8_t group, uint8_t cmd) {
   command(prefix);
   command(group);
   command(cmd);
}


void Noritake_VFD_GU7000::GU7000_drawImage_p(unsigned width, uint8_t height, const uint8_t *data) {
    if (height > this->height) return;
    us_command('f', 0x11);
    command_xy(width, height);
    command((uint8_t) 1);
    for (unsigned i = 0; i<(height/8)*width; i++)
        command(pgm_read_byte(data+i));
}
