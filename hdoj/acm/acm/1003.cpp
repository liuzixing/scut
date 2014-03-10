#include <iostream>
#include <stdio.h>
using namespace std;
int f[100001],a[100001],len[100001],maxlen,maxsum,location;
int main()
{
	int t,n,i,e;
	cin >> t;
	e = t;
	while (t)
	{
		t--;
		scanf("%d",&n);
		f[0] = 0;
		len[0] = 0;
		maxlen = -100000000;
		maxsum = -100000000;
		for (i = 1;i <= n;i++)
		{
			scanf ("%d",&a[i]);
			len[i] = 1;
			f[i] = a[i];
			if (f[i] <= f[i - 1] + a[i])
			{
				f[i]  = f[i - 1] + a[i];
				len[i] = len[i - 1] + 1;
			}
		}
		for (i = n;i > 0;i--)
		{
			if (maxsum < f[i])
				{
					maxlen = len[i];
					maxsum = f[i];
					location = i;
				}
		}
		printf("Case %d:\n%d %d %d",e - t,maxsum,location - maxlen + 1,location);
		if (t)
		{
			printf("\n\n");
		}
		else
		{
			printf("\n");
		}
	}
}