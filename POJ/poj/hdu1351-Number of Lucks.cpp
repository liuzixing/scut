#include <cstdio>
#include <cmath>
using namespace std;

__int64 f[32],g[32],t;
int n;
int main(){
	f[2] = 0;f[3] = 8;
	g[2] = 0;g[3] = 4;
	for (int i = 4;i < 17;i++){
		f[i] = f[i - 1] * 4;
		f[i] += __int64(pow(2.0,i) - 4);
		t = ((__int64)pow(4.0,i-2)-(__int64)pow(2.0,i-2))*2-g[i-1];
		f[i] += t;
		g[i] = f[i - 1] * 2 + t;
	}
	while (~scanf("%d",&n)){
		if (n == -1) break;
		printf("%d: %I64d\n",n,f[n]);
	}
	return 0;
}