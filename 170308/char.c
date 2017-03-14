#include<stdio.h>
#include<string.h>
int main(int argc, const char *argv[])
{
	char a;
	char *b = &a;
	strcpy(b,"this is to test");
	printf("b %s",b); 
	return 0;
}
