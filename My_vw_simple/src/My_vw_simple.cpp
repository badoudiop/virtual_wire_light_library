/*
ce programme avec le tx_gpt bloque les clefs de voiture qui ne fonctionnent pas .
*/
#include "My_vw_simple.h"

#include "Arduino.h"

#define F_CPU 2000000UL

int le_data;

unsigned char receive(void);
void pause(int k);
void envoi_0(void);
void envoi_1(void);

unsigned char get_data1(unsigned char j);

void send_char1(unsigned char x,unsigned char j);

My_vw_simple::My_vw_simple(int pin_data)
{
  	_tx=pin_data ;
	le_data=pin_data;
}

unsigned char receive(void)
{
unsigned char my_data=0;
for(int i=0;i<8;i++)
{
if(digitalRead(le_data)&0x01) my_data|=(1<<i); 
pause(1000);
}
return my_data;
}

void My_vw_simple::start(unsigned char j)
{
while(receive()!=j);
}

void pause(int k)
{
while(k--) _delay_us(1);
}

//**************
unsigned char My_vw_simple::get_data(unsigned char j)
{
return get_data1(j);
}
//*****************
unsigned char get_data1(unsigned char j)
{
  unsigned char my_data=0, my_data1=0;
  for(int i=0; i<1;i++)// le for à un tour pour les continue qui ne dfonctionnent que dans une boucle ; sans for il y a erreur .
  {
while(receive()!=j)continue;//J pour le start , on peut mettre autre chose .
while(receive()!=j+1) continue;

while(receive()!=j+2)continue;

my_data=receive();
//my_data1=receive()  ;
//if(my_data!=(char)~my_data1) continue;

while(receive()!=j+3) continue ;//Z pour le stop , possible de mettre autre chose .
/*
if (isAlphaNumeric(my_data))//teste si le data ne contient que des caractères alphanumériques= chiffres ou lettres alphabet .
Serial.println((char)my_data);
*/
return my_data ;

  }
  
  }


//**************************************

void transmit(unsigned char x)
{
for(int i=0;i<8;i++)
{
if(x&(1<<i)) envoi_1(); else envoi_0();
}

}
//**************
void My_vw_simple::send_char(unsigned char x,unsigned char j)
{
send_char1(x,j);
}
//****************

void send_char1(unsigned char x,unsigned char j)
{
//PORTA=my_data;
transmit(j);
transmit(j+1);
transmit(j+2);
transmit(x);//my_data);
//transmit(~x);
transmit(j+3);
_delay_ms(10);
}


void envoi_1(void)
{
digitalWrite(le_data,HIGH);

pause(1000);
}

void envoi_0(void)
{
digitalWrite(le_data,LOW);
pause(1000);
}


void My_vw_simple::tx_init()
{
pinMode(le_data,OUTPUT);
digitalWrite(le_data,LOW);
pause(10);
}

void My_vw_simple::tx_stop()
{
pinMode(le_data,INPUT);
digitalWrite(le_data,HIGH);
}


void My_vw_simple::rx_init()
{
pinMode(le_data,INPUT);
}

void My_vw_simple::rx_stop()
{
pinMode(le_data,OUTPUT);
}

