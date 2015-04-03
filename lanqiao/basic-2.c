#include<stdio.h>
#include<string.h>
int main()
{
	int data[5];
	int i,temp,k;
	for(i=0;i<32;i++){
		memset(data,'\0',sizeof(data));
		temp=i;
		for(k=0;k<5;k++){
			data[k]=temp%2;
			temp/=2;
			if(!temp)
				break;
		}
		for(k=4;k>=0;k--){
			printf("%d",data[k]);
		}
		printf("\n");
	}
	return 0;
}
