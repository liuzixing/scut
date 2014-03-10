#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a,b,c,ans,C,n;
	cin >> C;
	while(C--)
	{
		scanf("%d",&n);
		a = n / 2;
		n -=n / 2;
		b = n * 2 / 3;
		c = n - b;
		a = (a % 10 && a) ? a / 10 + 1 : a  / 10;
		b = (b % 10 && b) ? b / 10 + 1 : b  / 10;
		c = (c % 10 && c) ? c / 10 + 1 : c  / 10;
		ans = a + b + c;
		printf("%d\n",ans);
	}
}