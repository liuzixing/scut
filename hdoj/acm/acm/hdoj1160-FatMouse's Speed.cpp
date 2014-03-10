#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct mice
{
	int w,s,num;
}m[1001];
bool cmp (mice a,mice b)
{
	if (a.w == b.w)
	{
		return a.s > b.s;
	}
	return a.w < b.w;
}
int main()
{
	int j,i,n,total = 1,f[1001],tem;
	while (scanf("%d %d",&m[total].w,&m[total].s) != EOF)
	{
		m[total].num = total;
		total++;
	}
	total--;
	sort(m + 1,m + total + 1,cmp);
	for (i = 1;i <=total;i++)
	{
		f[i] = 1;
	}
	n = 1;
	for (i = 2;i <= total;i++)
	{
		for (j = 1;j < i;j++)
		{
			if (m[j].w < m[i].w && m[j].s > m[i].s)
			{
				f[i] = (f[j] + 1 > f[i]) ? f[j] + 1:f[i];
				n = (f[i] > f[n]) ? i : n;
			}
		}
	}
	vector<int> mm;
	tem = n;
	mm.push_back(n);
	printf("%d\n",f[n]);
	for (j = n - 1;j > 0 ;j--)
	{
		if (f[n] == f[j] + 1)
		{
			mm.push_back(j);
			n = j;
		}
	}
	for (i = f[tem] - 1;i >= 0;i--)
	{
		printf("%d\n",m[mm[i]].num);
	}
}