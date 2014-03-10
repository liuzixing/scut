#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,j;
	unsigned long long g[65],f[64];
	f[1] = 1;
	for (i = 2;i < 65;i++)
	{
		f[i] = f[i - 1] * 2 + 1;
	}
	g[1] = 1;
	for (i = 2;i < 65;i++)
	{
		g[i] = f[i];
		for (j = 1;j * 2 <= i;j++)
		{
			g[i] = min(g[i],(f[j] + g[i -1 - j]) * 2 + 1);
		}
	}
	while (cin >> n)
	{
		cout << g[n] << endl;
	}
}
