#include<stdio.h>
#define DI 16
int main()
{
	int a,i;
	int rem[10];//remainder 余数
	scanf("%d",&a);
	for(i=0;i<10;i++){
		rem[i]=a%DI;
		a=a/DI;
		if(!a)
			break;
	}
	for(i;i>=0;i--){
		if(rem[i]>9){
			switch (rem[i]){
				case 10:
					printf("%c",'A');
					break;
				case 11:
					printf("%c",'B');
					break;
				case 12:
					printf("%c",'C');
					break;
				case 13:
					printf("%c",'D');
					break;
				case 14:
					printf("%c",'E');
					break;
				case 15:
					printf("%c",'F');
					break;
			}
			continue;
		}
		printf("%d",rem[i]);
	}
	printf("\n");
	return 0;
}
