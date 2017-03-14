#include<stdio.h>
#define switch(x,y) {int tmp; tmp=x;x=y;y=tmp;}
int main(int argc, const char *argv[])
{
	int a,b;
	printf("input the number\n");
	scanf("%d,%d",&a,&b);
	if(a>b)
		switch(a,b);
	printf("the min is %d\n",a);
	return 0;
}
