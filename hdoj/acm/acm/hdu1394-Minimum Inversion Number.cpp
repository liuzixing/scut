#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 5001;
int h,w,n;
int sum[maxn << 2];
void PushUp(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l,int r,int rt)
{
	sum[rt] = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(l,m,rt << 1);
	build(m + 1,r,rt << 1 | 1);
}
void update(int p,int l,int r,int rt)
{
	if (l == r)
	{
		sum[rt]++;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p,l,m,rt << 1);
	else
		update(p,m + 1,r,rt << 1 | 1);
	PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if (L <= l && r <= R)
		return sum[rt];
	int m = (l + r) >> 1;
	int ans = 0;
	if (L <= m) ans += query(L,R,l,m,rt << 1);
	if (R > m) ans += query(L,R,m + 1,r,rt << 1 | 1);
	return ans;
}
int a[maxn];
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		build(0,n - 1,1);
		int sum = 0;
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			sum += query(a[i],n - 1,0,n - 1,1);
			update(a[i],0,n - 1,1);
		}
		int ans = sum;
		for (int i = 0;i < n;i++)
		{
			sum += n - 1 - a[i] - a[i] ;
			ans = min(ans,sum);
		}
		printf("%d\n",ans);
	}
}