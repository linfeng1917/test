#include<stdio.h>
int main(int argc, const char *argv[])
{
	int a=0;
	char str[] = "how are you\n";
	printf(str,a);
	printf(a);
	fflush(stdin);
	return 0;
}
