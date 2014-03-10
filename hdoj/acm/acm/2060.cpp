#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n,a,b,t;
	cin >> t;
	while (t--)
	{
		scanf("%d %d %d",&n,&a,&b);
		a += (n > 6) ? 8 * (n - 6) : 0;
		a += (n > 6) ? 27 : n * (15 - n) / 2;
		puts(a >= b ? "Yes" : "No");
	}
}