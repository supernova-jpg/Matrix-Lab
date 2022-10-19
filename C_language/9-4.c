#include<stdio.h>
#include<stdlib.h>
int main()
{
	int number;
	int *a;
	printf("Please input a number:");
	scanf("%d",&number);
	a= (int*)malloc(number*sizeof(int));
	printf("a=%d",a);
	void *p;
	int cnt=0;
	while((p=malloc(100*1024*1024)))
	{
		cnt++;
	}
	printf("\nWe can allocate %d MB's memory",cnt);
	free(p);
	return 0;
}
