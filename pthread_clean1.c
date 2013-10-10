#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void clean (void *arg)
{
	printf("%s\n", (char *)arg);
}

void *thread(void *arg)
{
	printf("thread start:\n");
	pthread_cleanup_push(clean, "first handler");
	pthread_cleanup_push(clean, "second handler");

	if ((int)arg)
		pthread_exit((void *)1);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	return ((void *)0);
}

int main(void)
{
	pthread_t th;
	void *res;
	pthread_create(&th, NULL, thread, (void *)0);
	pthread_join(th, &res);
	printf("thread exit code:%d\n", (int)res);
	exit(0);
}

