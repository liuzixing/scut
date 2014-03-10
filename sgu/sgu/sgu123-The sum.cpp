#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

__int64 f[42],sum;
int i,k;
int main()
{
	f[1] = 1;
	scanf("%d",&k);
	sum = 1;
	for (i = 2;i <= k;i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		sum += f[i];
	}
	printf("%I64d\n",sum);
}