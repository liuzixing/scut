/*
ID: benbenq1
PROG: fence9
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

int gcd(int a,int b)
{
	if (a % b == 0)
		return b;
	return gcd(b,a % b);
}
int main()
{
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	int s,n,m,p,b;
	cin >> n >> m>> p;
	s = m * p / 2;
	b += gcd(n,m);
	if (n != p)
		b += gcd(abs(n - p),m);
	else
		b += m;
	b += p;
	cout << s + 1 - (b / 2) << endl;
}