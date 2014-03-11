/*
ID: benbenq1
PROG: humble
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	int n,i,j,k,f[100001],t,index[101],prime[101];
	f[0] = 1;
	scanf("%d %d",&k,&n);
	for (i = 1;i <= k;i++)
	{
		scanf("%d",&prime[i]);
		index[i] = 0;
	}
	sort(prime + 1,prime + k + 1);

	for (i = 1;i <= n;i++)
	{
		f[i] = 0x7fffffff;
		for (j = 1;j <= k;j++)
		{
			if (f[i] > f[index[j]] * prime[j])
			{	
				f[i] = f[index[j]] * prime[j];
				t = f[i];
			}
		}
		for (j = 1;j <= k;j++)
		{
			if(f[index[j]] * prime[j] == t)
				index[j]++;
		}
	}
	printf("%d\n",f[n]);
}