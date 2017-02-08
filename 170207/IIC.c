#include<reg51.h>
#define uchar unsigned char 
#define uint unsigned int 
#define write_ADD 0xa0
#define read_ADD 0xa1

uchar a;
sbit SDA=P2^0;
sbit SCL=P2^1;

void SomeNop();
void init();
void check_ACK(void);
void I2CStart(void);
void I2CStop(void);
void write_byte(uchar dat);
void delay(uint z);
uchar read_byte();
void write_add(uchar addr, uchar dat);
uchar read_add(uchar addr);
bit flag;

void main()
{
	init();
	write_add(5,0xaa);
	delay(10);
	P1=read_add(5);
}

void SomeNop()
{; ;}

void start()
{
	SDA=1;
	SomeNop();
	SCL=1;
	SomeNop();
	SDA=0;
	SomeNop();
}

void stop()
{
	SDA=0;
	SomeNop();
	SCL=1;
	SomeNop();
	SDA=1;
	SomeNop();
}
      
void respons()
{
	uchar i=1;
	SCL=1;
	SomeNop();
	while((SDA==1)&&(i<250)) i++;
	SCL=0;
	delay();
}

void init()
{
	SDA = 1;
	SomeNop();
	SCL = 1;
	SomeNop();
}

void write_byte(uchar data)
{
	uchar mask=0x80,temp;

	for(; mask!=0;mask>>=1)
	{
		temp = data&mask;
		SCL = 0;
		SDA = temp;
		SomeNop();
		SCL = 1;
		SomeNop();
	}

	SCL = 0;
	SomeNop();
	SDA = 1;
	SomeNop();
}

uchar read_byte()
{
	uchar mask,k=0;
	SCL = 0;
	SomeNop();
	SDA = 1;
	SomeNop();
	for(mask=0x80; mask!=0; mask>>=1)
	{
		SCL = 1;
		SomeNop();
		k=(k<<1)|SDA;
		SCL = 0;
		SomeNop();
	}

	return k;
}

void write_add(uchar address, uchar data)
{
	start();
	write_byte(0xa0);
	respons();
	write_byte(address);
	respons();
	write_byte(data);
	respons();
	stop;
}

void read_add(uchar address)
{
	uchar data;
	start();
	write_byte(0xa0);
	respons();
	write_byte(address);
	respons();
	start();
	write_byte(0xa1);
	respons();
	data = read_byte();
	stop();
	return data;  
}
