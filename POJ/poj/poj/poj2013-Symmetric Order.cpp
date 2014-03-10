#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int SET = 0,n,i,j;
	string s[16],ans[16];
	while (cin >> n && n)
	{
		SET++;
		printf("SET %d\n",SET);
		for (i = 0;i < n;i++)
			cin >> s[i];
		j = 0;
		for (i = 0;i < n;i += 2)
		{
			
			ans[n - j - 1] = s[i + 1];
			ans[j] = s[i];
			j++;
		}
		for (i = 0;i < n;i ++)
		{
			cout << ans[i] << endl;
		}

	}
}