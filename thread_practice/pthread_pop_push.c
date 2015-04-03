#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void cleanup()
{
	printf("cleanup\n");
}
void* test_cancel(void)
{
	pthread_cleanup_push(cleanup,NULL);
	printf("test_cancel\n");
	while(1){
		printf("test message\n");
		sleep(1);
	}
	pthread_cleanup_pop(1);
}
int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,(void*)test_cancel,NULL);
	sleep(2);
	pthread_cancel(tid);
	pthread_join(tid,NULL);
	return 0;
}
