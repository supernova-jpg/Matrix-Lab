#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11}};
	int (*p)[4]=a;
	printf("%d\n",sizeof(*p));
	return 0;
}
