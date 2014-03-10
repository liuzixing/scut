/*
ID: benbenq1
PROG: cowcycle
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;
const int MAX = 11;

int s1[MAX],s2[MAX],ans1[MAX],ans2[MAX];
int f,r,f1,f2,r1,r2,cnt;
double rate[MAX * MAX],diff[MAX * MAX],minf = 0x7fffffff;
void init()
{
	freopen("cowcycle.in","r",stdin);
	freopen("cowcycle.out","w",stdout);
	cin >> f >> r >> f1 >> f2 >> r1 >> r2;
	cnt = f * r;
}
void solve()
{
	int i,j,k = 0,l;
	double sum = 0,ave,vf = 0,sumf = 0,p;
	for (i = 1;i <= f;i++)
		for (j = 1;j <= r;j++)
		{
			p = (double)s1[i] / s2[j];
			//²åÈëÅÅÐò
			l = ++k;
			while (rate[l - 1] >= p)
			{
				rate[l] = rate[l - 1];
				l--;
			}
			rate[l] = p;
		}
		for (i = 1;i <= cnt - 1;i++)
		{
			diff[i] = rate[i + 1] - rate[i];
			sum += diff[i];
			sumf += diff[i] * diff[i];
		}
		ave = sum / (cnt - 1);
		//·½²î
		vf = sumf - sum * ave;
		if (vf < minf)
		{
			minf = vf;
			memcpy(ans1 + 1,s1 + 1,sizeof(int) * f);
			memcpy(ans2 + 1,s2 + 1,sizeof(int) * r);
		}
}
void sc2(int k,int n)
{
	int i;
	if (k == r + 1)
	{
		if (s1[f] * s2[r] < 3 * s1[1] * s2[1])
			return;
		solve();
		return;
	}
	for (i = n;i <= r2 - r + k;i++)
	{
		s2[k] = i;
		sc2(k + 1,i + 1);
	}
}
void sc1(int k,int n)
{
	int i;
	if (k == f + 1)
	{
		sc2(1,r1);
		return;
	}
	for (i = n;i <= f2 - f + k;i++)
	{
		s1[k] = i;
		sc1(k + 1,i + 1);
	}
}

void PRINT()
{
	int i;
	for (i = 1;i <= f - 1;i++)
		cout << ans1[i] << ' ';
	cout << ans1[f] << endl;
	for (i = 1;i <= r - 1;i++)
		cout << ans2[i] << ' ';
	cout << ans2[r] << endl;
}
int main()
{
	init();
	sc1(1,f1);
	PRINT();
	return 0;
}