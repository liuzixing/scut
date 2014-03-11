#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100001;
int h,w,n;
long long add[maxn << 2];
long long sum[maxn << 2];
void PushUp(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void PushDown(int rt,int m)
{
	if (add[rt])
	{
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += (m - (m >> 1)) * add[rt];
		sum[rt << 1 | 1] += (m >> 1) * add[rt];
		add[rt] = 0;
	}
}
void build(int l,int r,int rt)
{
	add[rt] = 0;
	if (l == r) 
	{
		scanf("%lld",&sum[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(l,m,rt << 1);
	build(m + 1,r,rt << 1 | 1);
	PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if (L <= l && r <= R)
	{
		add[rt] += c;
		sum[rt] += (long long)c * (r - l + 1);
		return;
	}
	PushDown(rt,r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L,R,c,l ,m,rt << 1);
	if (R > m) update(L,R ,c,m + 1,r,rt << 1 | 1);
	PushUp(rt);
}
long long query(int L,int R,int l,int r,int rt)
{
	if (L <= l && r <= R)
		return sum[rt];
	PushDown(rt,r - l + 1);
	int m = (l + r) >> 1;
	long long ans = 0;
	if (L <= m) ans += query(L,R,l ,m,rt << 1);
	if (R > m) ans += query(L,R ,m + 1,r,rt << 1 | 1);
	return ans;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	build(1,n,1);
	while (q--)
	{
		int a,b,c;
		char op[2];
		scanf("%s",op);
		if (op[0] == 'C')
		{
			scanf("%d%d%d",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
		else
		{
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(a,b,1,n,1));
		}
	}
	return 0;
}
