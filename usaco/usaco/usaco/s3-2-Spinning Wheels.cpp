/*
ID: benbenq1
PROG: spin
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
bool f[6][360];
int speed[6],now[6];
bool can( int d)
{
	for (int i = 1; i <= 5;i++)
		if (!f[i][(now[i] + d) % 360])
			return 0;
	return 1;
}
int main()
{
	int t,a,b,i,j,k;
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	for (i = 1;i <= 5;i++)
	{
		scanf("%d%d",&speed[i],&t);
		//使用点去跟踪缺口，就相当于逆时针来转了，这速度是缺口的正向速度，所以要用360来减
		speed[i] = 360 - speed[i];
		for (j = 1;j <= t;j++)
		{
			scanf("%d %d",&a,&b);
			for (k = a;k <= a + b;k++)
				f[i][k % 360] = 1; 
		}
	}
	bool flag = false;
	for (t = 0;t < 360;t++)
	{
		if (flag)
			break;
		for (i = 0;i < 360;i++)
			if (can(i))
			{
				flag = true;
				break;
			}
		for (i = 1;i <= 5;i++)
			now[i] += speed[i];
	}
	if (flag)
		printf("%d\n", t - 1);
	else
		printf("none\n");
}
