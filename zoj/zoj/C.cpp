#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	double ans,p;
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d%lf",&n,&p);
		ans = 0;
		for (int i = n - 1;i > 0;i--){
			ans += double(n) * double (n - 1) / p / (double)i / double(n - i) / 2.0;
		}
		printf("%.3lf\n",ans);
	}
}