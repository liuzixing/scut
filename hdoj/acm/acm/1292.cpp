#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


int main()
{
	__int64 f[26][26] = {0},ans = 0;
	int i,j,t,n;
	f[1][1] = 1;
	for (i = 2;i < 26;i++)
	{
		for (j = i;j > 0;j--)
		{
			f[i][j] = f[i - 1][j]  * j+ f[i - 1][j - 1];
		}
	}
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		for (i = n;i > 0;i--)
		{
			ans += f[n][i];
		}
		cout << ans << endl;
	}
}