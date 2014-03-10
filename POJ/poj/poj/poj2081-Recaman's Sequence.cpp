#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int f[500001];
bool a[3000001];
int main()
{
	int n,i;
	a[0] = 1;
	for (i = 1;i < 500001;i++)
	{
		if (f[i - 1] - i > 0 && !a[f[i - 1] - i])
		{
			f[i] = f[i - 1] - i;
			a[f[i - 1] - i] = 1;
		}
		else
		{
			f[i] = f[i - 1] + i;
			a[f[i]] = 1;
		}
	}

	while (cin >> n)
	{
		if (n == -1)
			break;
		cout << f[n] << endl;
	}
}

