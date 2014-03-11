/*
ID: benbenq1
PROG: milk6
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
#include <memory>
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
FILE *fin = fopen("milk6.in","r");
FILE *fout = fopen("milk6.out","w");

long long c[33][33],residue[33][33],residuenow[33][33];
int n,m,x,y,i,j,edgesum,source,target;
long long edge1[1001][4];
long long imax;
int h[101],gap[101];
void init()
{
	int i;
	long long cost;
	fscanf(fin,"%d %d",&n,&m);
	for (i = 1;i <= m;i++)
	{
		fscanf(fin,"%d %d %lld",&x,&y,&cost);
		if (cost != 0)//等于0的不加边
		{
			edgesum++;
			edge1[edgesum][1] = x;
			edge1[edgesum][2] = y;
			edge1[edgesum][3] = cost * 1001 + 1; //加权
			c[x][y] += edge1[edgesum][3];
			imax += edge1[edgesum][3];
		}
	}

	source = 1;
	target = n;
}
long long aug(int x,long long int flow)
{
	long long int remain,f,l;
	int p,minh;
	if (x == target)
		return flow;
	remain = flow;
	minh = n + 1;
	for (p = 1;p <= n;p++)//多路增广
		if (residue[x][p] > 0)
		{
			if (h[p] + 1 == h[x])
			{
				if (residue[x][p] < remain) l = residue[x][p];
				else l = remain;
				f = aug(p,l);
				remain -= f;
				residue[x][p] -= f;
				residue[p][x] += f;
				if (h[source] > n) return flow - remain;
				if (remain == 0) break;
			}
			if (h[p] < minh) minh = h[p];
		}
	if (remain == flow)//GAP优化
	{
		gap[h[x]]--;
		if (!gap[h[x]]) h[source] = n + 1;
		h[x] = minh + 1;
		gap[h[x]]++;
	}
	return flow - remain;
}
long long makemaxf()
{
	int i,j;
	long long ans = 0;
	for (i = 0;i < 101;i++)
		h[i] = gap[i] = 0;
	for (i = 0;i < 33;i++)
		for (j = 0;j < 33;j++)
			residue[i][j] = c[i][j];//residue残量网络
	gap[0] = n;
	while (h[source] <= n)
		ans += aug(source,imax);
	return ans;
}
void solving()
{
	long long maxf,maxf1;
	int i,j,k;
	maxf = makemaxf();
	fprintf(fout,"%lld %lld\n",maxf / 1001,maxf % 1001);
	for (i = 0;i < 33;i++)
		for (j = 0;j < 33;j++)
			residuenow[i][j] = residue[i][j];//成功的时候的residue要存下来
	for (i = 1;i <= edgesum;i++)
	{
		if (residuenow[edge1[i][1]][edge1[i][2]] == 0)//最小割的必要条件
		{
			c[edge1[i][1]][edge1[i][2]] -= edge1[i][3];
			maxf1 = makemaxf();
			if (maxf - maxf1 == edge1[i][3])
			{
				fprintf(fout,"%d\n",i);
				maxf = maxf1;
				for (j = 0;j < 33;j++)
					for (k = 0;k < 33;k++)
						residuenow[j][k] = residue[j][k];
			}
		}
		else
			c[edge1[i][1]][edge1[i][2]] += edge1[i][3];
	}
}
int main()
{
	init();
	solving();
	fclose(fin);
	fclose(fout);
}