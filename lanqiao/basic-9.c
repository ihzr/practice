#include<stdio.h>
int main()
{
	int n,i,temp,sum;
		scanf("%d",&n);
		for(i=10000;i<1000000;i++){
			temp=i;
			sum=0;
			while(1){
				sum+=temp%10;
				temp/=10;
				if(!temp) break;
			}
			if(sum!=n)
				continue;
			sum=0;
			temp=i;
			while(1){
				sum=sum*10+temp%10;
				temp/=10;
				if(!temp) break;
			}
			if(sum==i)
				printf("%d\n",i);
		}
	return 0;
}
