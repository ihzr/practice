#include<stdio.h>
#include<string.h>
int pascal[34][34];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	memset(pascal,'\0',sizeof(pascal));
	pascal[1][1]=1;
	for(i=0;i<34;i++)
		pascal[i][0]=1;
	for(i=2;i<34;i++)
	{
		for(j=1;j<i;j++){
			pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
		}
		pascal[i][j]=1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			printf("%d ",pascal[i][j]);
		}
		printf("1\n");
	}
	return 0;
}
