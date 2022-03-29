#include<sys/stat.h>
#include<fcntl.h>
void main(){
	int fd;
	fd=open("f1",O_RDWR);
	if(fd == -1){
		perror("open");
		exit(1);
	}
}
