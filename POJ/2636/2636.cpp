#include<iostream>
using namespace std;

int main()
{

	int n, k, a, i, j, sum;
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		cin >> k;
		sum = 0;
		for (j = 1; j <= k; j++)
		{
			cin >> a;
			sum +=a;
		}
		cout << sum - k + 1 <<endl;
	}
}