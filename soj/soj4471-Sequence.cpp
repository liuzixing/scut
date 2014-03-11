#include <stdio.h>
using namespace std;
int main()
{
	long long n;
	while (~scanf("%lld",&n)) {
		long long temp = n;
		while (n % 2 == 0) 
			n >>= 1;
		if (n == 1) {
			printf("-1\n");
			continue;
		}
		n = temp;
		if (n & 1) {
			printf("2\n");
			continue;
		}
		int i;
		for (i = 3;; i++) {
			long long sum = i;
			sum = (1 + sum) * sum >> 1;
			if ((n - sum) % i == 0) break;
		}
		printf("%d\n", i);
	}
}
