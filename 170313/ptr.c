#include<stdio.h>
int main(int argc, const char *argv[])
{
	int a1[3][3] = {};
	int i,j;
	int (*p)[3];
	p = a1;
	**p = 1;
	*(*(p+1)+1) = 2;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			printf("a%d%d is %d\n",i,j,a1[i][j]);

	printf("a1 is %d\n",a1[0][0]);
	printf("error have happen!\n");
	return 0;
}
