/*
transmit 3 char redeived and displayed by rx_char .
you can modify to send only one char ; 
if so , modify also rx_char to get only one char .
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
my_data=193;// can be a value mapped to [0;255] such as a value of a resistence ;
my_vw.send_char(my_data,'1');
_delay_ms(10);

my_data=102;//can be a value mapped to [0;255] such as a value of a resistence ;
my_vw.send_char(my_data,'5');
_delay_ms(10);

my_data=108;//can be a value mapped to [0;255] such as a value of a resistence ;
my_vw.send_char(my_data,(unsigned char)13);
_delay_ms(50);

}