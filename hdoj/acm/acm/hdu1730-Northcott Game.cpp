#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int a,b,ans,n,m;
	while (~scanf("%d %d",&n,&m)){
		ans = 0;
		for (int i = 0;i < n;i++){
			scanf("%d%d",&a,&b);
			ans ^= abs(a - b) - 1;
		}
		if (ans > 0) printf("I WIN!\n");
		else printf("BAD LUCK!\n");
	}
}