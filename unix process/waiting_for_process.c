#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <unistd.h> /* header file for processes */
#include<sys/wait.h> /* headerfile for wait */

int main()
{
    int n, i;
    int id = fork();/* it makes new child process and for every single fork code will 
                        run twice parallely.the number of total process will follow #2^n 
                        as we have single fork the compiler will run the code from here to last 
                        line twice */
    if (id == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }
    if (id != 0)
    {
        wait(NULL); /* if comapiler find parent process it will wait
                         till child complete its work and id become 0 */
    }
    //printf("\n");
   /* printf("process id is= %d\n", id);    /* this will also run twice once for main process
                                            and once for child */
    for (i = n; i < n + 5; i++)
    {
        printf("%d", i);
        fflush(stdout); /* printf have its own buffer to store every thing and print them 
                at a time here fflush says dont wait to store all just print what u have */
    }

    
    if(id!=0){printf("\n");}
    return 0;
}