#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/syscall.h>

struct massage{
	int i;
	int j;
};
void* hello(struct massage* str)
{
	printf("massage.i=%d\tmassage.j=%d\n",str->i,str->j);
	printf("child:the tid=%lu,pid=%ld\n",pthread_self(),syscall(SYS_gettid));
	sleep(2);
	pthread_exit(0);
}
int main()
{
	struct massage test;
	pthread_t thread_id;
	test.i=10;
	test.j=20;
	pthread_create(&thread_id,NULL,hello,&test);
	printf("parent:the tid=%lu,pid=%ld\n",pthread_self(),syscall(SYS_gettid));
	pthread_join(thread_id,NULL);
	printf("thread over\n");
	return 0;
}
