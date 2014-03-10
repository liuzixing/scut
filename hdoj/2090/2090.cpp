#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
	char s[100];
	double a,b,sum = 0.0;
	while (scanf("%s %lf %lf",&s,&a,&b) != EOF)
	{
		sum += a * b;
	}
	printf("%.1lf\n",sum);
}