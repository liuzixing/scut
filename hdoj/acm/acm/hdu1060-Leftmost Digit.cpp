#include <cstdio>
#include <cmath>
using namespace std;



int main(){
	int t,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		double ans = n  * log10(n * 1.0);
		ans -= floor(ans);
		printf("%d\n",(int)floor(pow(10.0,ans)));
	}
}