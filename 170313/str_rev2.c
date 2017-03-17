#include<stdio.h>
#include<string.h>
char *str_rev2(char *str, int bit)
{
	char temp[128];
	int i,j;
	int str_len = strlen(str);
	bit = bit%str_len;

	for(i=0;i<bit;i++)
		*(temp+i) = *(str+i);
	for(i=0;i<str_len-bit;i++)
		*(str+i) = *(str+i+bit);
	for(j=0;j<bit;j++)
		*(str+i+j) = *(temp+j);
	return str;
}

int count_bit(int value)
{
	int temp,i = 0;
	for(temp=0x80;temp!=0;temp>>=1)
	{
		printf("the temp is %d\n",temp);	
		if(value&temp)
			i++;
		printf("the i is %d\n",i);
	}
	printf("in here %s\n",__func__);
	return i;
}

int main(int argc, const char *argv[])
{
	char s[] = "how are you";
	int a = 0x77;
	printf("%s\nafter revert is %s\n",s,str_rev2(s,3)); 
	printf("get the 0x77 1 is %d\n",count_bit(a));
	return 0;
}
