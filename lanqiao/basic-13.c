#include<stdio.h>
int num[200];
int main()
{
	int n,i,j,temp,record;
	while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++){
		scanf("%d",num+i);
	}
	for(i=0;i<n-1;i++){
		record=0;//用于记录交换是否发生，如果在一趟中没有
		         //交换发生，证明数据已经有序，直接推出冒泡排序
		for(j=0;j<n-i-1;j++){
			if(num[j+1]<num[j]){
				temp=num[j+1];
				num[j+1]=num[j];
				num[j]=temp;
				record=1;
			}
		}
		if(record==0)
			break;
	}
	printf("%d",num[0]);
	for(i=1;i<n;i++)
		printf(" %d",num[i]);
	printf("\n");
	}
	return 0;
}
