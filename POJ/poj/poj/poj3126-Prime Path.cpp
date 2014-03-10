#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int source,target;
bool isprime[10001];
int q[10001][4],step[100001];
bool v[10001],flag;
void prime()
{
	int i,j;
	isprime[1] = 1;
	for (i = 2;i < 101;i++)
	{
		if (!isprime[i])
			for (j = i + i;j < 10001;j += i)
				isprime[j] = 1;
	}
}
void bfs()
{
	int head = 0,tail = 1,i,j,t[4],tem,k;
	v[source] = 1;
	i = 0;
	while (source)
	{
		q[0][i++] = source % 10;
		source /= 10;
	}
	while (head < tail)
	{
		for (i = 0;i < 4;i++)
			t[i] = q[head][i];
		for (i = 0;i < 4;i++)
		{
			tem = 0;
			for (j = 0;j < 10;j++)
			{
				t[i] = j;
				tem = t[0] + t[1] * 10 + t[2] * 100 + t[3] * 1000;
				if (tem > 1000 && !v[tem] && !isprime[tem])
				{
					for (k = 0;k < 4;k++)
					{
						q[tail][k] = t[k];
					}
					step[tail] = step[head] + 1;
					if (tem == target)
					{
						printf("%d\n",step[tail]);
						flag = true;
						return ;
					}
					v[tem] = 1;
					tail++;;
				}
			}
			t[i] = q[head][i];
		}
		head++;
	}
}
int main()
{
	int t;
	prime();
	scanf("%d",&t);
	while (t--)
	{
		flag = false;
		memset(v,0,sizeof(v));
		scanf("%d %d",&source,&target);
		if (source == target)
		{
			printf("%d\n",0);
			continue;
		}
		bfs();
		if (!flag)
			printf("Impossible\n");
	}
}