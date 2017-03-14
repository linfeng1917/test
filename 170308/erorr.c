#include<stdio.h>
//#define ANDROID 1
#ifndef ANDROID 
	#error "ANDROID undefined"
#endif
int main(int argc, const char *argv[])
{
	printf("to test error\n");
	return 0;
}
