#include <stdio.h>
void foo(int &a, int &b)
{
	a^=b^=a^=b;
}

int main()
{
	int a = 1,b = 2;
	a^=b^=a^=b;
	printf("%d %d\n",a,b);
}