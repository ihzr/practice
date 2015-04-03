#include<stdio.h>
#define SIZE 3
int main()
{
	int i,j,temp;
	int num[SIZE];
	for(i=0;i<SIZE;i++)
		scanf("%d",num+i);
	for(i=0;i<SIZE-1;i++)
		for(j=0;j<SIZE-i-1;j++){
			if(num[j]<num[j+1]){
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	for(i=0;i<SIZE-1;i++){
		printf("%d ",num[i]);
	}
	printf("%d\n",num[SIZE-1]);
	return 0;
}
