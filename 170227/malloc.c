#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MEMSEZE 1024*1024
/*void test2()
{
	int count=0;
	void *p=NULL;
	while(1)
	{
		P = (void*)malloc(MEMSEZE);
		if(!p) break;
		memset(p,1,MEMSEZE);
		printf("current allocation %d\n",++count);
	}
}*/
int main(int argc, const char *argv[])
{
	int count=0;
	void *p=NULL;
	while(1)
	{
		p = (void*)malloc(MEMSEZE);
		if(!p) break;
		printf("current allocation %d\n",++count);
	}
	return 0;
}
