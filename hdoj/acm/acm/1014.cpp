#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main()
{
	int step,mod,i;
	int seed[100001];
	bool v[100000];
	while (cin >> step >> mod)
	{
		memset(v,0,sizeof(v));
		seed[0] = 0;
		bool flag = true;
		for (i = 1;i < mod;i++)
		{
			seed[i] = (seed[i - 1] + step) % mod;
			if (v[seed[i]])
			{
				cout << setw(10) << step << setw(10) << mod << "    Bad Choice\n" << endl;
				flag =  false;
				break;
			}
			v[seed[i]] = 1;
		}
		if (flag)
		{
			cout << setw(10) << step << setw(10) << mod << "    Good Choice\n" << endl;
		}
	}
}