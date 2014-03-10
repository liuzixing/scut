#include <iostream>
#include <stdio.h>
using namespace std;

__int64 gcd(__int64 a,__int64 b)
{
	if (a % b == 0)
	{
		return b;
	}
	return gcd(b,a % b);
}
__int64 lcm (__int64 a,__int64 b)
{
	__int64 tem;
	tem = a * b;
	return tem / gcd(a,b);
}
int main()
{
	__int64 t,a,ans,n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 1;
		while (n--)
		{
			scanf("%I64d",&a);
			ans = lcm(ans,a);
		}
		printf("%I64d\n",ans);
	}
}