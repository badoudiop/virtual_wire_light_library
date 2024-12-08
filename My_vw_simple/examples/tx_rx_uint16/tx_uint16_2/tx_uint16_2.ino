
#include <My_vw_simple.h>

#define F_CPU 2000000UL

 int TX=12 ;
uint16_t my_data;
unsigned char my_high,my_low;

My_vw_simple my_vw(TX);

void decompose(uint16_t x)
{
my_low=x&0xff;
my_high=(x>>8)&0xff;
}

void setup()
{
//pinMode(TX,OUTPUT);
my_vw.tx_init();
my_data=0;

}

void loop()
{
my_data=45478;//=PIND;
decompose(my_data);
my_vw.send_char(my_low,'1');
_delay_ms(1);
my_vw.send_char(my_high,'5');//5=1+4
_delay_ms(50);
}
