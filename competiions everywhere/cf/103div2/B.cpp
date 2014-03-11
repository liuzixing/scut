#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;

bool flag[10101];
int x[10101],y[10101];
int xa,ya,xb,yb,n,total,now;
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
int main(){
	while (~scanf("%d%d%d%d",&xa,&ya,&xb,&yb)){
		memset(flag,0,sizeof flag);
		total = abs(xa - xb) * 2  + 2 * abs(ya - yb);
		now = 0;
		scanf("%d",&n);
		if (xa > xb) swap(xa,xb);
		if (ya > yb) swap(ya,yb);
		for (int i = xa;i <= xb;i++){
			x[now] = i;
			y[now] = ya;
			now++;
			x[now] = i;
			y[now] = yb;
			now++;
		}
		for (int i = ya + 1;i < yb;i++){
			x[now] = xa;
			y[now] = i;
			now++;
			x[now] = xb;
			y[now] = i;
			now++;
		}
		int a,b,r;
		now = 0;
		for (int i = 0;i < n;i++){
			scanf("%d%d%d",&a,&b,&r);
			r *= r;
			for (int j = 0;j < total;j++)
				if ((x[j] - a) * (x[j] - a) + (y[j] - b) * (y[j] - b) <= r && !flag[j]){
					now++;
					flag[j] = 1;
				}
		}
		printf("%d\n",total - now);
	}
}