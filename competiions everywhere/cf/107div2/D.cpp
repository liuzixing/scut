#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;

__int64 n,m,k;
const __int64 mod =1000000007;
__int64 cal(__int64 m,__int64 n){
	__int64 r = 1;
	m %= mod;
	while (n){
		if (n & 1)
			r = r * m % mod;
		m = m * m % mod;
		n >>= 1;
	}
	return r;
}
int main(){
	cin >> n >> m >> k;
	if (k == 1 || k > n){
		printf("%d\n",cal(m,n));
		return 0;
	}
	if (k % 2 == 0){
		if (k < n)
			printf("%d\n",m);
		else
			printf("%d\n",cal(m,n / 2));
	}
	else{
		if (k == n)
			printf("%d\n",m * cal(m,n / 2) % mod);
		else
		printf("%d\n",m * m % mod); 
	}
}