#include<iostream>
using namespace std;
int main()
{
	int n, x, i, max;
	while ((cin >> n)&&(n != 0))
	{
		max = 0;
		for (i = 1; i <= n; i++)
		{
			cin >> x;
			if (x > max) 
			{
				max = x;
			}
		}
		cout << max + 1 << endl;
	}

}