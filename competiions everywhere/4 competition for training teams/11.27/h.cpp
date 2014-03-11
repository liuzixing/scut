#include <iostream>
using namespace std;
int main()
{
	int n,f[10001],j,l,r;
	f[1] = 0;
	f[2] = 0;
	f[3] = 0;
	f[4] = 1;
	f[5] = 1;
	f[6] = 1;
    f[0] = 0;
	l = 1;
	r = 3;
	for (j = 7; j <10001;j++)
	{
		if (f[j -4] && f[j-5] && f[j-6] )
		{
			f[j] = 0;
		}
		else
		{
			f[j] = 1;
		}
	}

	while (cin >>n)
	{
		if (f[n])
		{
			cout << "win" << endl;
		}
		else
		{
            cout << "lose" << endl;
		}

	}
}