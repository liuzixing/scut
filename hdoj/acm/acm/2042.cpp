#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int n,i,t;
	cin >> t;
	while (t--)
	{
		int ans = 3;
		cin >> n;
		for(i = 0;i < n ;i++)
		{
			ans = (ans - 1) * 2;
		}
		printf("%d\n",ans);
	}
}