#include<stdio.h>
#include<string.h>
#define UPCASE(c) (((c)>='a'&&(c)<='z')?((c)-0x20):(c))
char word1[80];
char word2[80];
int stat1[26];
int stat2[26];
int main()
{
	int i;
	char temp;
	scanf("%s",word1);
	scanf("%s",word2);
	memset(stat1,'\0',sizeof(stat1));
	memset(stat2,'\0',sizeof(stat2));
	for(i=0;word1[i];i++){
		temp=UPCASE(word1[i]);
		stat1[temp-'A']++;
	}
	for(i=0;word2[i];i++){
		temp=UPCASE(word2[i]);
		stat2[temp-'A']++;
	}
	for(i=0;i<26;i++){
		if(stat2[i]!=stat1[i]){
			printf("N\n");
			break;
		}
	}
	if(i==26)
		printf("Y\n");
	return 0;
}
