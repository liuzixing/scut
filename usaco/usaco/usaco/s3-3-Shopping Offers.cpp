/*
ID: benbenq1
PROG: shopping
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;
int f[6][6][6][6][6];
struct anode
{
	int v,k[1002];
}a[102];

struct bnode
{
	int c,m;
}b[6];

int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	int s,n,c,bb,i,j,b1,b2,b3,b4,b5,m1,m2,m3,m4,m5;
	//优惠方案
	scanf("%d",&s);
	for (i = 1;i <= s;i++)
	{
		scanf("%d",&n);
		for (j = 1;j <= n;j++)
		{
			scanf("%d",&c);
			scanf("%d",&a[i].k[c]);
		}
		scanf("%d",&a[i].v);
	}
	//购物单
	scanf("%d",&bb);
	for (i = 1;i <= bb;i++)
	{
		scanf("%d %d %d",&b[i].c,&b[i].m,&a[++s].v);
		a[s].k[b[i].c] = 1;
	}
	//DP
	memset(f,50,sizeof(f));
	f[0][0][0][0][0] = 0;
	for (i = 1;i <= s;i++)
	{
		m1 = a[i].k[b[1].c];
		m2 = a[i].k[b[2].c];
		m3 = a[i].k[b[3].c];
		m4 = a[i].k[b[4].c];
		m5 = a[i].k[b[5].c];
		for (b1 = m1;b1 <= b[1].m;b1++)
			for (b2 = m2;b2 <= b[2].m;b2++)
				for (b3 = m3;b3 <= b[3].m;b3++)
					for (b4 = m4;b4 <= b[4].m;b4++)
						for (b5 = m5;b5 <= b[5].m;b5++)
							f[b1][b2][b3][b4][b5] = min(f[b1][b2][b3][b4][b5],f[b1 - m1][b2 - m2][b3 - m3][b4 - m4][b5 - m5] + a[i].v);
	}
	printf("%d\n",f[b[1].m][b[2].m][b[3].m][b[4].m][b[5].m]);
}