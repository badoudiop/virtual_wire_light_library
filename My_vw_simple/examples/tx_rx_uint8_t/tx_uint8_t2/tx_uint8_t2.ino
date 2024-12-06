/*
ce programme en fonction avec rx_gpt bloque les clefs de voiture qui sont désactivées .
*/
#include <My_vw_simple.h>

#define F_CPU 2000000UL

 int TX=12 ;
unsigned char my_data;

My_vw_simple my_vw(TX);

void setup()
{
//pinMode(TX,OUTPUT);
my_vw.tx_init();
my_data=0;

}

void loop()
{
my_data=193;//=PIND;
my_vw.send_char(my_data,'1');

_delay_ms(50);

}