#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t,a,b;
	cin >> t;
	while (t--)
	{
		scanf("%d %d",&a,&b);
		a %= 100;
		b %= 100;
		printf("%d\n",(a + b) % 100);
	}
}