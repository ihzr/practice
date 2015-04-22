#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void cleanup(){
	printf("cleanup\n");
}
void* test(){
	pthread_cleanup_push(cleanup,NULL);
	printf("test cleanup\n");
	while(1){
		printf("test message...\n");
		sleep(1);
	}
	pthread_cleanup_pop(1);
}
int main(int argc,char* argv[]){
	pthread_t tid;
	pthread_create(&tid,NULL,(void*)test,NULL);
	sleep(2);
	pthread_cancel(tid);
	pthread_join(tid,NULL);
	return 0;
}
