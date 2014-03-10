#include<iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n,i;
	int a[11];
	while (cin >> n && n)
	{
		for (i = 0;i < n;i++ )
			cin >> a[i];
		if (n % 2)
		{
			cout << 1 << endl;
			continue;
		}
		sort(a,a + n);
		for (i = 0;i < n;i += 2)
			if (a[i] != a[i + 1])
			{
				puts("1");
				goto finish;
			}
		puts("0");
		finish:;
	}
	return 0 ;
}