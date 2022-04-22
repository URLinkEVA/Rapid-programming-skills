// 创建两个线程顺序访问一个字符数组中的每个字符
#include <pthread.h>
char str[]=“abcdefghijklopqrst123456789”;
pthread_mutex_t mutex;
int index2=0;
void *t1_exe(void *arg){
	while(index2<strlen(str)-1){
	    pthread_mutex_lock (&mutext);
        printf(“The %d th array:%d”,index2,str[index2]);
	    sleep(1);index2++;
        pthread_mutex_unlock (&mutext);
	}
}
void main(){
	pthread_t pid1,pid2;
	int error1,error2;
	pthread_mutex_init(&mutex,NULL);
    error1=pthread_creat(&pid1,NULL,t1_exe,NULL);
    error2=pthread_creat(&pid2,NULL,t1_exe,NULL); 
    if(error1!=0)||(error2!=0)
    {
	    printf(“pthread create failed”);
	    return;
	}
	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
	return;
}
