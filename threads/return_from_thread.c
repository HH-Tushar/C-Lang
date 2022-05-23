/* gcc basic_thread.c -pthread    #must use pthread word */

/*  case 1:we can use either global variable or
    case 2: we can use dynamic mem allocation in function and
    can return the mem address of that variable pointer in this we must cast it as a void pointer
    in function and void** in join section to recieve the vale*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

int xxx; //ex:- case 1;

void *roll_dics(){
    srand(time(NULL));
    int *value=malloc(sizeof(int)); //Ex:- case 2;
    *value=(rand()%6)+1;
    printf("mem addres in function =%p  \n",value);
    xxx= *value;
    return (void*)value;


}

int main(){
pthread_t ph;
int *x;

pthread_create(&ph,NULL,&roll_dics,NULL);
pthread_join(ph,(void **)&x);//recieving value from thread;


printf("Mem addres we r pointing by x=%p\n\n",x);
printf("value from thread = %d\n",*x);


free(x);//x is pointing to value which have a dm in faction
printf("value from xxx= %d\n",xxx);
return 0;
}