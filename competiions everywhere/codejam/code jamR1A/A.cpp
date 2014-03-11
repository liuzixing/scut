#include <iostream>
#include <cstdio>
using namespace std;

bool v[101];
int t,pd,pg,cases = 0,i,j;
__int64 n;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%I64d%d%d",&n,&pd,&pg);
		if ((pg == 0 && pd != 0) ||(pg == 100 && pd != 100)) 
		{
			printf("Case #%d: Broken\n",++cases);
			continue;
		}
		memset(v,0,sizeof v);
		if (n > 99)
			n = 100;
		for (i = 1;i <= n;i++)
		{
			for (j = 0;j <= i;j++)
			{
				if (j * 100 % i == 0)
					v[j * 100 / i] = 1;
			}
		}
		if (v[pd])
			printf("Case #%d: Possible\n",++cases);
		else
			printf("Case #%d: Broken\n",++cases);
	}
}