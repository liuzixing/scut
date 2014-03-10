#include <iostream>
#include <cstdio>
#include <cmath>
const int N = 50001;
#define Max(a,b) a > b?a:b
#define Min(a,b) a < b?a:b

int n,q;
int maxm[N][16],minm[N][16],h[N];
void rmqinit(){
	for (int i = 0;i < n;i++){
		maxm[i][0] = h[i];
		minm[i][0] = h[i];
	}
	for (int j = 1;(1 << j) <= n;j++)
		for (int i = 0;i + (1 << j) - 1 < n;i++){
			maxm[i][j] = Max(maxm[i][j - 1],maxm[i + (1 << (j - 1))][j - 1]);
			minm[i][j] = Min(minm[i][j - 1],minm[i + (1 << (j - 1))][j - 1]);
		}
}
int Maxquery(int l,int r){
	int k = floor((log(r - l + 1.0)/log(2.0)));
	return Max(maxm[l][k],maxm[r - (1 << k) + 1][k]);
}
int Minquery(int l,int r){
	int k = floor((log(r - l + 1.0)/log(2.0)));
	return Min(minm[l][k],minm[r - (1 << k) + 1][k]);
}
int main(){
	while (~scanf("%d %d",&n,&q)){
		for (int i = 0;i < n;i++)
			scanf("%d",&h[i]);
		int l,r;
		rmqinit();
		for (int i = 0;i < q;i++){
			scanf("%d%d",&l,&r);
			printf("%d\n",Maxquery(l-1,r-1) - Minquery(l-1,r-1));
		}
	}
}