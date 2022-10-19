#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct date
	{
		int month;
		int day;
		int year;
	}; //记得加分号！！！ 
	
	struct date today ={11,1,2020};
	struct date *time = &today;
	printf("Today's date is %i-%i-%i.\n",time->year,time->month,time->day);
	system("pause");
	return 0;
}
