/*
 *to test char int double how to storage
 *the address of a unit with one byte of date 
 *
 */
#include<stdio.h>
int main(int argc, const char *argv[])
{
	double *p = (double*)malloc(10*sizeof(double));
	int i;
	for(i=0; i<10; i++)
		*(p+i) = 97-i;
	for(i=0; i<10; i++)
		printf("%p p+%d \n", p+i, i);
	free(p);
	return 0;
}
