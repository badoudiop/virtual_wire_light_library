/*
receive 3 uint8_t and display them ; 
you can modify to get only one and display it .
*/
#include <My_vw_simple.h>

int RX=11;

My_vw_simple my_vw(RX);

unsigned char my_data;

//*********************

void setup(void)
{
  Serial.begin(9600);
my_vw.rx_init();
my_data=0;
}
//************


//****************

void loop()
{
//my_vw.start('1');
my_data=my_vw.get_data('1');
Serial.print(my_data);
//_delay_ms(10);
Serial.print("  :  ");
//my_vw.start('5');
my_data=my_vw.get_data('5');
Serial.print(my_data);
Serial.print("  :  ");
//my_vw.start((unsigned char)13);
my_data=my_vw.get_data((unsigned char)13);
Serial.println(my_data);

_delay_ms(10);

}