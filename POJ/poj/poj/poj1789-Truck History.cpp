#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;

const int maxn = 2001;
int g[maxn][maxn],dist[maxn];
int n,v[maxn];
char x[maxn][10];
int prim(int s){
	v[s] = 1;
	for (int i = 1;i <= n;i++)
		dist[i] = g[s][i];
	double mincost = 0;
	for (int i = 0;i < n - 1;i++){
		int k,tem = INT_MAX;
		for (int j = 1;j <= n;j++)
			if (!v[j] && tem > dist[j]){
				tem = dist[j];
				k = j;
			}
		v[k] = 1;
		mincost += tem;
		for (int j = 1;j <= n;j++)
			if (!v[j] && dist[j] > g[k][j])
				dist[j] = g[k][j];
	}
	return mincost;
}
int main(){
	while (~scanf("%d",&n) && n){
		for (int i = 1;i <= n;i++)
			scanf("%s",&x[i]);
		memset(g,0,sizeof g);
		memset(v,0,sizeof v);
		for (int i = 1;i < n;i++)
			for (int j = i + 1;j <= n;j++){
				for (int k = 0;k < 7;k++)
					g[i][j] += x[i][k] != x[j][k];
				g[j][i] = g[i][j];
			}
		printf("The highest possible quality is 1/%d.\n",prim(1));
	}
}