#include<stdio.h>
int num[1000];
int main()
{
	int n,m,i,loc;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",num+i);
	}
	scanf("%d",&m);
	for(i=0;i<n;i++){
		if(num[i]==m){
			printf("%d\n",i+1);
			break;
		}
	}
	if(i==n)
		printf("%d\n",-1);
	return 0;
}
