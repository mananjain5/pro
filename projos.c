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

void insert_item();
{
	
}

void 


void * producer ()
{
	int item,i;
	x= (x+rand())%5;
	item=x;
	pthread_mutex_lock(&mutex);
	if(counter<6)
	{
	sem_wait(&empty);
	printf("Producer %d has produced item: %d\n",counter,item);
	
	buffer[counter++]=item;
	sem_post(&full);
	}
	else
	{
		printf("Buffer is full hence cannot produce \n");
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
	printf("The consumer %d has consumed item: %d\n",counter,item);
	sem_post(&empty);
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
	pthread_t P1,P2,P3,P4,P5,P6,C1,C2,C3,C4,C5,C6;
	int c;
	print("Press 1 for ");
	scanf("%d",&c);
	switch(c):
	{
		case 1:
			printf("Case 1: Consumer cannot consume whem producer has not produced ");	
			pthread_create(&C1,NULL,consumer,NULL);
			pthread_join(C1,NULL);
			break;
		case 2:
			printf("")
			break;
		case 3:
			printf("Case 3: Producer cannot produce when buffer is full \n");
			pthread_create(&tidP1,NULL,producer,NULL);
			pthread_create(&tidP2,NULL,producer,NULL);
			pthread_create(&tidP3,NULL,producer,NULL);
			pthread_create(&tidP4,NULL,producer,NULL);
			pthread_create(&tidP5,NULL,producer,NULL);
			pthread_create(&tidP6,NULL,producer,NULL);
			pthread_join(tidP1,NULL);
			pthread_join(tidP2,NULL);
			pthread_join(tidP3,NULL);
			pthread_join(tidP4,NULL);
			pthread_join(tidP5,NULL);
			pthread_join(tidP6,NULL);
			break;
		case 4:
			
			break;
		default:
			
			break;		
	}
	
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
