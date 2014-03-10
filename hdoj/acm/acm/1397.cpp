#include <iostream>
#include <stdio.h>

using namespace std;
int f[1000001];
void prime()
{
	int i,j;
	f[1] = 1;
	for (i = 2;i < 1000;i++)
	{
		if (!f[i])
		{
			for (j = i * 2;j < 1000001;j += i)
			{
				f[j] = 1;
			}
		}
	}
	return;
}
int main()
{
	int n,i;
	prime();

	while (cin >> n && n)
	{
		int ans  = 0;
		for (i = 2;i <= n / 2;i++)
		{
			if (!f[i] && !f[n - i])
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}