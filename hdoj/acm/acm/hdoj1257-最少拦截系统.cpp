#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

int main()
{
	int n,i,j,a[10001];
	while (cin >> n)
	{
		for (i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		int ans = 0,count = n;
		while (count)
		{
			int t = 3000001;
			for (j = 1;j <= n;j++)
			{
				if (a[j] > 0 && a[j] < t)
				{
					count--;
					t = a[j];
					a[j] =  -1;
				}
			}
			ans++;
		}
		printf("%d\n",ans);
	}

}