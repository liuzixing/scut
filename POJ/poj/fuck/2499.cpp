#include <iostream>
using namespace std;
int n,i;
void doit(int l,int r)
{
   int stepl = 0, stepr = 0,t;
	while  (l != 1 || r != 1)
	{
		if (l > r)
		{
			t = l / r;
			l = l - r * t;
			if (l <= 0)
			{
				l += r;
				t--;
			}
			stepl += t;
		}
		else
		{
			t = r / l;
			r = r - l * t;
			if (r <= 0)
			{
				r += l;
				t--;
			}
			stepr += t;
		}
	}
	cout << "Scenario #" << i <<":" << endl;
	cout << stepl << " " << stepr << endl;
	cout << endl;
}
int main()
{
	int l,r;
	cin >> n;
	i = 0;
	while (n - i)
	{
		i++;
		cin >> l >> r;
		doit(l,r);
	}
}