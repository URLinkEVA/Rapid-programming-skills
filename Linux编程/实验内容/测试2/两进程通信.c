#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define DELAY_TIME  3

union semun
{    
    int val;  
    struct semid_ds *buf;  
    unsigned short *arry; 
};

int init_sem(int sem_id,int init_value);
int del_sem(int sem_id);
int semp(int sem_id);
int sem_v(int sem_id);

int init_sem(int sem_id,int init_value){
    union semun sem_union;
    sem_union.val = init_value;
    if(semctl(sem_id,0,SETVAL,sem_union)==-1){
        perror("initialize semaphere");
        return -1;
    }
    return 0;
}

int del_sem(int sem_id){
    union semun sem_union;
    if(semctl(sem_id,0,IPC_RMID,sem_union)==-1){
        perror("delete semaphere");
        return -1;
    }
}

int sem_p(int sem_id){
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;

    if(semop(sem_id,$sem_b,1)==-1){
        perror("p operation");
        return -1;
    }
    return 0;
}

int sem_v(int sem_id){
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;

    if(semop(sem_id,&sem_b,1)==-1){
        perror("v operation");
        return -1;
    }
    return 0;
}

int main(void){
    pid_t result;
    int sem_id;
    sem_id = semget(ftok(".","a"),1,066|IPC_CREAT);
    init_sem(sem_id,0);
    result = fork();
    if(result==-1){
        perror("Fork\n");
    }
    else if(result==0){
        printf("child process will wait for some seconds...\n");
        sleep(DELAY_TIME);
        printf("the return value is %d in the child process(PID = %d\n)",result.getpid());
        sem_v(sem_id);
    }
    else{
        sem_p(sem_id);
        printf("the return value is %d in the father process(PID - %d)/n",result.getpid());
        sem_v(sem_id);
        del_sem(sem_id);
    }
    exit(0);
}

