#include<stdio.h>

char *GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
int main(int argc, const char *argv[])
{
	char *str = NULL;
	str = GetMemory();
	printf("get string is %s\n",str);
	return 0;
}
