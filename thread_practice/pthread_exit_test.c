#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void* helloworld(char* argc)
{
	int *p;
	p=(int*)malloc(10*sizeof(int));
	printf("the message is %s\n",argc);
	printf("the child tid is %u\n",pthread_self());
	//printf("sizeof(p)=%d\n",sizeof(p));
	memset(p,'c',10*sizeof(int));
	printf("p=%x\n",p);
	pthread_exit(p);
}
int main()
{
	int error;
	int* temptr;
	pthread_t pthread_id;
	pthread_create(&pthread_id,NULL,(void*)*helloworld,"hehehe");
	if(error=pthread_join(pthread_id,(void**)&temptr)){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}
	printf("temptr=%x\t*temptr=%c\n",temptr,*temptr);
	printf("temptr+5=%c\n",temptr[4]);
	free(temptr);
	return 0;
}
