#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;

const int maxn = 1001;
long long g[maxn][maxn],dist[maxn];
int n,m,v[maxn];
long long x[maxn],y[maxn];
double prim(int s){
	v[s] = 1;
	for (int i = 1;i <= n;i++)
		dist[i] = g[s][i];
	double mincost = 0;
	for (int i = 0;i < n - 1;i++){
		long long tem = (long long) 1 << 63 - 1;
		int k;
		for (int j = 1;j <= n;j++)
			if (!v[j] && tem > dist[j]){
				tem = dist[j];
				k = j;
			}
		v[k] = 1;
		mincost += sqrt((double)tem);
		for (int j = 1;j <= n;j++)
			if (!v[j] && dist[j] > g[k][j])
				dist[j] = g[k][j];
	}
	return mincost;
}
int main(){
	while (~scanf("%d%d",&n,&m)){
		for (int i = 1;i <= n;i++)
			scanf("%lld%lld",&x[i],&y[i]);
		memset(g,0,sizeof g);
		memset(v,0,sizeof v);
		for (int i = 1;i < n;i++)
			for (int j = i + 1;j <= n;j++){
				g[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
				g[j][i] = g[i][j];
			}
		for (int i = 0;i < m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			g[a][b] = 0;
			g[b][a] = 0;
		}
		printf("%.2lf\n",prim(1));
	}
}