#include<iostream>
using namespace std;
int main()
{
	int n, x, y, i;
	cin >> n;
	for (i = 1;i <= n;i++ )
	{
		cin >> x >>y;
		if (x < y)
		{
			cout << "NO BRAINS" << endl;
		}
		else
		{
			cout << "MMM BRAINS" <<endl; 
		}
	}

}