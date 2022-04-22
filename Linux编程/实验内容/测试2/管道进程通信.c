/*读管道程序rdfifo.c*/
Main(void)
{
	int fd,len;
	char buf[PIPE_BUF];
	if(mkfifo("fifo1",0666)<0){                /*fifo1 管道名*/
		printf("mkfifo error\n");
		exit(1);
}
	if((fd=open( "fifo1",O_RDONLY))<0)       /*fd文件标识号*/
	{
		printf("pipe open error\n");
		exit(1);
	}
	while(len=(read(fd,buf,PIPE_BUF-1))>0)
			printf("read fifo pipe: %s",buf);
	close(fd);
}

/*写管道程序wdfifo.c*/
main(void)
{
int fd,len;
char buf[PIPE_BUF];
if((fd=open（"fifo1",O_WRONLY)) < 0){
	printf("pipe open error\n");
	exit(1);
	}
for(i=0；i<3;i++){
    len = printf(buf,"write fifo pipe from %d at %d times\n",getpid(),i+1);
    write(fd,buf,len+1);
}
close(fd);
}


// 在linux终端上运行这两个程序：
// $./rdfifo&
// $./wrfifo
// 结果：
// Read fifo pipe：Write fifo pipe from 945 at 1 times
// Read fifo pipe： Write fifo pipe from 945 at 2 times
// Read fifo pipe： Write fifo pipe from 945 at 3 times
