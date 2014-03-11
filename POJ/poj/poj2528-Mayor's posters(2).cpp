#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1 | 1

const int maxn = 11115;
bool hash[maxn];
int li[maxn],ri[maxn];
int X[maxn * 3];
int cover[maxn << 4];
int ans;
void PushDown(int rt)
{
	if (cover[rt] != -1)
	{
		cover[rt << 1] = cover[rt << 1 | 1] = cover[rt];
		cover[rt] = -1;
	}
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if (L <= l && r <= R)
	{
		cover[rt] = c;
		return;
	}
	PushDown(rt);
	int m = (l + r) >> 1;
	if (L <= m) update(L,R,c,lson);
	if (R > m) update(L,R,c,rson);
}
void query(int l,int r,int rt)
{
	if (cover[rt] != -1)
	{
		if (!hash[cover[rt]])ans++;
		hash[cover[rt]] = true;
		return;
	}
	if (l == r) return;
	int m = (l + r) >> 1;
	query(lson);
	query(rson);
}
int bin(int key,int n)
{
	int l = 0,r = n - 1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (X[m] == key) return m;
		if (X[m] < key) l = m + 1;
		else r = m - 1;
	}
	return -1;
}

int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int nn = 0;
		for (int i = 0;i < n;i++)
		{
			scanf("%d%d",&li[i],&ri[i]);
			X[nn++] = li[i];
			X[nn++] = ri[i];
		}
		sort(X, X + nn);
		int m = 1;
		for (int i = 1;i < nn;i++)
			if (X[i] != X[i - 1]) X[m++] = X[i];
		for (int i = m - 1;i > 0;i--)
			if (X[i] != X[i - 1] + 1) X[m++] = X[i] + 1;
		sort(X, X + m);
		memset(cover,-1,sizeof cover);
		for (int i = 0;i < n;i++)
		{
			int l = bin(li[i],m);
			int r = bin(ri[i],m);
			update(l,r,i,0,m,1);
		}
		ans = 0;
		memset(hash,0,sizeof hash);
		query(0,m,1);
		printf("%d\n",ans);
	}
}
