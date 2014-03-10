#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
long long int f[13][2100];
//__int64 f[13][2100];
int t[14000][2];
int h,w,tn;
void dfs(int n,int res,int tar){
	if (n > w) return ;
	if (n == w){
		t[tn][0] = res;
		t[tn++][1] = tar;
		return ;
	}
	dfs(n + 2,(res << 2) | 3,(tar << 2) | 3);//水平放
	dfs(n + 1,(res << 1) | 1,(tar << 1));//竖直放
	dfs(n + 1,(res << 1),(tar << 1) | 1);//不放
}
void dp(){
	memset(f,0,sizeof f);
	f[0][(1 << w) - 1] = 1;
	for (int i = 1;i <= h;i++)
		for (int j = 0;j < tn;j++)
			f[i][t[j][1]] += f[i - 1][t[j][0]];
}
int main(){
	while (~scanf("%d %d",&h,&w)){
		if(h == 0 && w == 0) break;
		if (h < w) swap(h,w);
		if (h * w % 2){
			printf("0\n");
			continue;
		}
		tn = 0;
		dfs(0,0,0);
		dp();
		cout << f[h][(1 << w) - 1] << endl;
		//printf("%I64d\n",f[h][(1 << w) - 1]);
	}
	return 0;
}