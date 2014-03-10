#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
int m[1000001];
int main()
{
	int i,j,t,n;
	time_t start,end;
	start = clock();
	bool f[1001],a;
	for (i = 2;i < 1000001;i++)
		m[i] = 1;
	memset(f,0,sizeof(f));
	for (i = 2;i < 1001;i++)
	{
		for (j = i * 2;j <= 1000000;j += i)
		{
			m[j] += i;
			if (j / i > 1000)
				m[j] += j / i;
		}
	}
	for (i = 2;i < 1000001;i++)
	{
		if (m[i] < 1001)
			f[m[i]] = 1;
	}
	end = clock();
	cin >> t;
	while (t--)
	{
		scanf("%d",&n);
		if (!f[n])
			printf("yes\n");
		else
			printf("no\n");
	}
}