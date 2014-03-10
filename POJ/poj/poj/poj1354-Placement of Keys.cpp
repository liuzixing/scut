#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;
//2*(n - 1)!
int n;
int ans[100001];
int main(){
	while (~scanf("%d",&n) && n > 0){
		memset(ans,0,sizeof ans);
		ans[0] = 1;
		ans[1] = 2;
		
		for (int i = 2;i <= n - 1;i++){
			int tmp = 0;
			for (int j = 1;j <= ans[0];j++){
				ans[j] = ans[j] * i + tmp;
				tmp = ans[j]  / 10000;
				ans[j] %= 10000;
			}
			if (tmp){
				ans[ans[0] + 1] = tmp;
				ans[0]++;
			}
		}
		printf("N=%d:\n",n);
		printf("%d",ans[ans[0]]);
		for (int i = ans[0] - 1;i > 0;i--)
			printf("%04d",ans[i]);
		printf("\n");
	}
}

