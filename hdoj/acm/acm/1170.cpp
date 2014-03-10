#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

double doit (char op,int a,int b)
{
	switch(op)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return double (a) / double (b);
	default :return 0;
	}
}
int main()
{
	int a,b,t;
	char op;
	double ans;
	cin >> t;
	while (t--)
	{
		cin >> op >> a >> b;
		ans = doit(op,a,b);
		if (int (ans) + 0.0000000000000001 < ans  )
		{
			printf("%.2lf\n",ans);
		}
		else
		{
			printf("%.0lf\n",ans);
		}
	}
}