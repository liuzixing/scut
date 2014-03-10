#include <iostream>
#include <stdio.h>
#include <cmath>
const int MAX = 1000000;
using namespace std;
int map[1001][1001];
int main()
{
	bool v[1010];
	int i,j,k,s,t,d,n,a,b,time,min,ans;
	while (scanf("%d %d %d",&t,&s,&d) != EOF)
	{
		n = 0;
		for (i = 0;i < 1001;i++)
		{
			for (j = 0;j < 1001;j++)
			{
				map[i][j] = MAX;
			}
		}
		for (i = 0;i < t;i++)
		{
			scanf("%d %d %d",&a,&b,&time);
			map[a][b] = (map[a][b] > time) ? time: map[a][b];
			map[b][a] = map[a][b];
			n = (n < b) ? b:n;
			n = (n < a) ? a:n;
		}
		for (i = 0;i <= n;i++)
		{
			v[i] = 0;
		}
		for (i = 0 ;i < s;i++)
		{
			scanf("%d",&a);
			map[0][a] = 0;
		}
		for (i = 1;i <= n;i++)
		{
			min = MAX;
			for (j = 1;j <= n;j++)
			{
				if (!v[j] && map[0][j] < min)
				{
					min = map[0][j];
					k = j;
				}
			}
			if (min == MAX)
			{
				break;
			}
			v[k] = 1;
			for (j = 1;j <= n;j++)
			{
				if (!v[j] && map[0][j] > map[0][k] + map[k][j])
				{
					map[0][j] = map[0][k] + map[k][j];
				}
			}
		}
		ans = MAX;
		for (i = 0;i < d;i++)
		{
			scanf("%d",&a);
			ans = (ans > map[0][a]) ? map[0][a]:ans;
		}
		printf("%d\n",ans);
	}
}