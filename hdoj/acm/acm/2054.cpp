#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

void fuckthefloat (char *s)
{
	int len = strlen(s);
	char *p = s + len - 1;
	if (strchr(s,'.'))
	{
		while (*p == '0') 
		{
             *p = 0;
			 p--;
		}
	}
	if (*p == '.') *p = 0;
}
int main()
{
    char *pa, *pb;
	char a[100001],b[100001];
	while (scanf("%s %s",&a,&b) != EOF)
	{
		pa = a;
		pb = b;
		while (*pa == '0') 
		{
			pa++;
		}
		while (*pb == '0') 
		{
			pb++;
		}
		fuckthefloat(a);
		fuckthefloat(b);
		puts(strcmp(pa,pb) ? "NO" : "YES");
	}
}