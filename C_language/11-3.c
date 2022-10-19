#include<stdio.h>
#include<stdlib.h>

struct date
{
	int month;
	int day;
	int year;
};

/*bool leapjudge(struct point *p)
{
	bool leap =false;
	if(p->year%4==0 && p->year%100==0 && p->year%400!=0)
	{
		bool leap= true;
	}
	return leap;
}

int number_of_days(struct point *p)
{
	const datePermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(p->month==2 && leapjudge(p->year))
	{
		int days= 29;
	}
	else
	{
		days= datePermonth[p->month-1];
	}
	return days;
}*/

int main()
{
	struct date today, tomorrow;
	struct date *p= &today, *q= &tomorrow;
	printf("Please input your date(mm/dd/yyyy):\n");
	scanf("%i,%i,%i",&p->month,&p->day,&p->year);
	printf("Today's date is %d-%d-%d\n",p->month,p->day,p->year);
	//if(p->day != number_of_days(*p))
	//{
		q->day= p->day+1;
		q->month= p->month;
		q->year= p->year;
	//}
	/*else if (p->month=12)
	{
		q->day=1;
		q->month=1;
		q->year=p->year+1;
	}
	else
	{
		q->day=1;
		q->month=p->month+1;
		q->year=p->year;
	}*/
	printf("Tomorrow's date is %d-%d-%d\n",q->month,q->day,q->year);
	system("pause");
	return 0;
}


