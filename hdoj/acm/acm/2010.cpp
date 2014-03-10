#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int i,mm,nn,a,b,c,last = 0;
	char m[5],n[5];
	while (cin >> m >> n)
	{
		bool flag =true;
		mm = (m[0] - '0') * 100 + (m[1] - '0') * 10 + m[2] - '0';
		nn = (n[0] - '0') * 100 + (n[1] - '0') * 10 + n[2] - '0';
		last = 0;
		for (i = mm;i <= nn; i++)
		{
			a = i / 100;
			b = i / 10 % 10;
			c = i % 10;
			if (i == a*a*a + b*b*b + c*c*c )
			{
				if (last)
				   printf("%d ",last);
				last = i;
				flag = false;
			}
		}

		if (flag)
		{
			cout << "no\n";
		}
		else
		{
			cout << last << endl;
		}
	}

}