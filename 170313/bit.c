#include<stdio.h>
#define BIT3 (0x01 << 3)

static int a;

void set_bit3(void)
{
	a |=BIT3;
}

void clear_bit3(void)
{
	a &= ~BIT3;
}
