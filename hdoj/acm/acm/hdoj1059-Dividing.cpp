#include <iostream>
#include <cstdio>
using namespace std;

int sum,n[10],i,j,cas,k,a[100000],total,tem;
bool f[210002];
int main()
{
	while (scanf("%d%d%d%d%d%d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5]) != EOF)
	{
		sum = n[0] + n[1] * 2 + n[2] * 3 + n[3] * 4 + n[4] * 5 + n[5] * 6;
		if (sum == 0) break;
		printf("Collection #%d:\n",++cas);
		if (sum % 2)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		memset(f,0,sizeof f);
		sum /= 2;
		f[0] = 1;
		total = 0;
		for (i = 0;i < 6;i++)
		{
			if (n[i] == 0)
				continue;
			tem = 1;
			while (tem <= n[i])
			{
				a[total++] = tem * (i + 1);
				n[i] -= tem;
				tem = (tem << 1);
			}
			if (n[i])
				a[total++] = n[i] * (i + 1);
		}

		for (i = 0;i < total;i++)
			for (k = sum;k >= a[i];k--)
				if (f[k - a[i]])
						f[k] = 1;
		if (f[sum])
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}
}