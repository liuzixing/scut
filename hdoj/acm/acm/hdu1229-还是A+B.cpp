#include <iostream>
#include <cstdio>
using namespace std;

int a,b,ak,bk,k;
int main(){
	while (~scanf("%d%d%d",&a,&b,&k)){
		if (a == 0 && b == 0) break;
		ak = a;bk = b;
		int at,bt,i;
		for (i = 0;i < k;i++){
			at = ak % 10;
			bt = bk % 10;
			if (at != bt){
				printf("%d\n",a + b);
				break;
			}
			ak /= 10;
			bk /= 10;
		}
		if (i == k){
			printf("-1\n");
		}
	}
}