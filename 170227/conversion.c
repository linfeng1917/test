#include<stdio.h>
#include<string.h>
#include<stdlib.h>

conversion(int array[],int n)
{
	int i,j=0,temp;
	for(i=0; i<n; i++)
	{
		if(array[i]<0)
		{
			temp = array[i];
			array[i]=array[j];
			array[j]=temp;
			j++; 
		}

	}
}
