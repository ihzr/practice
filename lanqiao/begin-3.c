#include<stdio.h>
#define PI 3.14159265358979323
int main()
{
	int r;
	double area;
	scanf("%d",&r);
	if(r<1||r>10000)
		return 0;
	area=r*r*PI;
	printf("%.7lf\n",area);
	return 0;
}
