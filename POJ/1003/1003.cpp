// 1003.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int times, i;
	double a, b, sum;
	while (cin >> a)
	{
		if (a == 0.00) 
		{
			break;
		}
		i = 1;
		sum = 0;
		times = 0;
		while (sum < a)
		{
			i++;
			b = 1.0 / i;
			sum = sum + b;
            times++;
		}
		cout << times << " card(s)" << endl;
		
	}
	
}

