#include <cstdio>

using namespace std;

int t,a,ans[1000],tot;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&a);
		tot = 0;
		while (a % 2 == 0){
			a /= 2;
		}
		if (a == 1){
			printf("No number can be output !\n");
			continue;
		}
		while (a > 1){
			if (a % 2 == 1){
				ans[tot++] = a;
				a = a * 3 + 1;
			}else{
				a /= 2;
			}
		}
		for (int i = 0;i < tot - 1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[tot - 1]);
	}
}