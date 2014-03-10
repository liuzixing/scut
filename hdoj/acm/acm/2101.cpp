#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	__int64 a,b;
	while (cin >> a >> b)
	{
		if ((a + b) % 86)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
}