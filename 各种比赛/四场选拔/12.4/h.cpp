#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1000000005;
const int mod = 10007;
struct maxtril
{
	int m[2][2];
}a[31];
int two[31];
maxtril xc(maxtril x,maxtril y)
{
	maxtril tem;
	tem.m[0][0] = (((x.m[0][0] % mod) * (y.m[0][0] % mod)) % mod + ((x.m[0][1] % mod) * (y.m[1][0] % mod) % mod)) % mod;
	tem.m[0][1] = (((x.m[0][0] % mod) * (y.m[0][1] % mod)) % mod + ((x.m[0][1] % mod) * (y.m[1][1] % mod) % mod)) % mod;
	tem.m[1][0] = (((x.m[1][0] % mod) * (y.m[0][0] % mod)) % mod + ((x.m[1][1] % mod) * (y.m[1][0] % mod) % mod)) % mod;
	tem.m[1][1] = (((x.m[1][0] % mod) * (y.m[0][1] % mod)) % mod + ((x.m[1][1] % mod) * (y.m[1][1] % mod) % mod)) % mod;
	return tem;
}
maxtril addt (int x)
{
	if (x == 0 )
		return a[0];
	a[x] = xc(addt(x - 1),addt(x -1));
	return a[x];
}
int main()
{
	int t,i,n,p,q,nn;
	maxtril ans;
	two[0] = 1;
	for (i = 1;i < 31;i++)
	{
		two[i] = two[i - 1] + two[i - 1];
	}
	cin >> t;
	while (t)
	{
		t--;
		cin >> p >> q >> n;
		nn = n;
		for (i = 0;i < 31 ;i++)
		{
			a[i].m[0][0] = 10008;
		}
		a[0].m[0][0] = 0;
		a[0].m[0][1] = p % 10007;
		a[0].m[1][0] = 1;
		a[0].m[1][1] = q % 10007;
		ans.m[0][0] = 1;
		ans.m[0][1] = p % mod;
		ans.m[1][0] = 0;
		ans.m[1][1] = 1;
		for (i = 30;i >= 0;i--)
		{
			if (n - 2 - two[i] >= 0)
			{
				a[i] = addt(i);
				break;
			}
		}
		for (i = 30;i >= 0;i--)
		{
			if (n - 2 - two[i] >= 0)
			{
			     ans = xc(ans,a[i]);

			}        
		}
        switch(nn)
		{
		case 0:cout << 0 << endl; break;
		case 1:cout << 1 << endl;break;
		case 2:cout << p << endl;break;
		default:cout << ans.m[1][0] << endl;break;
		}
	}
}