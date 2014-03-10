#include <stdio.h>
using namespace std;
long long n;
int i;
int main()
{
	while (~scanf("%lld",&n)) {
		long long temp = n,k = 2;
		while ((n & 1) == 0){
			n >>= 1;
			k <<= 1;
		}
		if (n == 1) {
			printf("-1\n");
			continue;
		}
		for (i = 3;i < k; i += 2)
			if (temp % i == 0)
				break;
		if (i < k) printf("%d\n",i);
		else printf("%d\n", k);
	}
}