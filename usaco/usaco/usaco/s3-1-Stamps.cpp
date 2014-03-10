/*
ID: benbenq1
PROG: stamps
LANG: C++
*/
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 2000001;
int f[MAX];
int main()
{
	int k,n,i,a[51],limit,m = 0,t,j,l;
	ifstream cin("stamps.in");
	ofstream cout("stamps.out");
	cin >> limit >> n;
	for (i = 0;i < n;i++)
	{
		cin >> a[i];
		if (a[i] > m)
			m = a[i];
	}
	m = m * limit;
	for (i = 0;i < MAX;i++)
		f[i] = m;
	f[0] = 0;
	for (i = 0;i < n;i++)
	{
		j = 1;
		k = limit;
		while (k - j + 1 > 0)
		{
			t = j;
			if (k - 2 * j + 1 < 0)
				j = k - j + 1;
			for (l = m;l >= j * a[i];l--)
				if (f[l - j * a[i]] + j < f[l])
					f[l] = f[l - j * a[i]] + j;
			j = t * 2; 
		}
	}
	for (i = 1;i <= m;i++)
	{
		if (f[i] > 0 && f[i] <= limit)
			continue;
		else
			break;
	}
	cout << i - 1 << endl;
}