#include<stdio.h>
int N(int n)
{
	if(!n)
		return 1;
	else
		return (n*N(n-1));
}

int main(int argc, const char *argv[])
{
	int i;
	for(i=0;i<4;i++)
	{
		printf("i! is %d\n",N(i));
	}
	return 0;
}
