/*
ce programme avec le tx_gpt bloque les clefs de voiture qui ne fonctionnent pas .
*/
#include <My_vw_simple.h>

#define F_CPU 2000000UL

int RX=11;

My_vw_simple my_vw(RX);

unsigned char my_data;

//*********************

void setup(void)
{
  Serial.begin(9600);
//pinMode(RX,INPUT);
my_vw.rx_init();
my_data=0;
my_vw.start('1');
}
//************


//****************

void loop()
{

my_data=my_vw.get_data('1');
Serial.println(my_data);

_delay_ms(50);

}