#include<sys/stat.h>
#include<fcntl.h>
void main(){
	int fd;
	fd=open("f2",O_RDWR|O_TRUNC|O_CREAT,0644);
	if(fd == -1){
		perror("open");
		exit(1);
	}
}
