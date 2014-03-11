#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n,ans;

int main()
{
	scanf("%d",&n);
	ans = n / 3 * 2;
	if (n % 3 == 2)
		ans += 1;
	printf("%d\n",ans);
}