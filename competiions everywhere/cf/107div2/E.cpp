#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,c,x[154000],a,b,p,u[128];
long long sum,h[154000],y,z;
#define L t[k << 1]
#define R t[k << 1 | 1]
struct node {
	long long l,m,r;
}t[154000<<2],dp;
void build(int k,int l,int r){
	if(l + 1 < r){
		int m = (l + r) >> 1;
		build(k << 1 , l , m);
		build(k << 1 | 1 , m , r);
		t[k].m = max(L.r + R.l , max(L.m , R.m));
		t[k].l = max(L.l , R.l + h[m] - h[l]);
		t[k].r = max(R.r , L.r + h[r] - h[m]);
	}
	else 
		t[k].l = t[k].m = t[k].r = max(0ll , h[r] - h[l]);
}
void query(int k,int l,int r){
	if(l >= a && r <= b){
		if(~dp.m){
			dp.m = max(dp.m , max(t[k].m , dp.r + t[k].l));
			dp.l = max(dp.l , sum + t[k].l);
			dp.r = max(t[k].r , dp.r + h[r] - h[l]);
			sum += h[r] - h[l];
		}
		else 
			dp = t[k],sum = h[r] - h[l];
	}else{
		int m = (l + r) >> 1;
		if(m > a) query(k << 1 , l , m);
		if(m < b) query(k << 1 | 1 , m , r);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&c);
	for (int i = 0;i < n;i++)
		scanf("%d",x + i);
	for (int i = 0;i < n - 1;i++){
		scanf("%d",&p);
		h[i + 1] = h[i] + (x[i + 1] - x[i]) * 50ll - 1ll * p * c;
	}
	build(1,0,n - 1);
	while (m--){
		scanf("%d%d",&a,&b);
		a--;b--;dp.m = -1;
		query(1,0,n - 1);
		y += dp.m;
	}
	printf("%.8lf\n",y * 0.01);
	return 0;
}