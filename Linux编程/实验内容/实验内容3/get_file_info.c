#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
	struct stat buf;
	int fd;
	fd = open("f2",O_RDONLY);
	fstat(fd,&buf);
	printf("f2 file size +%d\n",buf.st_size);
}
