#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;

const int maxn = 111;
int g[maxn][maxn],dist[maxn];
char gtem[maxn][maxn];
int n,m,tot,v[maxn];
int x[maxn],y[maxn];
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
bool vv[51][51];
int qx[maxn * maxn / 4];
int qy[maxn * maxn / 4];
int step[maxn * maxn / 4];
int prim(int s,int n){
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
void bfs(int s){
	int head = 0,tail = 1;
	vv[x[s]][y[s]] = 1;
	qx[head] = x[s];
	qy[head] = y[s];
	step[head] = 0;
	int found = 1;
	while (head < tail){
		for (int k = 0;k < 4;k++){
			int tx = qx[head] + dx[k];
			int ty = qy[head] + dy[k];
			if (tx < n && tx >= 0 && ty < m && ty >= 0 && gtem[tx][ty] && !vv[tx][ty]){
				qx[tail] = tx;
				qy[tail] = ty;
				step[tail] = step[head] + 1;
				vv[tx][ty] = 1;
				if (gtem[tx][ty] != 120){
					g[s][gtem[tx][ty]] = step[tail];
					g[gtem[tx][ty]][s] = step[tail];
					found++;
				}
				if (found ==  tot) return;
				tail++;
			}
		}
		head++;
	}
}
int main(){
	int t;
	char cc[100];
	scanf("%d",&t);
	while (t--){
		scanf("%d %d",&m,&n);
		tot = 0;
		gets(cc);
		for (int i = 0;i < n;i++){
			gets(gtem[i]);
			for (int j = 0;j < m;j++)
				switch(gtem[i][j]){
				case ' ':gtem[i][j] = 120;break;
				case '#':gtem[i][j] = 0;break;
				default:x[++tot] = i;
						y[tot] = j;
						gtem[i][j] = tot;
			}
				
		}
		memset(v,0,sizeof v);
		for (int i = 1;i <= tot;i++){
			memset(vv,0,sizeof vv);
			bfs(i);
		}
		printf("%d\n",prim(1,tot));
	}
}