/*
ID: benbenq1
PROG: kimbits
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

long long int f[50][50],i;
int main()
{
	int n,l,j,k;
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	scanf("%d %d %lld",&n,&l,&i);
	for (j = 0;j <= n;j++)
		f[j][0] = 1;
	for (j = 0;j <= l;j++)
		f[0][j] = 1;
	for (j = 1;j <= n;j++)
		for (k = 1;k <= l;k++)
			f[j][k] = f[j - 1][k] + f[j - 1][k - 1];
	i -= 1;
	for (j = n;j > 0;j--)
	{
		if (i && f[j - 1][l] <= i)
		{
			cout << 1;
			i -= f[j - 1][l];
			l -= 1;
		}
		else
		{
			cout << 0;
		}
	}
	cout << endl;
}
