#include "Arduino.h"
#include <stddef.h>

#ifdef __AVR__
  #include <util/delay.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
  #define _delay_ms(ms) delayMicroseconds((ms) * 1000)
  #define _delay_us(us) delayMicroseconds((us) * 100000)
#endif

#define DIRECTION(X,D)	if (D) pinMode(X##_PIN, OUTPUT); else pinMode(X##_PIN, INPUT)
#define RAISE(X)	digitalWrite(X##_PIN, HIGH)
#define LOWER(X)	digitalWrite(X##_PIN, LOW)
#define CHECK(X)	digitalRead(X##_PIN)



class GU7000_Interface{
public:
    virtual void init() = 0;
    virtual void write(uint8_t data) = 0;
    virtual void hardReset() = 0;
	
	unsigned getModelClass;
};

