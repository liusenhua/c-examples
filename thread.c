#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_COUNT 10000000
void count(void);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main (void) {
	int rc1, rc2;
	pthread_t thread1, thread2;

	if ((rc1 = pthread_create(&thread1, NULL, (void *)count, NULL))) {
		printf("Thread creation faild: %d\n", rc1);
	}

	if ((rc2 = pthread_create(&thread2, NULL, (void *)count, NULL))) {
		printf("Thread creation faild: %d\n", rc2);
	}

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);

	return 0;
}

void count(void) {
	int i, j;
	pthread_mutex_lock( &mutex1 );
	for ( i = 0; i < MAX_COUNT; ++i) {
		for (j = 0; j < MAX_COUNT; ++j) {
			counter++;
		}
	}
	printf("Counter value: %d\n", counter);
	pthread_mutex_unlock( &mutex1 );
}
