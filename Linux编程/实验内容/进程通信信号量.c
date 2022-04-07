#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define DELAY_TIME  3

// 定义联合体
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

// 函数声明
int init_sem(int sem_id,int init_value);
int del_sem(int sem_id);
int sem_p(int sem_id);
int sem_v(int sem_id);

int main(void){
    pid_t result;
    int sem_id;
    // 创造一个信号量
    sem_id = semget(ftok(".","a"),1,0666|IPC_CREAT);
    init_sem(sem_id,0);
    // 调用fork函数
    result = fork();
    if(result==-1){
        perror("Fork\n");
    }
    else if(result==0)// 返回为0代表子进程
    {
        printf("child progress wil wait for some seconds...\n");
        sleep(DELAY_TIME);// 睡眠3秒，执行父进程
        printf("the return value is %d in the child progress(PID=%d)\n",result,getpid());
        sem_v(sem_id);
    }
    else{ //返回值大于0代表父进程
        sem_p(sem_id);
        printf("the return value is %d in the father progress(PID=%d)\n",result,getpid());
        sem_v(sem_id);
        del_sem(sem_id);
    }
    exit(0);
}
// main end


// 信号量初始化函数
int init_sem(int sem_id,int init_value){
    union semun sem_union;
    sem_union.valu = init_value;
    if(semctl(sem_id,0,SETVAL,sem_union)==-1)
    {
        perror("Initialize semaphere");
        return -1;
    }
    return 0;
}

// 从系统中删除信号量的函数
int del_sem(int sem_id)
{
    union semun sem_union;
    if(semctl(sem_id,0,IPC_RMID,sem_union)==-1){
        perror("delete semaphere");
        return -1;
    }
}

// p操作函数
int sem_p(int sem_id){
    struct sembuf sem_b;
    sem_b.sem_num=0;
    sem_b.sem_op=-1;  // 信号量取值为-1表示p操作
    sem_b.sem_flg=SEM_UNDO;  // 在进程没释放信号量而退出时，系统自动释放该进程中未释放的信号量
    if(semop(sem_id,&sem_b,1)==-1){
        perror("p operation");
        return -1;
    }
    return 0;
}

// v操作函数
int sem_v(int sem_id){
    struct sembuf sem_b;
    sem_b.sem_num=0; // 单个信号量的编号为0
    sem_b.sem_op=1; // 取值为1表示为v操作
    sem_b.sem_flg=SEM_UNDO；//释放
    if(semop(sem_id,&sem_b,1)==-1){ // 进行v操作
        perror("v operation");
        return -1;
    }
    return 0;
}
