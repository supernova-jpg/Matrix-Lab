#include<stdio.h>
#include<stdlib.h>
void minmax(int a[],int len,int *min,int *max);
int main()
{
	int a[]={4,5,7,8,6,5,7,6,65,42,856,4,5,};
	int min,max;
	minmax(a, sizeof(a)/sizeof(a[0]), &min, &max); 
	printf("min=%d , max=%d \n",min,max);
	system("pause");
	return 0;
}

void minmax(int *a,int len,int *min,int *max)
{
	int i;
	*min = *max = a[0]; 
	for(i=1; i<len; i++)
	{
		if(a[i]<=*min)
		{
			*min = a[i];
		}
		if(a[i]>=*max)
		{
			*max = a[i];
		}
	}
}
