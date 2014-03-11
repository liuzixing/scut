/*
ID: benbenq1
LANG: C++
TASK: packrec
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;

int ans[101],area = INT_MAX;
struct rectangle
{
	int x,y;
}a[4],tem;

void check()
{
	if (tem.x * tem.y < area)
	{
		area = tem.x * tem.y;
		fill_n(ans + 1,100,0);
	}
	if (tem.x * tem.y == area)
	{
		ans[min(tem.x,tem.y)] = 1;
	}
}

void solve()
{
	//case 1
	tem.x = 0;tem.y = 0;
	for (int i = 0;i < 4;i++)
	{
		tem.x += a[i].x;
		if (a[i].y > tem.y)
		{
			tem.y = a[i].y;
		}
	}
	check();
	//case 2
	tem.x = 0;tem.y = 0;
	for (int i = 1;i < 4;i++)
	{
		tem.x  += a[i].x;
		if (a[i].y > tem.y)
		{
			tem.y = a[i].y;
		}
	}
	if (a[0].x > tem.x)
	{
		tem.x = a[0].x;
	}
	tem.y += a[0].y;
	check();
	//case 3
	tem.x = max(a[0].x + a[1].x,a[2].x) + a[3].x;
	tem.y = max(max(a[0].y,a[1].y) + a[2].y,a[3].y);
	check();
	//case 4,5
	tem.x = a[0].x + max(a[1].x , a[2].x) + a[3].x;
	tem.y = max(max(a[0].y,a[1].y + a[2].y),a[3].y);
	check();
	//case 6
	tem.x = a[0].x + a[1].x;
	tem.y = max(a[0].y + a[2].y,a[1].y + a[3].y);
	if (a[0].y < a[1].y)
	{
		tem.x = max(tem.x,a[2].x + a[1].x);
	}
	if (a[0].y + a[2].y > a[1].y)
	{
		tem.x = max(tem.x,a[2].x + a[3].x);
	}
	if (a[1].y < a[0].y)
	{
		tem.x = max(tem.x,a[0].x + a[3].x);
	}
	tem.x = max(max(tem.x,a[2].x),a[3].x);
	check();
}

void Rotate(int k)
{
	if (k == 4) 
	{
		solve();
	}
	else
	{
		Rotate(k+1); 
		swap(a[k].x, a[k].y);
		Rotate(k+1);
		swap(a[k].x, a[k].y);
	}
}
 
void Permutate(int k)
{
	if (k == 4) 
	{
		Rotate(0);
	}
	else
	{
		for (int i = k; i < 4; ++i)
		{
			swap(a[k], a[i]);
			Permutate(k+1);
			swap(a[k], a[i]);
		}
	}
}

int main()
{
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	for (int i = 0;i < 4;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	Permutate(0);
	printf("%d\n",area);
	for (int i = 1;i <= 100;i++)
	{
		if (ans[i])
		{
			printf("%d %d\n",i,area / i);
		}
	}
}