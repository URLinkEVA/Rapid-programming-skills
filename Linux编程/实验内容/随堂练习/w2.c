#include<stdio.h>
#include<unistd.h>
void main()
{
	if(fork())
		printf("this is parent process!\n");
	else
		execl("/bin/ls","ls","-l",0);
	return;
}
