#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{

    pid_t pid1, pid2;
    pid1 = fork();  /* here father "A" and his son "A1" */
    pid2 = fork();  /* here father "A" gets new son "A2" and his son "A1" gets a new son "B1"*/

    if (pid1 == 0)
    {
        if (pid2 == 0)
        {
            printf("This is the grand child process. My id is %d and my parent's id is %d.\n", getpid(), getppid());
        }
        else
        {
            printf("This is the father process. My id is %d and my parent's id is %d.\n", getpid(), getppid());
        }
    }

    else
    {
        if (pid2 == 0)
        {
            printf("This is the child process. My id is %d and my parent's id is %d.\n", getpid(), getppid());
        }
        else
        {
            printf("This is the gran father process. My id is %d \n", getpid());
        }
    }
    return 0;
}