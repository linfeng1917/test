#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* revert(char* src,int n)
{
	int len,i,j;
	len = strlen(src);
	char p[len+1] ;
	char* temp = (char*)(src+len-1);
	char *ptest = (char*)p;
	printf("src is %s len is %d\n",src,len);
	for(j=0;j<len;j++)
	{
		*ptest++ = *temp--;
		//p[j] = *ptest;
		printf("ptest is %c ,temp is %c p is %c\n",*(ptest-1),*temp,p[j]);
	}
	*ptest = '\0';
/*	for(i=0;i<n;i++)
	{
		for(j=0;j<len;j++)
		{
			*ptest++=*temp--;
		}
		*ptest = '\0';
		ptest = ptest - len;
		temp = temp +len ;
	}*/
//	ptest = ptest + len;
//	printf("p is %c,%c,%s\n",*p,*(p-len),ptest);
	for(i=0;i<5;i++)
		printf(" p i is %c ,%d\n",p[i],i);
	strcpy(src,p);  
	return src;
}
int main(int argc, const char *argv[])
{
	char test[] = "howareyou";
	revert(test,3);
	printf("test is %s\n",test);
	return 0;
}
