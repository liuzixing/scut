//1：如果X是钥匙 则X1/2/3/4也是 所以a[I]=a[I-1]*4
//	2: 如果X不是，X2/3是则X由1/4组成/但要除去全1和全4 所以a[I]+=(2^(I-1)-2)*2
//	3 如果X不是 X1/4是。则X=Y（1/4） M=X1/4=Y（4/1）（1/4）
//	前I-2位可以是1234，但要除去全为1/4的情况 还有就是X是钥匙且X是以1/4结尾
//	的情况。我们用b[I]数组表示i位时以1/4结尾的的数量
//temp=4^(i-2)-2^(i-2)-b[i-1];
//则 b[i]=a[i-1]*2+temp;

#include <cstdio>
#include <cmath>
using namespace std;

__int64 f[32],g[32],t;
int n;
int main(){
	f[2] = 0;f[3] = 8;
	g[2] = 0;g[3] = 4;
	printf("N=2: 0\nN=3: 8\n");
	for (int i = 4;i < 32;i++){
		f[i] = f[i - 1] * 4;
		f[i] += __int64(pow(2.0,i) - 4);
		t = ((__int64)pow(4.0,i-2)-(__int64)pow(2.0,i-2))*2-g[i-1];
		f[i] += t;
		g[i] = f[i - 1] * 2 + t;
		printf("N=%d: %I64d\n",i,f[i]);
	}
	return 0;
}