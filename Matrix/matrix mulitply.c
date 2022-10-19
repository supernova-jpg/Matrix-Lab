#include<stdio.h>
#include<stdlib.h>
#define MAX 10

float A[MAX][MAX];
float B[MAX][MAX];
float C[MAX][MAX];
int a,b,c;

void Matrprint(float A[MAX][MAX],int a,int b)
{
	int j,k;
	for(k=0; k<a;k++)
	{
	    for(j=0;j<b;j++)
		{
			printf("%f\t",*(A[k]+j));
		}
		printf("\n");
	}
}

void Matrscan(float A[MAX][MAX],int a, int b, int AB)
{
	int j,k;
	for(k=0; k<a;k++)
	{
		if(AB)
		{
			printf("Please input line %d of matrix A:\n",k+1);
		}
		else
		{
			printf("Please input line %d of matrix B:\n",k+1);
		}
	    for(j=0;j<b;j++)
		{
			scanf("%f",A[k]+j);
		}
	}
}

void input()
{
	int i,j;
	printf("Please input the line of matrix A:\n");
	scanf("%d",&a);
	printf("Please input the row of matrix A:\n");
	scanf("%d",&b);
	printf("Please input the row of matrix B:\n");
	scanf("%d",&c);
	Matrscan(A,a,b,1);
	Matrscan(B,b,c,0);
	printf("Matrix A is:\n");
	Matrprint(A,a,b);
	printf("Matrix B is:\n");
	Matrprint(B,b,c);
}


void multiply()
{
	int i,j,k;
    for(i=0;i<a;i++)
	{
    	for(j=0;j<c;j++)
    	{
    		C[i][j]=0;
    		for(k=0;k<b;k++)
    		{
    			C[i][j]+=(A[i][k]*B[k][j]);
			}
		}
	}
	printf("\nMatrix C= AB is:\n");
	Matrprint(C,a,c);
}

int main()
{
	int judge=1;
	while(judge)
	{
		input();
		multiply();
		printf("\nDo you want to continue(0N/1Y)?");
		scanf("%d",&judge);
		system("cls");
	}
	system("pause");
	return 0;
}
