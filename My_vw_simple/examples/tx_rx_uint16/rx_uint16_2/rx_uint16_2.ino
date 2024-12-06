
#include <My_vw_simple.h>

#define F_CPU 2000000UL

int RX=11;

My_vw_simple my_vw(RX);

unsigned char my_low , my_high;
unsigned char a,b;

//*********************

void setup(void)
{
  Serial.begin(9600);
my_vw.rx_init(); 
my_low=0;
my_high=0;

}
//************


//****************

void loop()
{
//*********************
my_vw.start('1');
my_low=(my_vw.get_data('1'));// si get_data(j) avec j>9 alors ecrire par ewemple get_data((unsigned char)13) et non get_data('13');
//_delay_ms(1);
my_vw.start('5');//'1' and '5' are the same as in tx .
my_high=(my_vw.get_data('5'));// for get_data(j) , if j>9 use get_data((unsiged char)j), get_data((unsiged char)13) not get_data('13')

uint16_t y = (my_high<<8)|my_low;

Serial.println(y);
_delay_ms(50);
}