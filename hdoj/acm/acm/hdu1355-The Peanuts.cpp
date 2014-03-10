#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node{
	int x,y,p;
}b[2501];
int n,m,t,k,tot,a,ans,now,u;
bool cmp(node a,node b){
	return a.p > b.p;
}
int main(){
	scanf("%d",&t);
	while (t--){
		tot = 0;
		scanf("%d%d%d",&m,&n,&k);
		for (int i = 1;i <= m;i++)
			for (int j  = 1;j <= n;j++){
				scanf("%d",&a);
				if (a){
					b[tot].x = i;
					b[tot].y = j;
					b[tot++].p = a;
				}
			} 
		sort(b,b + tot,cmp);
		u = b[0].x + 1;
		now = b[0].p;
		ans = 0;
		if (u + b[0].x <= k)
			ans = now;
		int i = 0;
		while (u + b[i].x <= k && i < tot){
			now += b[i + 1].p;
			u += abs(b[i + 1].x - b[i].x) + abs(b[i + 1].y - b[i].y) + 1;
			i++;
			if (i < tot && u + b[i].x <= k)
				ans = max(now,ans);
		}
		printf("%d\n",ans);
	}
}