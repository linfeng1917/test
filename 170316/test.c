#include<stdio.h>

void test(int **p)
{
	*p+=1;
}

int main(int argc, const char *argv[])
{
	char *n,m[10];
	unsigned char cnt;
	n=m;
	for(cnt=0;cnt<10;cnt++)
		m[cnt]=cnt;
	test(&n);
	printf("n is %d\n",*n);
	return 0;
}
