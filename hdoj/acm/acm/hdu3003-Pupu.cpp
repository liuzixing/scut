#include <cstdio>
using namespace std;

__int64 n,p;
//¼ÆËãn^p % m
__int64 fastpow(__int64 n,__int64 p,__int64 m = 0x7fffffff){
	__int64 r = 1;
	while (p){
		if (p & 1)
			r = r * n % m;
		n = n * n % m;
		p >>= 1;
	}
	return r;
}
int main(){
	while (~scanf("%d",&n) && n){
		printf("%d\n",(fastpow(2,n - 1,n) + 1) % n );
	}
}