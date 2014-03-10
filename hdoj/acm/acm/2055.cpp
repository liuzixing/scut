#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int i,n,y,f[200];
	char x;
	for (i = 0;i < 26;i++)
	{
		f[i + 'a'] =  -i - 1;
		f[i + 'A'] = i + 1;
	}
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		printf("%d\n",y + f[x]);
	}
}