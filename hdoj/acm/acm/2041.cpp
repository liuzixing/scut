#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int m,n;
	int i,f[41] = {0};
	cin >> n;
	f[1] = 1;
	for (i = 2;i < 41;i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	while (n--)
	{
		scanf("%d",&m);
		printf("%d\n",f[m]);
	}
}