#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool isprime[9989900];
int ans[1000];
void init()
{
	int i,j;
	i = 2;
	for (j = i * i;j <= 9989899;j += i)
	{
		isprime[j] = true;
	}
	for (i = 3;i <= 3163;i += 2)
	{
		if (isprime[i]) continue;
		for (j = i * i;j <= 9989899;j += i)
		{
			isprime[j] = true;
		}
	}
}
bool judge (int x)
{
	int t = x,b = 0;
	while (t != 0)
	{
		b *= 10;
		b += t % 10;
		t /= 10;
	}
	return x == b;
}
int main()
{
	int a,b,i,k = 0;
	init();
	for (i = 5;i <= 9989899;i += 2)
	{
		if (!isprime[i] && judge(i))
		{
			ans[k++] = i;
		}
	}
	while (scanf("%d%d",&a,&b) != EOF)
	{
		for (i = 0;i < k;i++)
		{
			if (ans[i] < a)
				continue;
			else
			{
				if (ans[i] <= b)
				{
					printf("%d\n",ans[i]);
				}
				else
				{
					break;
				}
			}
		}
		printf("\n");
	}
}