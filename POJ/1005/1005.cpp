#include<iostream>
using namespace std;

int main()
{
	int n, i, year;
	double x, y, area;
	i = 1;
	cin >> n;
	while (i <= n)
	{
		cin >> x >> y;
		area = 0.5 * 3.1415926 * (x * x + y * y);
		year = area / 50;
        cout << "Property " << i <<": This property will begin eroding in year " << year + 1 << "." << endl;
		i++;
	}
	cout << "END OF OUTPUT." << endl;
}