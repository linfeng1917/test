/*
 *
 *目的:关于林锐内存思考
 *
 *data:2017/03/16
 *
 *
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* GetMemory(char *p)
{
	p = (char*)malloc(100);
	printf("p address is %p\n",p);
	return p;
}

void Test(void)
{
	char *str = NULL;
	/*char d;
	str = &d; //解决方案1 无效*/
	printf("str = %p\n",str);

	GetMemory(str);
//	str = GetMemory(str); // 方案2 是可行的 用函数返回值来搞
	printf("str = %p\n",str);

	strcpy(str,"hello world\n");
	printf(str);// 虽然这个只会报waring 但我不建议你这样写
	printf("str is %s",str);
}
// 程序崩溃, GetMemory() 不能动态传递内存 str 是NULL 赋值使程序崩溃

char *GetMemory2(void)
{
	char p[] = "hello world";
	return p;
}

void Test2(void)
{
	char *str = NULL;
	str = GetMemory2();
	printf("str is %s\n",str);
}
// 可能是乱码 原内容被清除,新内容不可知

void GetMemory3(char **p, int num)
{
	*p = (char*)malloc(num);
}

void Test3(void)
{
	char *str = NULL;
	GetMemory3(&str, 100);
	strcpy(str,"hello");
	printf("str is %s\n",str);
}
// (1)能够输出hello (2)内存泄露没有free

void Test4(void)
{
	char *str = (char*)malloc(100);
	strcpy(str,"hello");
	free(str);
	if(str != NULL)
	{
		strcpy(str,"word\n");
		printf("str is %s",str);
	}
}
// 函数输出结果 world 篡改动态内存区的内容,后果难以预料 典型的野指针 

void Usage(void)
{
	printf("****************Usage**********************\n");
	printf("        ./linrui num                  \n");
	printf("the num is 1 void GetMemory(char *p) \n\
			2 is  char *GetMemory2(void)         \n\
			3 is void GetMemory3(char **p, int num)\n\
			4 is void Test4(void)                 \n");
	printf("****************Usage**********************\n");
}

int main(int argc, const char *argv[])
{
	if(argc < 2)
	{
		printf("the parameter need 2\n");
		Usage();
		return 1;
	}
	int a;
	a = atoi(argv[1]);
	switch(a)
	{
	case 1:Test();break;
	case 2:Test2();break;
	case 3:Test3();break;
	case 4:Test4();break;
	default:Usage();break;
	}
	return 0;
}
