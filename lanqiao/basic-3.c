#include<stdio.h>
char data[26];
int main()
{
	int n,m,i,k;
	char temp;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		data[i]='A'+i;
	}
	for(k=0;k<m;k++)
		printf("%c",data[k]);
	printf("\n");
	for(i=1;i<n;i++){
		for(k=m-1;k>0;k--){
			data[k]=data[k-1];
		}
		data[0]='A'+i;
		for(k=0;k<m;k++)
			printf("%c",data[k]);
		printf("\n");
	}
	return 0;
}
