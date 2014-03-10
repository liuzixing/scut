#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;
struct node
{
	int l,x;
}a[1000002];
int b[1000002];
int h[1000001];
bool cmp(node i,node j)
{
	return i.x < j.x;
}
int main()
{
	int t,n,i,j;
	while (cin >> t)
	{
		while (t--)
		{
			scanf("%d",&n);
			for (i = 0;i < n;i++)
			{
				scanf("%d",&a[i].x);
				a[i].l = i;
			}
			sort(a,a + n,cmp);

			j = 0;
			a[n].x = 0x7fffffff;
			for (i = 0;i < n;i++)
			{
				b[a[i].l] = j;
				while (a[i].x == a[i + 1].x)
				{
					b[a[i + 1].l] = j;
					i++;
				}
				j++;
			}

			for (i = 0;i <= j;i++)
				h[i] = -1;
			int ans = 1,last = -1;

			for (i = 0;i < n;i++)
			{
				if (h[b[i]] > -1 && last < h[b[i]])
				{
					last = h[b[i]];
				}
				if (ans < i - last)
				{
					ans = i - last;	
				}
				h[b[i]] = i;
			}
			printf("%d\n",ans);
		}
	}
}