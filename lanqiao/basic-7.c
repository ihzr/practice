#include<stdio.h>
#define POW3(i) ((i)*(i)*(i))
int main()
{
	int i,sum,temp,k;
	for(i=100;i<1000;i++){
		temp=i;
		sum=0;
		while(1){
			k=temp%10;
			sum+=POW3(k);
			temp/=10;
			if(!temp)
				break;
		}
		if(sum==i)
			printf("%d\n",i);
	}
	return 0;
}
