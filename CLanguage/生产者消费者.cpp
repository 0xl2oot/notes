#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

const int NrProd = 3, NrCons = 2; //生产者、消费者数量
const int BufLen = 6;             //缓冲区长度

int buf[BufLen], in = 0, out = 0; //缓存区，首尾指针
sem_t empty, full;                //信号量
pthread_mutex_t mutex;            //互斥锁

int producerID = 0, consumerID = 0;//生产者、消费者ID

void handler(int signo)
{
	printf("Exit program.\n");
	exit(0);
}

void *producerFunc(void *arg) //生产者进程
{
	int id = producerID++;
	while (true)
	{
		sleep(2);

		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		
		buf[in] = 1;
		printf("Producer %d produces %d:", id, in);
		for (int i = 0; i < BufLen; ++i)
			if (buf[i]) printf(" %d", i);
		printf("\n");
		in = (in + 1) % BufLen;

		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumerFunc(void * arg) //消费者进程
{
	int id = consumerID++;
	while (true)
	{
		sleep(2);

		sem_wait(&full);
		pthread_mutex_lock(&mutex);

		buf[out] = 0;
		printf("Consumer %d consumes %d:", id, out);
		for (int i = 0; i < BufLen; ++i)
			if (buf[i]) printf(" %d", i);
		printf("\n");
		out = (out + 1) % BufLen;

		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

int main()
{
	if (signal(SIGINT, handler) == SIG_ERR)
	{
		printf("Signal error.\n");
		exit(1);
	}

	if (sem_init(&empty, 0, BufLen) != 0)
	{
		printf("Init empty error.\n");
		exit(1);
	}

	if (sem_init(&full, 0, 0) != 0)
	{

		printf("Init full error.\n");
		exit(1);
	}

	pthread_t producer[NrProd];
	for (int i = 0; i < NrProd; ++i)
		if (pthread_create(&producer[i], NULL, producerFunc, NULL) != 0)
		{
			printf("Creating producer %d error.\n", i);
			exit(1);
		}
	
	pthread_t consumer[NrCons];
	for (int i = 0; i < NrCons; ++i)
		if (pthread_create(&consumer[i], NULL, consumerFunc, NULL) != 0)
		{
			printf("Creating consumer %d error.\n", i);
			exit(1);
		}
	
	for (int i = 0; i < NrProd; ++i) pthread_join(producer[i], NULL);
	for (int i = 0; i < NrCons; ++i) pthread_join(consumer[i], NULL);

	return 0;
}