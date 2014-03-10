#include <iostream>
using namespace std;
int main()
{
	int n, a[200], i = 1, total = 0, k = 1, rest, j;
	{

		cin >> n;
		while (total + i + 1 <= n)
		{
			i++;
			total += i;
		}
		if (total == n)
		{
			for (j = 2; j < i ; j++)
				cout << j << " ";
			cout << i ;
		}
		else
		{
			for  (j = 2; j <= i ; j++)
			{
				a[k] = j;
				k++;
			}
			rest = n - total;
			k--;
			j = k;
			while (rest)
			{
				rest--;
				a[k] ++;
				k--;
				if (k == 0)
				{
					k = j;
				}
			}
			for (k = 1; k < j; k++)
				cout << a[k] << " ";
			cout << a[j];

		}
		

	}
}