#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
void main(){
	int fd;
	char buf[100];
	fd=open("f2",O_RDWR);
	if(fd == -1){
		perror("open");
		exit(1);
	}
	read(fd,buf,sizeof(buf)-1);
	close(fd);
}
