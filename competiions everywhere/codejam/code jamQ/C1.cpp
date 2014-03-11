#include <iostream>
#include <cstdio>

using namespace std;

int t,n,c[1001],cases = 0,ans,MIN;
__int64 sum;
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int i;
	cin >> t;
	ans = 0;
	while (t--)
	{
		cin >> n;
		ans = 0;
		sum = 0;
		MIN = 102344123;
		for (i = 0;i < n;i++)
		{
			scanf("%d",&c[i]);
			ans ^= c[i];
			sum += c[i];
			if (MIN > c[i])
				MIN = c[i];
		}
		if (ans)
		{
			printf("Case #%d: NO\n",++cases);
		}
		else
		{
			printf("Case #%d: %I64d\n",++cases,sum - MIN);
		}
	}
}