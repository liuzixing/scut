#include<iostream>
#include <cstdio>
using namespace std;

int main()
{
	int i,k,now,ansi,ansj,sum,a[10001],ti,tj;
	while (scanf("%d",&k) != EOF && k)
	{
		now = 0;
		sum = -10000000;
		bool f = 0;
		for (i = 0;i < k;i++)
		{
			scanf("%d",&a[i]);
			if (a[i] >= 0)
			{
				f = 1;
			}
			if (now > 0)
			{
				tj = a[i];
				now = now + a[i];
			}
			else
				now = ti = tj = a[i];

			if(sum < now)
			{
				sum = now;
				ansi = ti;
				ansj = tj;
			}
		}
		if (!f)
			printf("0 %d %d\n",a[0],a[k -1]);
		else
			printf("%d %d %d\n",sum,ansi,ansj);
	}
}