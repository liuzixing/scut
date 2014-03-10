#include <iostream>
#include <stdio.h>

using namespace std;
int divisors(int factor,__int64 & n)
{
	int sum = 1;
	while (1)
	{
		if (n % factor == 0)
		{
			sum++;
			n /= factor;
		}
		else
		{
			break;
		}
	}
	return sum;
}
int main()
{
	__int64 n,ans;
	while (scanf("%I64d",&n) != EOF && n)
	{
		ans = 0;
		ans += divisors(2,n) * divisors(3,n) * divisors(5,n) * divisors(7,n);
		printf("%I64d\n",ans);
	}
}