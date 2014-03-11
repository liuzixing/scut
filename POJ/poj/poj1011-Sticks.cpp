#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int a[70];
bool v[70];
int n;

bool dfs(int length,int rest,int restsum)
{
	int i;
	if (restsum == 0 && rest == 0)
		return 1;
	if (rest == 0)
		rest = length;
	if (rest > restsum)
		return 0;
	for (i = n - 1;i >= 0;i--)
	{
		if (v[i])
			continue;
		if (rest < a[i])
			continue;
		if ((i != n - 1) && (a[i] == a[i + 1]) && !v[i + 1])
			continue;
		v[i] = 1;
		if (dfs(length,rest - a[i],restsum - a[i]))
			return 1;
		v[i] = 0;
		if (a[i] == rest || rest == length)
			return 0;
	}
	return 0;

}
int main()
{
	int i;
	int sum = 0;
	while (scanf("%d",&n) != EOF && n)
	{
		sum = 0;
		int maxlength = 0;
		for (i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
			if (a[i] > maxlength)
				maxlength = a[i];
		}
		memset(v,0,sizeof(v));
		sort(a,a + n);
		for (i = maxlength;i <= sum;i++)
		{
			if (sum % i == 0)
			{
				if (dfs(i,i,sum))
				{
					cout << i << endl;
					break;
				}			
			}
		}
	}
}