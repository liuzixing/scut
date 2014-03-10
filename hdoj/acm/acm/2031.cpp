#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
const char c[17] = "0123456789ABCDEF";
void tentor(int n, int r)
{
	if (!n) return;
	tentor(n / r,r);
	putchar(c[n % r]);
}
int main()
{
	int n,r;
	while (cin >> n >> r)
	{
		if (n > 0)
		{
			tentor(n,r);
		}
		if (!n)
		{
			putchar('0');
		}
		if (n < 0)
		{
			putchar('-');
            tentor(-n, r);
		}
		putchar('\n');
	}
}