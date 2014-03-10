#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 200001;
int Max[maxn << 2];
void PushUp(int rt)
{
	Max[rt] = max(Max[rt << 1],Max[rt << 1 | 1]);
}
void build(int l,int r,int rt)
{
	if (l == r)
	{
		scanf("%d",&Max[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(l,m,rt << 1);
	build(m + 1,r,rt << 1 | 1);
	PushUp(rt);
}
void update(int p,int s,int l,int r,int rt)
{
	if (l == r)
	{
		Max[rt] = s;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m)
		update(p,s,l,m,rt << 1);
	else
		update(p,s,m + 1,r,rt << 1 | 1);
	PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if (L <= l && r <= R)
		return Max[rt];
	int m = (l + r) >> 1;
	int ans = 0;
	if (L <= m) ans = max(ans,query(L,R,l,m,rt << 1));
	if (R > m) ans = max(ans,query(L,R,m + 1,r,rt << 1 | 1));
	return ans;
}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		build(1,n,1);
		char op[2];
		while (m--)
		{
			scanf("%s",op);
			int a,b;
			scanf("%d%d",&a,&b);
			if (op[0] == 'Q')
				printf("%d\n",query(a,b,1,n,1));
			else  update(a,b,1,n,1);
		}
	}
	return 0;
}