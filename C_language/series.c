#include<stdio.h>
#include<stdlib.h>
int main()
{
	const int num=43;
	long a[num],i;
	long *p= a;
	double b;
	*p=*(p+1)=1;
	*(p+2)=2;
	printf("&a[0]= %p\n&a[2] = %p\n",&a[0],p+2);
	while(*p<=400000000)
	{
		*(p+3)=*(p+2)+*(p+1)+*p;
		p++;
	}
	for(p=a;p<&a[25];p++)
	{
		printf("%d\n",*p);
	}
	b=(double)(a[25])/a[24];
	printf("b=%.8f\n",b);
	printf("\n%d\n",sizeof(a));
	system("pause");
	return 0;
}

