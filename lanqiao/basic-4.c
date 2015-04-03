#include<stdio.h>
int num[10000];
int main()
{
	int n,max,min,sum,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",num+i);
	}
	max=-10000;
	min=10000;
	sum=0;
	for(i=0;i<n;i++){
		sum+=num[i];
		if(num[i]>max)
			max=num[i];
		if(num[i]<min)
			min=num[i];
	}
	printf("%d\n%d\n%d\n",max,min,sum);
	return 0;
}
