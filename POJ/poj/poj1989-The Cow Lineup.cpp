#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

int main()
{
	int n,k,sum = 1,cal = 0,a;
	bool f[10001] = {0};
	cin >> n >> k;
	while(n--)
	{
		scanf("%d",&a);
		if (!f[a])
		{
			f[a] = 1;
			cal++;
		}
		if(cal == k)
		{
			memset(f,0,sizeof(f));
			cal = 0;
			sum++;
		}
	}
	printf("%d\n",sum);
}