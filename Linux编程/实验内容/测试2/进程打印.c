// 编写一个程序，创建两个线程，第一个线程打印1-5，第二个线程在第一个线程结束后打印6-10这5个数字。
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void *thread_function1(void *arg) 
{
    int i;
    for ( i=0; i<5; i++) 
	{
        printf("Thread 1 working...! %d \n",i);
		  sleep(1);
     }
    return NULL;
}
void *thread_function2(void *arg) 
{
    int i;
    for ( i=6; i<10; i++) 
	{
        printf("Thread 2 working...! %d \n",i);
		   sleep(1);
     }
    return NULL;
}
int main()
{
    int i=0, ret=0;
    pthread_t id1,id2;
    ret = pthread_create(&id1, NULL, (void*) thread_function1, NULL); 
    if (ret) 
    {
        printf("Create pthread error!\n");
        return 1;
    }
    ret = pthread_create(&id2, NULL, (void*) thread_function2, NULL);
    if (ret)
    {
        printf("Create pthread error!\n");
        return 1;
    }
    pthread_join(id1, NULL); //等待线程1结束
    pthread_join(id2, NULL); //等待线程2结束
    return 0;
}
