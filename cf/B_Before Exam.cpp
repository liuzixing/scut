#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct node
{
	int num;
	int val;
}a[102];
bool h[102];
int n,k,q,used,tem;
double sum[102];

bool cmp(node x,node y){
	return x.val > y.val;
}
int main(){
	scanf("%d %d",&n,&k);
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i].val);
		a[i].num = i;
	}
	scanf("%d",&q);
	for (int j = 0;j < q;j++){
		double s = 0;
		for (int i = 0; i < n / k;i++){
			scanf("%d",&tem);
			h[tem] = 1;
			s += a[tem].val;
		}
		sum[j] = s;
	}
	for (int i = 1;i <= n;i++)
		if (h[i]) used++;
	if (q > 0) sort(sum,sum + q);
	if (used >= n / k * k){
		printf("%.10lf %.10lf\n",sum[0] / (n / k),sum[q - 1] / (n / k));
	} else{
		sort(a + 1,a + n + 1,cmp);
		double s = 0,s2 = 0;
		int j = 1;
		for (int i = 1;i <= n && j <= n / k;i++)
			if (!h[a[i].num]){
				s += a[i].val;
				j++;
			}
		if (q > 0)s = max(sum[q - 1],s);
		j = 1;
		for (int i = n;i >= 1 && j <= n / k;i--)
			if (!h[a[i].num]){
				s2 += a[i].val;
				j++;
			}
		if (q > 0)s2 = min(sum[0],s2);
		printf("%.10lf %.10lf\n",s2 / (n / k),s / (n / k));
	}
}