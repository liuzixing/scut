/*
ID: benbenq1
PROG: money
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

long long int f[10001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int v,n,i,j,a;
	scanf("%d %d",&v,&n);
	for (i = 1;i <= v;i++)
	{
		scanf("%d",&a);
		if (a <= n)
		f[a] += 1;
		for (j = a + 1;j <= n;j++)
		{
			f[j] += f[j - a];
		}
	}
	printf("%lld\n",f[n]);
}