#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	__int64 n,ans;
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%I64d",&n);
		ans = n * n % 10000;
		printf("%I64d\n",ans);

	}
}