#include<stdio.h>
int main()
{
	int i,sum,temp;
	for(i=1000;i<10000;i++){
		temp=i;
		sum=0;
		while(1){
			sum=sum*10+temp%10;
			temp/=10;
			if(!temp)
				break;
		}
		if(sum==i)
			printf("%d\n",i);
	}
	return 0;
}
