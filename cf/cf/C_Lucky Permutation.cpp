#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
__int64 fac[14]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};
int p[14],k,n,ans,total;
__int64 a[3000],b[14],xy[2] = {4,7};
void uncantor(int p[],int m,int n)
{
	int i,j,l,t;
	bool v[14];
	memset(v,0,sizeof v);
	m--;
	for (i = 1;i <= n;i++){
		t = m / fac[n - i];
		m -= t * fac[n - i];
		for (j = 1,l = 0;l <= t;j++)
			if (!v[j])l++;
		j--;
		v[j] = 1;
		p[i] = j;
	}
}
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
void deal(__int64 y,int &index){
	for (int i = 0;i <= total;i++)
		if (y < a[i]){
			index = i - 1;
			return;
		}
}
bool pd(__int64 y){
	for (int i = 0;i <= total;i++)
		if (y == a[i]){
			return 1;
		}else if (y < a[i]) return 0;
	return 0;
}
int main(){
	bool f = 0;
	scanf("%I64d %d",&n,&k);
	for (int i = 1;i <= 10;i++)
		dfs(0,i);
	deal(n,ans);
	ans++;
	__int64 nn = n;
	if (nn > 13) nn = 13;
	if (k > fac[nn]) ans = -1;
	else
	{
		uncantor(p,k,nn);
		if (n > 13){
			for (int i = 1;i <= 13;i++){
				p[i] += (n - 13);
				if (!pd(p[i]) && pd(n - 13 + i)) ans--;
			}
		}
		else{
			if (n >= 4 && p[4] != 4 && p[4] != 7) ans--;
			if (n >= 7 && p[7] != 4 && p[7] != 7) ans--;
		}
	}
	printf("%d\n",ans);
}