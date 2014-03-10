#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1000001;
bool isprime[N];
__int64 prime[79000];
int getprime(int n){
	int i,j,k = 0;
	int s,e = (int)sqrt(0.0 + n);
	memset(isprime,1,sizeof isprime);
	prime[k++] = 2;
	for (i = 4;i < n;i += 2)isprime[i] = 0;
	for (i = 3;i < e;i += 2)
		if (isprime[i]){
			prime[k++] = (__int64)i;
			for (s = i * 2,j = i * i;j < n;j += s)
				isprime[j] = 0;
		}
	for (;i < n;i += 2)
		if (isprime[i])
			prime[k++] = (__int64)i;
	return k;
}
int main(){
	int i,T,cas = 0;
	__int64 n;
	int totprime = getprime(N);
	scanf("%d",&T);
	while (T--){
		scanf("%I64d",&n);
		cas++;
		bool flag = 0;
		for (i = 0;i < totprime && prime[i] * prime[i] <= n;i++){
			if (n % (prime[i] * prime[i]) == 0){
				flag = 1;
				break;
			}
			while (n % prime[i] == 0)
				n /= prime[i];
		}
		__int64 x = (__int64)sqrt(n + 0.0);
		if (n - x * x < 0.000000001 ) flag = 1;
		if (flag)
			printf("Case %d: No\n",cas);
		else 
			printf("Case %d: Yes\n",cas);
	}
}