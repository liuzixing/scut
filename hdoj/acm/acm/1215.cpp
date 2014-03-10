#include <iostream>
#include <stdio.h>
using namespace std;

int f[500001];

int main()
{
	int i,j,t,n;
	for (i = 1;i <= 500000 / 2;i++)
	{
		for (j = i + i;j < 500001;j += i)
		{
			f[j] += i;
		}
	}
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}	
}