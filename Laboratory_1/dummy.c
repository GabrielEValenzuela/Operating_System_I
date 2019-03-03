#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 5

void *print_hello(void * bha){

printf("Hello World! It’s me, thread #\n");
}

int main (int argc, char *argv[]) {
pthread_t threads[NUM_THREADS];
int rc;
long t;
for (t = 0; t < NUM_THREADS; t++) {
printf("In main: creating thread %ld\n", t);
rc = pthread_create(threads + t, NULL, print_hello, NULL);
if (rc) {
printf("ERROR; return code from pthread_create() is %d\n", rc);
return -1;}

}
/* wait for all threads to complete */
for (t = 0; t < NUM_THREADS; t++) {
	pthread_join(threads[t], NULL);
}
pthread_exit(NULL);
}