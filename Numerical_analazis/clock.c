#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>
#define ln2 0.6931471805599

double start,finish;
double power(double a, short int b)
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
	m = (m+1)/2+i;
    return sum;
}
int main()
{
	double x,y;
    start=(double) clock(); 
	for(x=3;x<10000000;x++)
	{
	y = ln(x);
    }
    finish=(double) clock(); 
    printf("%.1f ms\n",finish-start);
    start=(double) clock(); 
    for(x=3;x<10000000;x++)
	{
	y = log(x);
    }
    finish=(double) clock(); 
    printf("%.1f ms\n",finish-start);
	system("pause");
	return 0;
}