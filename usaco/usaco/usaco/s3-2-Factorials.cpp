/*
ID: benbenq1
PROG: fact4
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
	int n,i,ans;
	ans = 1;
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	scanf("%d",&n);
	for (i = 2;i <= n;i++)
	{
		ans = ans * i % 100000;
		while (ans % 10 == 0)
		{
			ans /= 10;
		}
	}
	printf("%d\n",ans % 10);
}