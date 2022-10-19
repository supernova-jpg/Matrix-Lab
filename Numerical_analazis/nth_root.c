#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
	double b=(power(2,i/n)+ power(2,i/n+1)/2);
	return b;
}
int main()
{
	double y,z=1,i;
	short int n;
	while(z)
	{
	    printf("Please input a positive number and the order:\n");
	    scanf("%lf,%d",&z,&n);
		i=approximate(z,n);
		printf("i=%.10g\n",i);

	    for(k=0; fabs(y-i)>=1e-7 ; k++)
     	{
		   y=i;
		   i=((n-1)*y+ z/power(y,n-1))/n;
		   printf("i=%.10g\n",i);
	    }
	
	    printf("The %dth roots of %.10g is %.10g\n",n,z,i);
	    printf("\nThe iteration step is %d\n\n",k);
	}
	
	system ("pause");
	return 0;
}
