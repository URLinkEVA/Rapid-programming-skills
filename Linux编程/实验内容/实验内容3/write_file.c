#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
void main(){
	int fd;
	fd=open("f2",O_RDWR);
	if(fd == -1){
		perror("open");
		exit(1);
	}
	write(fd,"hello",strlen("hello"));
	close(fd);
}
