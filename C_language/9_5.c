#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a =10,b,*i_p1,*i_p2,*i_p3;
	i_p1=&a;
	*i_p1=6;
	i_p2=&b;
	i_p3=(int*)&i_p2;
	*i_p2=*i_p1+5;
	printf("a=%d  b=%d",a,b);
	printf("\np1=%p, p2=%p\n",i_p1,i_p2);
	printf("p3=%p\n",*i_p3);
	system("pause");
	return 0;
}
