#include <cstdio>
using namespace std;

int n,k,z;
int main(){
	scanf("%d",&n);
	while (n--){
		scanf("%d",&k);
		if (k < 0){
			printf("-");
			k = -k;
		}
		if (k == 0)
			printf("0\n");
		else{
			z = 0;
			while (k % 10 == 0){
				k /= 10;
				z++;
			}
			while (k){
				printf("%d",k % 10);
				k /= 10;
			}
			for (int i = 0;i < z;i++)
				printf("0");
			puts("");
		}
	}
}