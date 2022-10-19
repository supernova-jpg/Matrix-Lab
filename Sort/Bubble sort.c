#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int num;
float A[MAX];

int Vscan(float *p)
{
	int i;
	while(i<MAX)
	{
		scanf("%f",(p+i));
		i++;
		char c= getchar();
		if(c=='\n')
		{
			break;
		}
	}
	return i;
}

void Vprint(float *p, int a)
{
	int i;
	for(i=0; i<a; i++)
	{
		printf("%.5g\n",*(p+i));
	}
}

void input()
{
	printf("Please input the elements of this array:\n");
	num=Vscan(A);
	printf("Your input array is:\n");
	Vprint(A, num);
}

void Bubblesort(float *A, int num)
{
	int i,j;
	float temp;
	for(i=0; i<num-1;i++) 
	{
		for(j=num-2; j>=i;j--)
		{
			if(A[j+1]>=A[j])
			{
				temp=A[j+1];
				A[j+1]=A[j];
				A[j]=temp;
	
			}
		}
	}
	printf("The array in decending order is:\n");
	Vprint(A,num);
}

int main()
{
	int judge = 1;
	while(judge)
	{
		input();
		Bubblesort(A,num);
		printf("Would you like to continue?(Y/N)");
		scanf("%d",&judge);
	}
	system("pause");
	return 0;
}

