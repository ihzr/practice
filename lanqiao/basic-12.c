#include<stdio.h>
#define SIZE 100000
char num[100000*4];
char out[SIZE*2];
char temp[SIZE];
int main()
{
	int n,i,k,j,h,sum;
	int h0,h1,h2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",temp);
		for(k=0;temp[k]!='\0';k++);
		//for(h=k-1;h>=0;h--)
		//	printf("%c\n",temp[h]);
		k--;
		for(h=0;k>=0;k--,h++){
			j=h*4;
			switch (temp[k]){
				case '0':
					num[j]='0';
					num[j+1]='0';
					num[j+2]='0';
					num[j+3]='0';
					break;
				case '1':
					num[j]='1';
					num[j+1]='0';
					num[j+2]='0';
					num[j+3]='0';
					break;
				case '2':
					num[j]='0';
					num[j+1]='1';
					num[j+2]='0';
					num[j+3]='0';
					break;
				case '3':
					num[j]='1';
					num[j+1]='1';
					num[j+2]='0';
					num[j+3]='0';
					break;
				case '4':
					num[j]='0';
					num[j+1]='0';
					num[j+2]='1';
					num[j+3]='0';
					break;
				case '5':
					num[j]='1';
					num[j+1]='0';
					num[j+2]='1';
					num[j+3]='0';
					break;
				case '6':
					num[j]='0';
					num[j+1]='1';
					num[j+2]='1';
					num[j+3]='0';
					break;
				case '7':
					num[j]='1';
					num[j+1]='1';
					num[j+2]='1';
					num[j+3]='0';
					break;
				case '8':
					num[j]='0';
					num[j+1]='0';
					num[j+2]='0';
					num[j+3]='1';
					break;
				case '9':
					num[j]='1';
					num[j+1]='0';
					num[j+2]='0';
					num[j+3]='1';
					break;
				case 'A':
					num[j]='0';
					num[j+1]='1';
					num[j+2]='0';
					num[j+3]='1';
					break;
				case 'B':
					num[j]='1';
					num[j+1]='1';
					num[j+2]='0';
					num[j+3]='1';
					break;
				case 'C':
					num[j]='0';
					num[j+1]='0';
					num[j+2]='1';
					num[j+3]='1';
					break;
				case 'D':
					num[j]='1';
					num[j+1]='0';
					num[j+2]='1';
					num[j+3]='1';
					break;
				case 'E':
					num[j]='0';
					num[j+1]='1';
					num[j+2]='1';
					num[j+3]='1';
					break;
				case 'F':
					num[j]='1';
					num[j+1]='1';
					num[j+2]='1';
					num[j+3]='1';
					break;
			}
			//printf("%.4s\n",num);
		}
		num[h*4]='\0';
		//printf("%s\n",num);
		for(k=0;;k++){
			j=k*3;
			if(!num[j]||!num[j+1]||!num[j+2])
				break;
			if(num[j+2]=='0'){
				if(num[j+1]=='0'){
					if(num[j]=='0')
						out[k]='0';
					else
						out[k]='1';
				}
				else{
					if(num[j]=='0')
						out[k]='2';
					else
						out[k]='3';
				}
			}
			else{
				if(num[j+1]=='0'){
					if(num[j]=='0')
						out[k]='4';
					else
						out[k]='5';
				}
				else{
					if(num[j]=='0')
						out[k]='6';
					else
						out[k]='7';
				}
			}
		}
		if(!num[j]){
			for(k--;out[k]=='0';k--);//消除前导0
			for(k;k>=0;k--){
				printf("%c",out[k]);
			}
			printf("\n");
			continue;
		}
		if(!num[j+1]){
			if(num[j]!='\0')
				out[k++]=num[j];
			for(k--;out[k]=='0';k--);//消除前导0
			for(k;k>=0;k--){
				printf("%c",out[k]);
			}
			printf("\n");
			continue;
		}
		if(!num[j+2]){
			if(num[j+1]=='1')
				if(num[j]=='1')
					out[k++]='3';
				else
					out[k++]='2';
			else
				if(num[j]=='1')
					out[k++]='1';
			for(k--;out[k]=='0';k--);//消除前导0
			for(k;k>=0;k--){
				printf("%c",out[k]);
			}
			printf("\n");
			continue;
		}
	}
	return 0;
}
