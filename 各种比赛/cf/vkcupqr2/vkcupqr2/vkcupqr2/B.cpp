#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n,m,ans,bea;
int f[1001][1001],g[1001][1001],aa,b;
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n;i++){
		scanf("%d%d",&aa,&b);
		g[b][aa]++;
		g[b][0]++;
	}
	for (int j = 0;j < m;j++){
		scanf("%d%d",&aa,&b);
		f[b][aa]++;
		f[b][0]++;
	}
	int tem;
	for (int i = 1;i <= 1000;i++)
		for (int j = 1;j <= 1000;j++){
			tem = min(f[i][j],g[i][j]);
			bea += tem;
			f[i][j] -= tem;
			f[i][0] -= tem;
			g[i][0] -= tem;
		}
	ans = bea;
	for (int i = 1;i <= 1000;i++)
		ans += min(f[i][0],g[i][0]);

	printf("%d %d\n",ans,bea);
}