/*
ID: benbenq1
LANG: C++
TASK: checker
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
int n,sum = 0,upperlim,path[14],m = 3;
void test(int row,int ld,int rd,int k)
{
	int pos,p,i;
	if (row != upperlim)
	{
		pos = upperlim & (~(row | ld | rd));
		while (pos)
		{
			p = pos & (-pos);
			pos -= p;
			int t = 1,tem = p;
			while (tem >> 1)
			{
				t++;
				tem = tem >> 1;
			}
			path[k] = t;
			test(row + p,(ld + p) << 1,(rd + p) >> 1,k + 1);
		}
	}
	else
	{
		if (m)
		{
			m--;
			for (i = 1;i < k - 1;i++)
			{
				printf("%d ",path[i]);
			}
			printf("%d\n",path[i]);
		}
		sum++;
	}
}
int main()
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	scanf("%d",&n);
	upperlim = (1 << n) - 1;
	test(0,0,0,1);
	printf("%d\n",sum);
}