#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void print_PCB()
{
    printf("PCB | PPID: %d\n",getppid());
    printf("    | PID: %d\n",getpid());
    printf("    | UID: %d\n",getuid());
    printf("    | GID: %d\n",getgid());
}

int main()
{
    __pid_t ret = fork();
    print_PCB();

    if(ret == 0)
    {
        sleep(30);
        exit(123);
    }else{
        wait(NULL);
        printf("J'AII FINIIIIIII\n");
    }

    exit(EXIT_SUCCESS);
}