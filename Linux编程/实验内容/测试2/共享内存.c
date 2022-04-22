// 父子进程通过 共享内存传送信息，获取并打印共享内存的部分属性信息
#define KEY 1234 /* 键 */
#define SIZE 1024 /* 欲建立的共享内存的大小 */
int main(){
    int shmid;
    char *shmaddr;
    struct shmid_ds buf;
    shmid = shmget(KEY,SIZE,IPC_CREAT|0600); /* 建立共享内存 */
    if(shmid == -1){
    	printf("create share memory failed: %s",strerror(errno));
	    return 0;
    }
    if(fork() == 0){ /* 子进程 */
        shmaddr = (char *)shmat(shmid, NULL , 0); /* 系统自动选择一个地址连接 */
        if((int) shmaddr == -1){
            printf("connect to the share memory failed: %s",strerror(errno));
            return 0;
        }
    strcpy(shmaddr,"hello, this is child process!\n");
    shmdt(shmaddr); /* detach共享内存 */
    return 0;
    } /* 子进程结束 */
    else{ /* 父进程 */
        sleep(3); /* 等待子进程执行完毕 */
        shmctl(shmid, IPC_STAT, &buf); /* 取得共享内存的相关信息 */
        printf(" size of the share memory: ");
        printf("shm_segsz = %d bytes \n",buf.shm_segsz);
        printf(" process id of the creator: ");
        printf("shm_cpid = %d \n",buf.shm_cpid);
        printf(" process id of the last operator: ");
        printf("shm_lpid = %d \n",buf.shm_lpid);
        /* 系统自动选择一个地址连接 */
        shmaddr = (char *)shmat(shmid,NULL,0);
        if((int)shmaddr == -1){
            printf("connect the share memory failed: %s",strerror(errno));
            return -1;
        }
        printf("print the content of the share memory: ");
        printf("%s \n",shmaddr);
        shmdt(shmaddr); /* delete 共享内存 */
        /* 当不再有任何其它进程使用该共享内存时系统将自动销毁它 */
        shmctl(shmid,IPC_RMID,NULL);
        } /* 父进程结束 */
} /*main结束 */

