#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
main()
{
	pid_t val;
	printf("PID before fork():%d\n",(int)getpid());
	if(val=fork())
		printf("parent process PID:%d\n",(int)getpid());
	else
		printf("child process PID:%d\n",(int)getpid());
}
