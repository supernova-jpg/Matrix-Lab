#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int mylen(const char *s1,const char *s2)
{
	int idx=0;
	while(s1[idx]!='\0'&&s1[idx]==s2[idx])
	{
		idx++;
	}
	return s1[idx]-s2[idx];
}
int main()
{
int size = 0;
char s1[] = "abcdefghijklmnopqrstuvwxyz";
char s2[] = "achfkd";
printf("%d\n",mylen(s1,s2));
int len = strlen(s1);
printf("%d\n",len);
size = sizeof(s1);
printf("%d\n",size);
system("pause");
return 0;
}
