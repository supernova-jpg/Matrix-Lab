#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long a[]={0,1,2,3,4,5,6,7,8,9,};
	long long *p=a;  
	long long *p1=&a[5];
	printf("p1-p=%d\n",p1-p);
	printf("\n&a=%p\n%p",&p,*p);
	while (*p!=9)
	{
		printf("%d\n",*p++);
	}
	system("pause");
	return 0;
}
