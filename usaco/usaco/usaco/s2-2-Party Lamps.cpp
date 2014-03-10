/*
ID: benbenq1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <stdio.h>

using namespace std;
bool  ans[17][101];
const int b[4] = {1,2,4,8};
int c,n,on[101],off[101];
void change(int x,int k)
{
	int i;
	switch(k)
	{
	case 0:for (i = 1;i <= n;i++)
		   {
			   ans[x][i] ^= 1; 
		   }
		   break;
	case 1:for (i = 1;i <= n;i += 2)
		   {
			   ans[x][i] ^= 1;
		   }
		   break;
	case 2:for (i = 2;i <= n;i += 2)
		   {
			   ans[x][i] ^= 1;
		   }
		   break;
	case 3:for (i = 0;i * 3 + 1 <= n;i++)
		   {
			   ans[x][i * 3 + 1] ^= 1;
		   }
		   break;
	}
}
void solve(int x)
{
	int i;
	for (i = 0;i < 4;i++)
	{
		if (b[i] & x)
		{
			change(x,i);
		}
	}
}
bool cmp(int x,int y)
{
	int i;
	for (i = 1;i <= n;i++)
	{
		if (ans[x][i] > ans[y][i])
		{
			return 1;
		}
		if (ans[x][i] < ans[y][i])
		{
			return 0;
		}
	}
	return 0;
}
void sort1()
{
	int i,j,k,t;
	for (i = 0;i < 15;i++)
	{
		for (j = i + 1;j < 16;j++)
		{
			if (cmp(i,j))
			{
				for (k = 0;k <= n;k++)
				{
					t = ans[i][k];
					ans[i][k] = ans[j][k];
					ans[j][k] = t;
				}
			}
		}
	}
}
bool check(int x)
{
	int i,t = 0;
	for (i = 0;i < 4;i++)
	{
		if (b[i] & x)
		{
			t++;
		}
	}
	for (i = 1;i <= on[0];i++)
	{
		if (ans[x][on[i]] == 0)
		{
			return 0;
		}
	}
	for (i = 1;i <= off[0];i++)
	{
		if (ans[x][off[i]] == 1)
		{
			return 0;
		}
	}
	if (c >= t && (c - t) % 2 == 0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int tem,i,j;
	for (i = 0;i <= 16;i++)
	{
		for (j = 0;j < 101;j++)
		{
			ans[i][j] = 1;
		}
	}
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&c);
	while (scanf("%d",&tem) && tem != -1)
	{
		on[0]++;
		on[on[0]] = tem;
	}
	while (scanf("%d",&tem) && tem != -1)
	{
		off[0]++;
		off[off[0]] = tem;
	}

	for (i = 0;i < 16;i++)
	{
		solve(i);
	}

	for (i = 0 ;i < 16;i++)
	{
		if (check(i))
		{
			ans[i][0] = 1;
		}
		else
		{
			ans[i][0] = 0;
		}
	}
	sort1();
	bool f = 0;
	for (i = 0 ;i < 16;i++)
	{
		if (ans[i][0])
		{
			f = 1;
			for (j = 1;j <= n;j++)
			{
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	if (!f)
	{
		printf("IMPOSSIBLE\n");
	}
}