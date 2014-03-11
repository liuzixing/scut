#include <iostream>
#include <cmath>
using namespace std;
const int maxnum = 10000;
int k = 1;
void createprimenumber(int primenumber[])
{
	int i,j,t;
	primenumber[0] = 2;
	for (i = 3;i < 10000;i++)
	{
		t = int(sqrt(double (i)));
		int flag = true;
		for (j = 2 ;j <= t;j++)
		{
			if (i % j == 0)
			{
				flag =false;
				break;
			}
		}
		if (flag)
		{
			primenumber[k] = i;
			k++;
		}
	}
}
int main()
{
	int primenumber[10001],i,j,n;
	createprimenumber(primenumber);
	cin >> n;
	while (n)
	{
		int sum = 2;
		int ans = 0;
		i = 0;
		j = 0;
		while (sum <= n && primenumber[j] <= n)
		{
			if (sum == n)
			{
				ans++;
			}	
			if (sum + primenumber[j + 1] <= n)
			{
				sum += primenumber[j + 1];
				j++;
			}
			else
			{
				sum -= primenumber[i];
				i++;
			}
		}
		cout << ans << endl;
		cin >> n;
	}
}
