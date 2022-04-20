#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{

    pid_t pid1;
    pid1 = fork();  /* here father "A" and his son "A1" */
   

    if (pid1 == 0)
    {
      printf("This is the child process. My id is %d and my father id is %d.\n", getpid(),getppid());
    }

    else
    {
        printf("This is the father process. My id is %d and .\n", getpid());
  }
    return 0;
}