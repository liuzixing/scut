#include <iostream>
#include <stdio.h>
using namespace std;
double a[100001];
int f[100001];
int n;
int main()
{
	int i,j,max;
	while (cin >> n)
	{
		max = 1;
	    for (i = 0;i < n;i++)
	    {
	    	scanf("%f",&a[i]);
	    }
		memset(f,0,sizeof(f));
		f[0] = 1;
		for (i = 1;i < n;i++)
		{
			f[i] = 1;
			for (j = i -1;j >= 0;j--)
			{
				if (a[j] < a[i] && f[i] < f[j] + 1)
				{
					f[i] = f[j] + 1;
					if (max < f[i])
					{
						max = f[i];
						break;
					}
				}
			}
		}
	    printf("%d", n - max);
	}
}