#include<stdio.h>
int main(int argc, const char *argv[])
{
	int i,j, a[3][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			a[i][j] = i+j;
	printf("a,%d,*a,%d,**a,%d\n",a,*a,**a);
	return 0;
}
