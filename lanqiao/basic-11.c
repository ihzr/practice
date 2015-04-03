#include<stdio.h>
int main()
{
	char instr[9];
	unsigned long long sum,num;
	int i;
	scanf("%s",instr);
	sum=num=0;
	for(i=0;instr[i];i++){
		switch(instr[i]){
			case '0':
				num=0;
				break;
			case '1':
				num=1;
				break;
			case '2':
				num=2;
				break;
			case '3':
				num=3;
				break;
			case '4':
				num=4;
				break;
			case '5':
				num=5;
				break;
			case '6':
				num=6;
				break;
			case '7':
				num=7;
				break;
			case '8':
				num=8;
				break;
			case '9':
				num=9;
				break;
			case 'A':
				num=10;
				break;
			case 'B':
				num=11;
				break;
			case 'C':
				num=12;
				break;
			case 'D':
				num=13;
				break;
			case 'E':
				num=14;
				break;
			case 'F':
				num=15;
				break;
		}
		sum=sum*16+num;
	}
	printf("%lld\n",sum);
	return 0;
}
