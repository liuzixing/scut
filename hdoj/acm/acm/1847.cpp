#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i,j,f[11],v[1001],a[1001],n;
	memset(v,0,sizeof(v));
	memset(a,0,sizeof(a));
	f[0] = 1;
	v[1] = 1;
	for (i = 1 ;i < 11;i++)
	{
		f[i] = f[i - 1] * 2;
		v[f[i]] = 1;
	}
	a[1] = 1;
	for (i = 2;i < 1001;i++)
	{
		for (j = 0;j < 10;j++)
		{
			if (i - f[j] > 0)
			{
				if (!a[i - f[j]] || v[i])
				{
					a[i] = 1;
					break;
				}
				else
				{
					a[i] = 0;
				}
			}
		}
	}

	while (scanf("%d",&n) != EOF)
	{
		if (a[n])
		{
			printf("Kiki\n");
		}
		else
		{
			printf("Cici\n");
		}
		
	}
}