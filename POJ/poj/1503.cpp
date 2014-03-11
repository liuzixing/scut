#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <fstream>
using namespace std;
void conversion(char c[],int a[])
{
	int i;
	a[0] = strlen(c);
	for (i = 1; i <= a[0];i++)
	{
		a[i] = c[a[0] - i] - '0';
	}
}

void add(int a[],int b[])
{
	int i,c[10010];
	if (a[0] < b[0])
	{
		a[0] = b[0];
	}
	memset(&c,0,sizeof(c));
	for (i = 1;i <= a[0];i++)
	{
		c[i] += a[i]+ b[i];
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	c[0] = a[0];
	while (c[c[0]+1] > 0)
	{
		c[0]++;
	}
	for (i = 0; i <= c[0] ;i++)
	{
		a[i] = c[i];
	}
}
 int main()
 {
	 int sum[10010] = {0},a[1001],i;
	 char c[1001];
	 fstream fin("test.in");
	 cin >>c;
	 while (strcmp(c,"0"))
	 {
		 memset(&a,0,sizeof(a));
		 conversion(c,a);
		 add(sum,a);
		 cin >> c;
	 }
	 for (i = sum[0];i > 0;i--)
	 {
		 printf("%d",sum[i]);
	 }
	 printf("\n");
 } 