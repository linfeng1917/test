#include <unistd.h>  
#include <stdio.h>  
int main ()   
{   
    pid_t fpid; //fpid表示fork函数返回的值  
    int count=0;  
    fpid=fork();   
    if (fpid < 0)   
        printf("error in fork!");   
    else if (fpid == 0) {  
        while(1)
		{
			printf("i am the child process, my process id is %d\n",getpid());   
        	count++; 
			sleep(1);
		}
    }  
    else {  
		while(1)
		{
        	printf("i am the parent process, my process id is %d\n",getpid());   
        	count++;
			sleep(1);
		}
    }  
    printf("统计结果是: %d/n",count);  
    return 0;  
}  
