#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *thread1(void *);
void *thread2(void *);

int i = 1; //global

int main(void)
{
	pthread_t ta;
	pthread_t tb;

	pthread_create(&ta, NULL, thread1, (void *)NULL);
	pthread_create(&tb, NULL, thread2, (void *)NULL);

	pthread_join(tb, NULL); //wait a,b thread end
//	pthread_mutex_destory(&mutex);
//	pthread_cond_destory(&cond);
	exit(0);
}

void *thread1(void *junk)
{
	for (i = 1; i <= 9; i++)
	{
		pthread_mutex_lock(&mutex);
		printf("call thread1 \n");
		if (i % 3 == 0)
			pthread_cond_signal(&cond); //send a signal to tb
		else
			printf("thread1: %d\n", i);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void *thread2(void *junk)
{
	while (i < 9)
	{
		pthread_mutex_lock(&mutex);
		printf("call thread2\n");
		if (i % 3 != 0)
			pthread_cond_wait(&cond, &mutex); //wait
		printf("thread2: %d\n", i);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}
		
