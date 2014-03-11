#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

int f[2][5001];

int main()
{
	int n,i,j,ans = 0;
	string s;
	cin >> n;
	getchar();
	getline(cin,s);
	for (i = n - 1;i >= 0;i--)
	{
		for (j = 0;j < n;j++)
		{
			if (s[i] == s[j])
			{
				f[i % 2][j] = f[(i + 1) % 2][j - 1] + 1;
			}
			else
			{
				f[i % 2][j] =  max(f[(i + 1) % 2][j],f[i % 2][j - 1]);
			}
			if (ans < f[i % 2][j])
				ans = f[i % 2][j];
		}
	}
	printf("%d\n",n - ans);
}