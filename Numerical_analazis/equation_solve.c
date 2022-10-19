#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10

int Vscan(double *p)
{
	int a=0;
	while(a<MAX)
	{
		scanf("%lf",(p+a));
		a++;
		char c= getchar();
		if(c=='\n')
		{
			break;
		}
	}
	return a;
}

void Vprint(double *p, int num)
{
	int i;
    for(i=0;i<num;i++)
   {
        printf("%f\n",*(p+i));
   }
   printf("\n\n");
}

void solve(double *A, double *B, int num)
{
	int i,j;
	double sum,a,b;
	//step1
    for(i=1;i<num;i++)
	{
		A[i]/= (-A[0]);
	}
	for(i=num;i<200;i++)
	{
		B[i]=0;
	}
    //step2
    B[num-1]=1;
	//step3
	for(j=0;j<200;j++)
	{
    	for(i=1;i<num;i++)
	    {
		    B[num+j] += A[i]*B[num-i+j];
	    }
		a = B[num+j-2]/B[num+j-3];
		b = B[num+j-1]/B[num+j-2];
		if(fabs(a-b)<1e-10 && j>=5)
		{
			break;
		}
	}
	puts("B");
	Vprint(B,num+j+1);
	printf("The max root of this equation is:\n%.10g\n\n",b);
}

int main()
{
	int judge = 1;
	
	while(judge)
	{
		int a;
		double A[MAX], B[200];
		printf("Please input your equation coefficients:\n");
	    a= Vscan(A);
		printf("a=%d\n",a);
		solve(A,B,a);
		printf("Would you like to continue?(Y/N)");
		scanf("%d",&judge);
		system("cls");
	}
	system("pause");
	return 0;
}