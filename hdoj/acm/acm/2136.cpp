#include <iostream>
#include <stdio.h>
using namespace std;
int a[1000001],b[1000001],c[100000];
void createprimenumber()
{
	int i,j;
	memset(a,0,sizeof(int) * 1000000);
	memset(b,0,sizeof(int) * 1000000);
	a[1] = 1;
	for (i = 2;i < 1000;i++)
	{
		if (!a[i])
		{
			for (j = i * 2;j < 1000000;j += i)
			{
				a[j] = 1;
			}
		}
	}
	c[0] = 0;
	for (i = 2;i < 1000000;i++)
	{
		if (!a[i])
		{
			b[0]++;
			b[i] = b[0]; 
			c[0]++;
			c[c[0]] = i;
		}
	}
	for (i = 1;i <= c[0];i++)
	{
		for (j = c[i] * 2;j < 1000000; j += c[i])
		{
			if (b[j] < i)
			{
				b[j] = i;
			}	
		}
	}
	b[0] = 0;
	return;
}
int main()
{
	
	int i,n;
	createprimenumber();
	while (scanf("%d",&n) != EOF)
	{
		printf("%d\n",b[n]);
	}
}
	