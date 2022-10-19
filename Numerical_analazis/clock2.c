#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double start,finish;
short int k;
double power(double a, short int b)
{
    if(b==0)
	{
		return 1; 
	}
	else
	{
	    return a*power(a,b-1);
	}
	
}

double approximate(double z,short int n)
{
	k=0;
	short int i=0;
	while(z>=2)
	{
		z/=2;
		i++;
	}
	double a=power(2,i/n),b=power(2,i/n+1);
	b=(a+b)/2.0;
	return b;
}
int main()
{
	double y,z;
	short int n=10,i;
    start=(double) clock();
	for(z=3;z<10000000;z++)
	{
        i=(int)z%180;
        y=sin(i*3.1415926/180);
	}
	finish=(double) clock();
    printf("%.1f ms\n",finish-start);
    start=(double) clock();
    for(z=3;z<10000000;z++)
    {
        y=pow(z,0.1);
    }
	finish=(double) clock();
    printf("%.1f ms\n",finish-start);
	system ("pause");
	return 0;
}