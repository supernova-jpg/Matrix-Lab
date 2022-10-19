#include<stdio.h>
#include<stdlib.h>

enum COLOR{red,yellow,green,NumCOLORS};
int main()
{
	int color =-1;
	char *ColorNames[NumCOLORS]={"red","yellow","green"};
	char *colorname = NULL;
	printf("Please input your favorite color code:\n");
	scanf("%d",&color);
	if(color>=0&&color<NumCOLORS)
	{
		colorname = ColorNames[color];
	}
	else
	{
		colorname = "Unknown";
	}
	printf("Your favorite color is %s\n",colorname);
	system("pause");
	return 0;
}
