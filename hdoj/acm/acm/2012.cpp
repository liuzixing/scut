#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
int prime[3000];
void createprime()
{
	int i,j;
	prime[1] = 1;
	prime[0] = 1;
	for (i = 2; i < sqrt(3000.0); i++)
	{
		for (j = i * 2 ;j < 3000;j += i)
		{
			prime[j] = 1;
		}
	}
}
int main()
{
	int i,x,y,n;
	createprime();
	while (cin >> x >> y && x!=y!=0)
	{
		bool flag = true;
		for (i = x;i <=y;i++)
		{
			n = i * i + i + 41;
			if (prime[n])
			{
				cout << "Sorry\n";
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << "OK\n"; 
		}
	}

}