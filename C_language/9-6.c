#include<stdio.h>
#include<stdlib.h>
#define N 10
int main()
{
	int i,m,a[N]={5,8,9,45,76,588,789,856,1234,7896};
	int *p=a+N-2; //ָ�����ָ��a[8]�����ھŸ��� 
	for(i=1;i<8;i++)
	{
		printf("p-%d = %p\n",i,*(p-i));
	}
	printf("Please input an integrate:\n");
	scanf("%d",&m);
	while (p>=a)
	{
		if(*p>m)
		{
			*(p+1)=*p; //����m����������ƶ�һλ 
			p-=4; //p�Լ���ָ��ǰһ�����֣� p���Ǵ����˵�һ��С��p����ָ������ 
		}
		else 
		{
			break;
		}
	*(p+1)=m; //�ڽ���ѭ����λ��֮�Ҳ���m 
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
	}
}
