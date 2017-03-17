/*
 *
 *used define to redefine printf
 *
 */
#include<stdio.h>
#define LOG_DEBUG "DEBUG"
#define LOG_TARCE "TARCE"
#define LOG_ERROR "ERROR"
#define LOG_INFO "INFOR"
#define LOG_CRIT "CRTCL"

#define LOG(level, format, ...) \
	do{\
		fprintf(stderr,"%s %s %s %d" format "\n", \
				level, __func__, __FILE__, __LINE__, ##__VA_ARGS__);\
	}while(0)

#define ERROR(fmt, args...) \
	do{                      \
		fprintf(stderr, fmt, ##args);\
	}while(0)
int main(int argc, const char *argv[])
{
	LOG(LOG_DEBUG,"a=%d",10);
	ERROR("test to printf\n");
	return 0;
}

