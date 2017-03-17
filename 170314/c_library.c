/*
 * rewrite c library
 */

#include<stdio.h>
#include<assert.h>
/*convert character to uppercase */
const char *toupper(char*s)
{
	int temp;
	temp = 'a' - 'A';
	for(char *t=s;*t!='\0';t++)
		if(*t>='a'&&*t<='z')
			*t+=temp;
	return s;
}

/* copies character between buffers*/
void *mymemcpy(void *dest,const void *src,size_t count)
{
	assert((dest!=NULL)&&(src!=NULL));
	char *tmp_dest = (char*)dest;
	char *tmp_src = (char*)src;
	if(tmp_dest+count<tmp_src||tmp_src+count<tmp_dest)
	{ // 如果没有重叠区
		while(count--)
			*tmp_dest++ = *tmp_src++;
	}
	else
	{// 如果有重叠区
		tmp_dest+=count-1;
		tmp_src+=count-1;
		while(count--)
			*--tmp_dest = *--tmp_src;
	}
	return dest;
}

/* sets buffers to a specified character*/
void *mymemset(void *src,int c,size_t count)
{
	assert(src!=NULL);
	char *tmpsrc = (char*)src;
	while(count--)
		*tmpsrc++=(char)c;
	return src;
}

/*finds character in a buffer*/
void *mymemchr(const void *src, int c, size_t count)
{
	assert(src!=NULL);
	char *tmp_src = (char*)src;
	while(count&&*tmp_src!=(char)c)
	{
		count--;
		tmp_src++;
	}
	if(count!=0)
		return tmp_src;
	else
		return NULL;
}

/*copy a string*/
void mystrcpy(char *strDest, const char *strSrc)
{
	assert((strDest!=NULL)&&(strSrc!=NULL));
	while(*strSrc!='\0')
		*strDest++ = *strSrc++;
	*strDest = '\0';
}

char *strcpy1(char *strDest, const char *strSrc)
{
	assert((strDest!=NULL)&&(strSrc!=NULL));
	char *address = strDest;
	while((*strDest++ = *strSrc++)!='\0');
	return address;
}

/* append a string */
char *mystrcat(char *str1, const char *str2)
{
	assert((str1!=NULL)&&(str2!=NULL));
	while(*str1!='\0')
		str1++;
	while((*str1++ = *str2++)!='\0');
	return str1;
}

/* compare strings */
int mystrcmp(const char *str1, const char *str2)
{
	assert((str1!=NULL)&&(str2!=NULL));
	for(;*str1==*str2;str1++,str2++)
		if(('\0' == *str1)||('\0' == *str2))
			if(*str1 == *str2)
				return 0;
			else
				break;
	return ((*str1>*str2)?1:-1);
}

/* find substr in str */
char *mystrstr(char *str1, const char *str2)
{
	assert((str1!=NULL)&&(str2!=NULL));
	int n;
	if(*str2)
	{
		while(*str1)
		{
			for(n=0; *(str1+n)==*(str2+n); n++)
			{
				if(*(str2+n+1))
					return str1;
			}
		}
		return NULL;
	}
	else
		return str1; 
}

/* used special mark to split string */
void *mystrtok(char *src, const char *delim)
{
	assert((src!=NULL)&&(delim!=NULL));
	int n;
	char *temp = (char*)src;
	if(*delim)
	{
		while(*src)
		{
			for(n=0;*(src+n)==*(delim+n);n++)
			{
				if(!*(delim+n+1))
				{
					while(*src++)
						*src = '\0';
					return temp;
				}
			}
			src++;
		}
	}
	else
		return src;
}
