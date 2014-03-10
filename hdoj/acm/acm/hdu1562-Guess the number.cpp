#include <cstdio>
using namespace std;

int a,b,c,x;
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d",&a,&b,&c);
		x = -1;
		for (int i = 1000;i < 10000;i++){
			if (i % a ==0 && (i + 1) % b == 0 && (i + 2) % c == 0){
				x = i;
				break;
			}
		}
		if (x > 0)
			printf("%d\n",x);
		else printf("Impossible\n");
			
	}
}