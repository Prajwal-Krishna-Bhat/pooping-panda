#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1){
        perror("vfork");
        return 1;
    }else if(pid==0){
        printf("Child process:Hello, im the child!\n");
        printf("Child process:My PID is %d\n",getpid());
        printf("Child process:My parent's PID is %d\n",getppid());
        _exit(0);
    }else{
        printf("Parent process:Hello, im the parent!\n");
        printf("Parent process:My PID is %d\n",getpid());
        printf("Parent process:My child's PID is %d\n",pid);
    }
    int status;
    waitpid(pid,&status,0);
    if(WIFEXITED(status)){
        printf("Parent process: Child process terminated normally.\n");
    }else{
        printf("Parent process: Child Process terminated abnormally.\n");
    }
}