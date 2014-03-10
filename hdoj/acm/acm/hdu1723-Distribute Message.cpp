#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
__int64 dp[31][31];
int n,m;
int main(){
	for (int i = 1;i < 31;i++){
		dp[1][i] = 1;
		for (int j = 2;j < 31;j++)
			for (int k = 1;k <= i && j - k > 0;k++)
				dp[j][i] += dp[j - k][i];
	}
	dp[1][0] = 1;
	while (~scanf("%d %d",&n,&m) && (n || m)){
		printf("%I64d\n",dp[n][m]);
	}
}