#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,t,p[1001],sg;
int main()
{
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		sg = 0;
		for (int i = 1;i <= n;i++)
			scanf("%d",&p[i]);
		sort(p+1,p+n+1);
		for (int i = 1;i <= n;i++)
			if (i % 2)
				sg ^= p[n - i + 1] - p[n - i] - 1;
		if (sg)
			printf("Georgia will win\n");
		else
			printf("Bob will win\n");
	}
	return 0;
}