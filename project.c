#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define buffsize 5
typedef int buffer_item;
pthread_mutex_t mutex;
sem_t full,empty;
int counter;
int x;
buffer_item buffer[buffsize];
void * producer ()
{
	int item,i;
	x= (x+rand())%5;
	item=x;
	pthread_mutex_lock(&mutex);
	printf("%d \n",counter);
	
	if(counter<5)
	{
	sem_wait(&empty);
	printf("Producer has produced item: %d\n",item);
	
	buffer[counter++]=item;
	printf("Counter is %d\n",counter);
	sem_post(&full);
	}
	else
	{
		printf("Buffer is full\n");
	}
	pthread_mutex_unlock(&mutex);
}

void * consumer ()
{
	int item;
	pthread_mutex_lock(&mutex);
	if(counter>1)
	{
	sem_wait(&full);
	
	item=buffer[--counter];
	printf("The consumer has consumed item: %d\n",item);
	
	
	
	sem_post(&empty);
	printf("Hello \n");
	}
	else
	{
		printf("Cannot consume as nothing produced by producer \n");
	}
	pthread_mutex_unlock(&mutex);
}

int main()
{
	//int n1,n2,i;
	pthread_mutex_init(&mutex,NULL);
	sem_init(&full,1,0);
	sem_init(&empty,1,buffsize);
	counter=1;
	pthread_t tidP1,tidP2,tidP3,tidP4,tidP5,tidP6,tidC1,tidC2,tidC3,tidC4,tidC5,tidC6,tidC7;

	pthread_create(&tidC5,NULL,consumer,NULL);
	pthread_create(&tidP1,NULL,producer,NULL);
	pthread_create(&tidP2,NULL,producer,NULL);
	pthread_create(&tidP3,NULL,producer,NULL);
	pthread_create(&tidP4,NULL,producer,NULL);
	pthread_create(&tidP5,NULL,producer,NULL);
	pthread_create(&tidP6,NULL,producer,NULL);
	sleep(2);
	pthread_create(&tidC1,NULL,consumer,NULL);
	pthread_create(&tidC2,NULL,consumer,NULL);
	pthread_create(&tidC3,NULL,consumer,NULL);
	pthread_create(&tidC4,NULL,consumer,NULL);
	pthread_create(&tidC6,NULL,consumer,NULL);
	pthread_create(&tidC7,NULL,consumer,NULL);

	pthread_join(tidC5,NULL);
	pthread_join(tidP1,NULL);
	pthread_join(tidP2,NULL);
	pthread_join(tidP3,NULL);
	pthread_join(tidP4,NULL);
	pthread_join(tidP5,NULL);
	pthread_join(tidP6,NULL);
	pthread_join(tidC1,NULL);
	pthread_join(tidC2,NULL);
	pthread_join(tidC3,NULL);
	pthread_join(tidC4,NULL);
	pthread_join(tidC6,NULL);
	pthread_join(tidC7,NULL);
	//sleep(5);
	exit(0);
}
