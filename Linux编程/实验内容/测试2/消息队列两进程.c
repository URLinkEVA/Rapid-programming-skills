#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// 创建信号量创建信号量
int semget(key_t key,int nsems,int flags)

// 删除和初始化信号量
int semctl(int semid, int semnum, int cmd, ...);
union semun
{    
    int val;  //使用的值
    struct semid_ds *buf;  //IPC_STAT、IPC_SET 使用的缓存区
    unsigned short *arry;  //GETALL,、SETALL 使用的数组
    struct seminfo *__buf; // IPC_INFO(Linux特有) 使用的缓存区
};


// 改变信号量的值
int semop(int semid, struct sembuf *sops, size_t nops);
struct sembuf{ 
    short sem_num;   //除非使用一组信号量，否则它为0 
    short sem_op;   //信号量在一次操作中需要改变的数据，通常是两个数，                                        
                    //一个是-1，即P（等待）操作， 
                    //一个是+1，即V（发送信号）操作。 
    short sem_flg; //通常为SEM_UNDO,使操作系统跟踪信号量， 
                  //并在进程没有释放该信号量而终止时，操作系统释放信号量 
}; 

