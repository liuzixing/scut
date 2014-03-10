#include <iostream>
#include <cstdio>;
#include <string.h>
using namespace std;

__int64 a[10000];
int total,li,ri;
__int64 xy[2] = {4,7};
__int64 ans,ll,rr,l,r,b[11];
void dfs(int k,int n){
	if (k == n){
		__int64 sum = 0;
		for (int i = 0;i < n;i++){
			sum = sum * 10 + b[i];
		} 
		a[total] = sum;
		total++;
		return;
	}
	for (int i = 0;i < 2;i++){
		b[k] = xy[i];
		dfs(k + 1,n);
	}
}
__int64 deal(__int64 y,int & index ){
	for (int i = 0;i <= total;i++){
		if (y <= a[i]){
			index = i;
			return a[i];
		}
	}
}
int main(){
	for (int i = 1;i <= 10;i++)
	dfs(0,i);
	scanf("%I64d %I64d",&l,&r);
	deal(l,li);
	ll = l;
	rr = deal(r,ri);
	if (r < a[li]) ans = (r - l + 1) * a[li];
	else
	while (ll <= rr){
		if (a[li] <= r){
			ans += a[li] * (a[li] - ll + 1);
			ll = a[li] + 1;
			li++;
			
		}else {
			ans += a[li] * (r - a[li - 1]);
			break;
		}
	}
	printf("%I64d\n",ans);
}