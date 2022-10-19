#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double funeva(double a,double b,double c, double d, double x)
{
	double y=x*(x*(a*x+b)+c)+d;
	return y;
}
double diffeva(double a,double b,double c,double x)
{
	double y0=x*(3*a*x+2*b)+c;
	return y0;
}

double eqsolve(double a,double b,double c,double d)
{
   double e=-64,f=64;
   double x,m;
   int i=0; 
   while((f-e)>=0.25)
   {
   	 if(int(funeva(a,b,c,d,e))^int(funeva(a,b,c,d,(e+f)/2))<=0)
   	 {
   	 	f=(e+f)/2;
   	 	i++;
	 }
	 else
	 {
	 	e=(e+f)/2;
	 	i++;
	 }
   }
    x = (e+f)/2; 
   do
   {
   	m=funeva(a,b,c,d,x)/diffeva(a,b,c,x);
   	x-= m;
   	i++;
   }
   while(fabs(m)>=10e-10);
   printf("i=%d\n",i);
   return x;
}

int main()
{
	double a,b,c,d,x1,x2,x3;
	double B,C,delta;
	double y;
	int i=1;
	while(i)
	{
		printf("Please input the coefficient of cube equation:\n");
    	scanf("%lf,%lf,%lf,%lf",&a,&b,&c,&d);
	    x1=eqsolve(a,b,c,d);
    	printf("x[1]= %.8g\n",x1);
    	if(a!=0)
        {
         	B = b/a+x1;
         	C = -d/(a*x1);
    	    delta = B*B-4*C;
	        if(delta>=0)
            {
		         x2 = (-B+ sqrt(delta))/2.0;
		         x3 = (-B- sqrt(delta))/2.0; 
		         printf("x[2]= %.8g\nx[3]= %.8g\n",x2,x3); 
	        }
	        else
	       {
		        x2 = x3 = -B/2.0;
		        y = sqrt(-delta)/2.0;
	         	printf("x[2]= %.8g + %.8gi\n",x2,y);
		        printf("x[3]= %.8g - %.8gi\n",x2,y);
	        }
    	}
    	if(a==0)
    	{
    		x2 = -(c/b+x1);
    		printf("x[2]= %.8g\n",x2);
		}
	    printf("\n\nContinue 1(Yes)/0(No)?\n");
	    scanf("%d",&i);
	    printf("\n");
	    
	}
	system("pause");
	return 0;
}
