#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *mystrstr(char *s1, char *s2);

int main(int argc, const char *argv[])
{
	char *s = "Golden Global View";
	char *l = "oba";
	char *p;
	p = mystrstr(s,l);
	if(p!=NULL)
	{
		printf("%s\n",p);
	}
	else
	{
		printf("Not Found!\n");
	}
	return 0;
}

char *mystrstr(char *s1, char *s2)
{
	int n,i=0;
	if(*s2)
	{
		while(*s1)
		{
			for(n=0;*(s1+n)==*(s2+n);n++)
				if(!*(s2+n+1))
					return (char*)(s1-i);
			i++;
			s1++;
		}
		return NULL;
	}
	else
	{
		return (char*)s1;
	}
}
