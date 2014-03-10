#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	long  sum,n;
	while (cin >> n)
	{
		if (n % 2)
		{
			sum = (1 + n) / 2 * n;
		}
		else
		{
			sum =  n / 2 * (1 + n);
		}
		cout << sum;
		printf("\n\n");
	}
}