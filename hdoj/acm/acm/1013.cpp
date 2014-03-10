#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

void init(char c[],int &ans)
{
	int i,len = strlen(c);
	ans = 0;
	for (i = 0 ;i < len;i++)
	{
		ans += c[i] - '0';
	}
}

int main()
{
	char c[1001];
	int ans;
	while (cin >> c && strcmp(c,"0"))
	{
		init (c,ans);
		int tem = 0;
		while (ans >= 10)
		{
			tem = ans;
			ans = 0;
			while (tem > 0)
			{
				ans += tem % 10;
				tem = tem / 10;
			}
		}
		cout << ans << endl;
	}
}