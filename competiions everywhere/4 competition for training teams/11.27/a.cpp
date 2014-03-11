#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("test.in");
	int t,n,min,a[110],tt,i;
	char c[110][110];
	cin >> t;
	while (t)
	{
		t--;
		min = 1000;
		cin >> n;
		for (i = 0;i < n;i++)
		{
			cin >> c[i];
			cin >> a[i];
			if (min > a[i])
			{
				min = a[i];
				tt= i;
			}
		}
		cout << c[tt] << endl;
	}
}