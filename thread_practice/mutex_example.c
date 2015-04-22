#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#define WORK_SIZE 1024
char work_area[WORK_SIZE];
pthread_mutex_t lock;
int time_to_exit=0;
void* thread_function(void* arg);
int main(int argc,char* argv[]){
	int res;
	pthread_t tid;
	void* thread_result;
	res=pthread_mutex_init(&lock,NULL);
	if(res){
		perror("Mutex init failed");
		exit(EXIT_FAILURE);
	}
	res=pthread_create(&tid,NULL,(void*)thread_function,NULL);
	if(res){
		perror("Thread create failed");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_lock(&lock);
	printf("Input some text. Enter 'end' to finish\n");
	while(!time_to_exit){
		//fgets(work_area,WORK_SIZE,stdin);
		scanf("%s",work_area);
		pthread_mutex_unlock(&lock);
		while(1){
			pthread_mutex_lock(&lock);
			if(work_area[0]!='\0'){
				pthread_mutex_unlock(&lock);
				sleep(1);
			}
			else
				break;
		}
	}
	pthread_mutex_unlock(&lock);
	printf("Waiting for thread to finish\n");
	res=pthread_join(tid,(void**)&thread_result);
	if(res){
		perror("thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
	pthread_mutex_destroy(&lock);
	return 0;
}
void* thread_function(void* arg){
	sleep(1);
	pthread_mutex_lock(&lock);
	while(strncmp("end",work_area,3)!=0){
		printf("you input %d characters\n",strlen(work_area));
		printf("the characters is %s\n",work_area);
		work_area[0]='\0';
		pthread_mutex_unlock(&lock);
		sleep(1);
		pthread_mutex_lock(&lock);
		while(work_area[0]=='\0'){
			pthread_mutex_unlock(&lock);
			sleep(1);
			pthread_mutex_lock(&lock);
		}
	}
	time_to_exit=1;
	work_area[0]='\0';
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}
