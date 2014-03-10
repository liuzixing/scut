/*
ID: benbenq1
PROG: inflate
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int f[10001],i,j,n,m,a,b;
int main()
{
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	scanf("%d %d",&m,&n);
	for (i = 0;i < n;i++)
	{
		scanf("%d %d",&a,&b);
		for (j = b;j <= m;j++)
		{
			f[j] = (f[j] < f[j - b] + a) ? f[j - b] + a:f[j];
		}
	}
	printf("%d\n",f[m]);
}