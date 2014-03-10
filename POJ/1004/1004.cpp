// 1004.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double a, sum = 0, i;
	for (i = 1; i <= 12; i++)
	{
		cin >> a;
		sum += a;
	}
	cout << "$" << sum / 12.0 ;
}

