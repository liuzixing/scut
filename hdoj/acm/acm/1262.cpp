#include <iostream>
#include <cmath>
using namespace std;
int primenumber[10001];
void createprimenumber()
{
	int i,j;
	for (i = 2;i <= 100;i++)
	{
		if (primenumber[i])
		for (j = 2 * i ;j <= 10000;j+=i)
		{
			primenumber[j] = 0;	
		}
	}
}
int main()
{
	int n;
	memset(primenumber, 1, sizeof(primenumber));
	createprimenumber();
	while (cin >> n)
	{
		int i;
		for(i = n/2; i >=3 ; i--)
		{
			if(primenumber[i] && primenumber[n-i])
			{
				cout  << i << " " << n - i <<endl;
				break;
			}
		}
	
	}
}