#include <cstdio>
#include <algorithm>
using namespace std;

int n;
double a[101],b,ans,x[101],t,m;
int main(){
	scanf("%d%lf",&n,&b);
	for (int i = 0;i < n;i++){
		scanf("%lf",&a[i]);
		m = max(m,a[i]);
	}
	for (int i = 0;i < n;i++)
		ans += m - a[i];
	if (ans > b)
		printf("-1\n");
	else{
		ans = (b - ans)  / n;
		for (int i = 0;i < n;i++){
			printf("%.6lf\n",m + ans  -  a[i]);
		}
	}
}