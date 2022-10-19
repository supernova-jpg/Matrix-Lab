#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10
float a[MAX][MAX];
float x[MAX],y[MAX];
int num;

void Vprint(float *p, int num)
{
	int i;
    for(i=0;i<num;i++)
   {
        printf("%f\n",*(p+i));
   }
}

void Matrprint(float A[MAX][MAX],int num)
{
	int j,k;
	printf("Your input matrix is:\n");
	for(k=0; k<num;k++)
	{
	    for(j=0;j<num;j++)
		{
			printf("%f\t",*(A[k]+j));
		}
		printf("\n");
	}
}

void Matrscan(float A[MAX][MAX],int num)
{
	int j,k;
	for(k=0; k<num;k++)
	{
		printf("Please input line %d of this matrix:\n",k+1);
	    for(j=0;j<num;j++)
		{
			scanf("%f",A[k]+j);
		}
	}
}

void input()
{
	int i,j;
	printf("Please input the dimension of this matrix:\n");
	scanf("%d",&num);
	printf("The dimension of this matrix is %d:\n",num);
	Matrscan(a,num);
	Matrprint(a,num);
	
}

void solve()
{
	int i,j,k,count=0;
	float r1,r2=0;
	for(i=0;i<num;i++)
    {
		x[i]=0;
		y[i]=1;
	}
	for(j=1;j<200;j++)
	{
		r2=r1;
		for(i=0;i<num;i++)
		{
			x[i]=0;
		}
		for(i=0;i<num;i++)
		{
			for(k=0;k<num;k++)
			{
				x[i]+=a[i][k]*y[k];
			}
		}
		printf("The step %d 's vector x is:\n",j);
		Vprint(x,num);
		r1=x[1]/y[1];
		float max=0;
		for(k=0;k<num;k++)
		{
			if(max<=x[k])
			{
				max = x[k];
			}
		}
		for(k=0;k<num;k++)
		{
			y[k]=x[k]/max;
		}
		printf("The step %d of vector y is:\n",j);
		Vprint(y,num);
		if(fabs(r2-r1)<=1e-8)
		{
			break;
		}
	}
	printf("The main eigenvalue of this matrix is %f\n",r1);
	printf("The main eigenvactor of this matrix is:\n");
    Vprint(y,num);
}
int main()
{
	int judge=1;
	while(judge)
	{
		input();
		solve();
		printf("Would you like to continue (1Y0N)?\n");
		scanf("%d",&judge);
		system("cls");
	 } 
	 system("pause");
	 return 0;
}
