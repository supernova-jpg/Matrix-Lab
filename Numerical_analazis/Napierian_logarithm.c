#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ln2 0.6931471805599

double power(double a,short int b)
{
    if(b==1)
	{
		return a;
	}
	else
	{
		return a*power(a,b-1);
	}
	
}

double ln(double n)
{
	double a,sum=0,x;
	short int i=0,m=1;
    while(n>=2)
    {
    	n/=2.0;
    	i++;
	}
	a = (n-1)/(1+n);
	do
	{
		x = (power(a,m))/m;
		sum += x;
		m +=2;
	}
	while(x >= 1e-12);
	sum = ln2 *i + 2*sum;
	m = i+ (m+1)/2;
	printf("The loop count of this algorithm is %d\n",m);
    return sum;
}
int main()
{
	double x,y,z;
	x = 1;
	while(x)
	{
		printf("Please input a positive number:\n");
		scanf("%lf",&x);
		y = ln(x);
		printf("ln(%.6g) = %.10f\n\n",x,y);
    }
	system("pause");
	return 0;
}

