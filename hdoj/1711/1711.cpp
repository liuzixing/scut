#include <iostream>
#include <stdio.h>

using namespace std;

int p[10001],a[1000001],b[10001];
int main()
{
	int i,j,n,m,t;
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&n,&m);
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (i = 1;i <= m;i++)
		{
			scanf("%d",&b[i]);
		}
		p[1] = 0;
		j = 0;
		for (i = 2;i <= m;i++)
		{
			while (j > 0 && b[i] != b[j + 1])
			{
				j = p[j];
			}
			if (b[j + 1] == b[i])
			{
				j++;
			}
			p[i] = j;
		}
		j = 0;
		bool flag = false;
		for (i = 1;i <= n;i++)
		{
			while (j > 0 && a[i] != b[j + 1])
			{
				j = p[j];
			}
			if (b[j + 1] == a[i])
			{
				j++;
			}
			if (j == m)
			{
				printf("%d\n",i - m + 1);
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			printf("-1\n");
		}
	}

}