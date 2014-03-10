#include <iostream>
#include <cstdio>
using namespace std;

const double eps = 1e-7;
int n,k;
double a[10001],l,r,mid;;
bool check(double x){
	int ans = 0;
	for (int i = 0;i < n;i++){
		ans += int(a[i]/x);
		if (ans >= k)return true;
	}
	return false;
}
int main(){
	//double tem;
	while (~scanf("%d%d",&n,&k)){
		if (n == 0  && k == 0)
			break;
		l = 0;r = 0;
		for (int i = 0;i < n;i++){
			scanf("%lf",&a[i]);
			if (a[i] > r ) r = a[i];
		}
		while (r - l > eps){
			mid = (l + r) / 2.0;
			if (check(mid))
				l = mid;
			else r = mid;
		}
		if (int(r * 1000) % 10 >= 5) r -= 0.005;
		printf("%.2lf\n",r);
	}
}