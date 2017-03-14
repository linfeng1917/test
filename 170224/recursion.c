#include<stdio.h>

int GetAge(int num)
{
	if(num == 1)
		return 10;
	return GetAge(num-1)+2;
}

int main(int argc, const char *argv[])
{
	int age;
	scanf("%d",&age);
	printf("the age is %d\n",GetAge(age));
	return 0;
}
