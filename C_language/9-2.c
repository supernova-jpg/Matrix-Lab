#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b);
int main()
{
	int a=45,b=56;
	swap(&a,&b);
	printf("a=%d, b=%d\n",a,b);
	system("pause");
	return 0;
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a= *b;
	*b= temp;
}


