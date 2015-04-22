#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void* hello(char* argv){
	int* p;
	p=(int*)malloc(sizeof(int));
	printf("the message is %s\n",argv);
	*p=10;
	pthread_exit(p);
}
int main(int argc,char* argv[]){
	int error;
	int* temptr;
	pthread_t tid;
	error=pthread_create(&tid,NULL,(void*)hello,"helloworld");
	if(error){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	error=pthread_join(tid,(void**)&temptr);
	if(error){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	printf("temp=%d\n",*temptr);
	free(temptr);
	return 0;
}
