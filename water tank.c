#include<avr/io.h>
#include<util/delay.h>
void lcdcmd(char x)
{
	
	PORTD=x;
	PORTC=0b00000100;
	_delay_ms(100);
	PORTC=0b00000000;
	_delay_ms(100);
}

void lcddata(char x)
{
	PORTD=x;
	PORTC=0b00000101;
	_delay_ms(100);
	PORTC=0b00000001;
	_delay_ms(100);
	
}
void display(char y[])
{
	int i;
	for(i=0;y[i]!='\0';i++)
	
	{
		lcddata(y[i]);
	}
}

void main()
{
	
DDRA=0b00000000;
DDRB=0b11111111;
DDRC=0b11111111;
DDRD=0b11111111;
while(1)
{
	lcdcmd(0x38);
	lcdcmd(0x0E);
	lcdcmd(0X01);
if((PINA==0b00000000)||(PINA==0b00000100))
{
	PORTB=0b000000010;
	display("TANK EMPTY");
	_delay_ms(1000);
}
if(PINA==0b00000110)
{  lcdcmd(0x01);
 display("TANK PARTIALLY FILLED");
 _delay_ms(1000);
}
if(PINA==0b00000111)
{
	PORTB=0b00000000;
	lcdcmd(0x01);
	display(" TANK FULL");
	_delay_ms(1000);
}
}
}