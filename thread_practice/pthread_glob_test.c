#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int key=10;
void* p_one(char* argc){
	printf("the message is %s\n",argc);
	key=10;
	printf("key=%d,the child id is %u\n",key,pthread_self());
	pthread_exit(NULL);
}
void* p_two(char* argc){
	printf("the message is %s\n",argc);
	sleep(1);
	printf("key=%d,the child id is %u\n",key,pthread_self());
	pthread_exit(NULL);
}
int main(){
	pthread_t tid_one,tid_two;
	pthread_create(&tid_one,NULL,(void*)p_one,"helloworld");
	pthread_create(&tid_two,NULL,(void*)p_two,"helloworld");
	pthread_join(tid_one,NULL);
	pthread_join(tid_two,NULL);
	return 0;
}
