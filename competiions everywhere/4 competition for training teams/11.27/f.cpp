#include <iostream>
using namespace std;

int main()
{
	int f[10001],n,i;
	
	f[0] = 0;
	f[1] = 1;
	for (i = 2; i<=10000;i++)
	{
		f[i] = (f[i-1] + f[i-2]) %10;
	}
	while (cin >>n)
	{
    if (f[n] % 2 == 1)
	{
		cout << "odd" << endl;
	}
	else
	{
		cout << "even" << endl;
	}
	}
}