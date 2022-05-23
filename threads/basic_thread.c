
/* gcc basic_thread.c -pthread    #must use pthread word */
#include<stdio.h>
#include<pthread.h>
void *run(){
    printf("1. printing from pthread\n");
}
void *run2(){
    printf("2. printing from pthread\n");
}

int main(){
pthread_t p1,p2;
pthread_create(&p1,NULL,&run,NULL);//create
pthread_create(&p2,NULL,&run,NULL);
//pthread_create(&p2,NULL,&run2,NULL);
    
pthread_join(p1,NULL);//join with main threat
pthread_join(p2,NULL);
//pthread_join(p2,NULL);

    return 0;
}
