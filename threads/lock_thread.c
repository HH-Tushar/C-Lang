//gcc lock_thread.c -pthread
/* we use lock and unlock to avoid race condition*/
#include <stdio.h>
#include <pthread.h>
int x;
pthread_mutex_t mutex;
void *routine()
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);//locking x sothat other thread cannot manupulate it
        x++;
        pthread_mutex_unlock(&mutex);//unlocking x sothat other thread can use it again
    }
}

int main()
{
    pthread_t a,b;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&a,NULL,&routine,NULL);
    pthread_create(&b,NULL,&routine,NULL);

    pthread_join(a,NULL);
    pthread_join(b,NULL);


printf("value of x= %d\n",x);
return 0;
}
