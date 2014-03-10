#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
double  f[51];
double dfs(int b)
{ 
	if (b < 1)
	{
		return 0;
	}
	if (f[b] > 0)
	{
		return f[b];
	}
	f[b] = dfs(b - 1) + dfs(b - 2);
	return f[b]; 
}
int main()
{
	int n,a,b;
	memset(f,0,sizeof(f));
	f[1] = 1;
	f[50] = dfs(50);
	cin >> n;
	while (n--)
	{
		scanf("%d %d",&a,&b);	
		printf("%.0lf\n",f[b - a + 1]);
	}
}