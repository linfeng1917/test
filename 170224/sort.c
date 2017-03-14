#include<stdio.h>

void exchange(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
	int n = sizeof(a)/sizeof(int);
	for(int j=0; j<n-1; j++)
		for(int i=0; i<n-1-j; i++)
		{
			if(a[i]>a[i+1])
				exchange(a,i,i+1);
		}
	return 0;
}
