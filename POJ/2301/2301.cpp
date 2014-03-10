#include <iostream>
using namespace std;

int main()
{
	int n,s,d;
	double x,y;
	cin >> n;
	while (n)
	{
		cin >> s >>d;
		x = (s + d)/2.0;
		y = (s - d) /2.0;
		if ((y < 0) || (x > s) || (int(x) - x != 0) || (int(y) - y != 0))
		{
			cout << "impossible" <<endl;
		}
		else
		{
			cout << x << " " << y << endl;
		}
		n--;
	}



}