/*
ID: benbenq1
PROG: runround
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int d[10],c[10],v[10],len;
int n;
void partition(int x)
{
	d[0] = 0;
	while (x)
	{
		d[d[0] + 1] = x % 10;
		x /= 10;
		d[0]++;
	}
}
//void dfs(int x)
//{
//	int i;
//	if (x == 10)
//	{
//		return ;
//	}
//	int t = 0;
//	for (i = 9;i > 0 ;i--)
//	{
//		t = t * 10 + c[i];
//	}
//	num[len + 1] = t;
//	len++;
//	for (i = 0;i < 10;i++)
//	{
//		if (!v[i])
//		{
//			v[i] = 1;
//			c[x] = i; 
//			dfs(x + 1);
//			v[i] = 0;
//			c[x] = 0;
//		}
//	}
//}
bool check(int x)
{
	int i,j,tem;
	bool v[10] = {0};
	partition(x);
	tem = d[0];
	for (i = d[0];i > 0 ;i--)
	{
		tem -= d[tem];
		while (tem <= 0)
		{
			tem += d[0];
		}
		if (!v[d[tem]])
		{
			v[d[tem]] = 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
void work()
{
	int i,j;
	for (i = n + 1;1;i++)
	{
		if(check(i))
		{
			printf("%d\n",i);
			exit(0);
		}
	}
}
int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	scanf("%d",&n);
	work();
}