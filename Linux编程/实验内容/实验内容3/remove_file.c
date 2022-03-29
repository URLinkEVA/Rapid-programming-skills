#include<sys/stat.h>
#include<fcntl.h>
void main(){
	if(mkdir("testdir",0774) != -1)//create dir
		puts("创建目录成功");
	else
		return 1;
	if(creat("test1",0664) != -1)// create a file
		puts("创建文件成功");
	else
		return 1;
	if(unlink("test1") != -1)  // remove file
		puts("删除文件成功");
	else
		return 1;
	if(rmdir("testdir") != -1)  // remove dir
		puts("删除目录成功");
	else
		return 1;
}
