#include<stdio.h>
#include<assert.h>
char *mystrstr(char *s1, char *s2);
char *mystrtok(char *s1, char *s2);

int main(int argc, const char *argv[])
{
	char *s = "Golden Global View";
	char *l = "oba";
	char *p;
/*	p = mystrstr(s,l);
	if(p!=NULL)
	{
		printf("%s\n",p);
	}
	else
	{
		printf("Not Found!\n");
	}*/
	p = mystrtok(s,l);
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
	assert((s1!=NULL)&&(s2!=NULL));
	int n;
	if(*s2)
	{
		while(*s1)
		{
			for(n=0;*(s1+n)==*(s2+n);n++)
				if(!*(s2+n+1))
				{
					return s1;
				}
			s1++;
		}
		return NULL;
	}
	else
	{
		return (char*)s1;
	}
}

char *mystrtok(char *s1, char *s2)
{
	assert((s1!=NULL)&&(s2!=NULL));
	int n;
	char *temp = s1;
	if(*s2)
	{
		while(*s1)
		{
			for(n=0;*(s1+n)==*(s2+n);n++)
				if(!*(s2+n+1))
				{
					while(*s1)
					{
						*s1 = '\0';
						s1++;
					}
					return temp;
				}
			s1++;
		}
		return NULL;
	}
	else
	{
		return (char*)s1;
	}
}
