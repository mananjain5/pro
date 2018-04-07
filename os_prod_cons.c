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
	printf("Enter 1 for case 1\nEnter 2 for case 2\nEnter 3 for case 3\nElse to exit \n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("Case 1: Consumer cannot consume whem producer has not produced \n\n");	
			pthread_create(&C1,NULL,consumer,NULL);
			pthread_join(C1,NULL);
			break;
		case 2:
			printf("Case 2: Producer cannot produce when buffer is full \n\n");
			pthread_create(&P1,NULL,producer,NULL);
			pthread_create(&P2,NULL,producer,NULL);
			pthread_create(&P3,NULL,producer,NULL);
			pthread_create(&P4,NULL,producer,NULL);
			pthread_create(&P5,NULL,producer,NULL);
			pthread_create(&P6,NULL,producer,NULL);
			pthread_join(P1,NULL);
			pthread_join(P2,NULL);
			pthread_join(P3,NULL);
			pthread_join(P4,NULL);
			pthread_join(P5,NULL);
			pthread_join(P6,NULL);
			break;
		case 3:
			while(1)
			{
			printf("Case 3 User enter no of thread of consumer and producer\n\tPress 1 for consumer \n\tPress 2 for producer thread \n\tPress 3 to exit \n \n");
			int m;
			scanf("%d",&m);
			if(m==1)
			{
				pthread_create(&C1,NULL,producer,NULL);
				pthread_join(C1,NULL);
			}
			else if(m==2)
			{
				pthread_create(&P1,NULL,consumer,NULL);
				pthread_join(P1,NULL);
			}
			else
			{
				break;
			}
			}
			break;
		default:
			printf("Program is closing\n");
			break;
	}
	exit(0);
}
