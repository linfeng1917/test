#include<stdio.h>
void *mymemcpy(void *memTo, void *memFrom, size_t size)
{
	if((memTo == NULL) || (memFrom == NULL))
		return NULL;
	char *tempFrom = (char *)memFrom;
	char *tempTo = (char *)memTo;
	while(size -- > 0)
		*tempFrom++ = *tempTo++;
	return memTo;
}
int main(int argc, const char *argv[])
{
	char string1[]="how are you";
	char des[10] = {0};
	mymemcpy(string1, des,sizeof(string1));
	printf("des %s\n",des);
	return 0;
}
