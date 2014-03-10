#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;
 
int main()
{
	int n;
	int a[3],b[3];
	cin >> n;
	while (n--)
	{
		cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
		a[1] += (a[2] + b[2]) / 60;
		a[2] = (a[2] + b[2]) % 60;
		a[0] += (a[1] + b[1]) / 60;
		a[1] = (a[1] + b[1]) % 60;
		a[0] = a[0] + b[0];
		cout << a[0] << " " << a[1] << " "  << a[2] << endl;
	}
}