#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <set>
using namespace std;
struct node
{
	int x,y;
}p[2001];

bool cmp(const struct node &xx,const struct node &yy)
{
	if (xx.x == yy.x)
		return xx.y < yy.y;
	return xx.x < yy.x;
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF )
	{
		int sum = 0;
		for (int i = 0;i < n ;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p,p + n,cmp);
		for(int i = 0;i < n;i++)
		{
			for(int j = i + 1;j < n;j++)
			{
				if(p[i].x <= p[j].x && p[i].y >= p[j].y)
				{
					node p0,p1;
					p0.x = p[i].x + p[j].y - p[i].y;  
					p0.y = p[i].y + p[i].x - p[j].x;  
					p1.x = p[j].x + p[j].y - p[i].y;  
					p1.y = p[j].y + p[i].x - p[j].x;  
					if (!binary_search(p, p + n, p0, cmp))
						continue;
					if (!binary_search(p, p + n, p1, cmp))  
						continue;  
					sum++;
				}
			}
		}
		printf("%d\n",sum);
	}
}