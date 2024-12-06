#ifndef My_vw_simple_h
#define My_vw_simple_h

#include <Arduino.h>

#if ARDUINO >= 100
#include <Arduino.h>       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#endif

class My_vw_simple
{
private :
int _tx  ;

  public:
My_vw_simple(int a);
unsigned char get_data(unsigned char j);
void send_char(unsigned char x,unsigned char j);
void tx_init(void);
void rx_init(void);
void rx_stop();
void tx_stop();
void start(unsigned char j);
};
//extern My_I2C my_i2c ;
#endif

