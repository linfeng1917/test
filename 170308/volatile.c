#include<stdio.h>
int main(int argc, const char *argv[])
{
	volatile char p;
	p = 0x01;
	p = 0x02;
	printf("p %d\n",p);
	return 0;
}
