#include<stdio.h>
int main()
{
	long long int n;
	long long int sum=0;
	scanf("%lld",&n);
	if(n<1||n>1000000000)
		return 0;
	sum=(1+n)*n/2;
	printf("%lld\n",sum);
	return 0;
}
