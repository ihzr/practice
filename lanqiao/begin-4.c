#include<stdio.h>
#define FACTOR 10007
int main()
{
	int num,sum,temp,i;
	int a1=1,a2=1;
	scanf("%d",&num);
	if(num<1||num>1000000)
		return 0;
	for(i=0;i<num;i++){
		sum=a1%FACTOR;//a1为当前的F数
		temp=a2;//a2为下一个F数 
		a2=(a1+a2)%FACTOR;//此时a2为下下一个F数
		a1=temp;//此时a1为下一个F数，用于下一次循环
	}
	printf("%d",sum);
	return 0;
}
