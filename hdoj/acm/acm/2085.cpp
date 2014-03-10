#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	__int64 f[34][2];
	int i,n;
	f[0][0] = 1;
	f[0][1] = 0;
	for (i = 1;i < 34;i++)
	{
		f[i][0] = f[i - 1][0] * 3 + f[i - 1][1] * 2;
		f[i][1] = f[i - 1][1] + f[i - 1][0] ;
	}
	while (cin >> n && n != -1)
	{
		cout << f[n][0] << ", " << f[n][1] << endl;
	}
}