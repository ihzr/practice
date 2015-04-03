#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=n;i>0;i--){
        for(j=0;j<i-1;j++){
            printf("* ");
        }
        printf("*\n");
    }
    //printf("*");
    return 0;
}
