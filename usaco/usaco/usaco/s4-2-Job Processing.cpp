/*
ID: benbenq1
PROG: job
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

const int maxn = 1000;
const int maxm = 30;
int mina,minai,minb,minbi;
int n,m1,m2,i,j,a[maxm],b[maxm],da[maxm],db[maxm],fa[maxn],fb[maxn];
//da,db分别代表a,b的延时。。fa，fb就是加工完第i个零件后的时间。。
int main()
{
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	cin >> n >> m1 >> m2;
	for (i = 0;i < m1;i++)
		cin >> a[i];
	for (i = 0;i < m2;i++)
		cin >> b[i];
	for (i = 0;i < n;i++)
	{
		mina = da[0] + a[0];
		minai = 0;
		minb = db[0] + b[0];
		minbi = 0;
		for (j = 1;j < m1;j++)
			if (mina > da[j] + a[j])
			{
				mina = da[j] + a[j];
				minai = j;
			}
		for (j = 1;j < m2;j++)
			if (minb > db[j] + b[j])
			{
				minb = db[j] + b[j];
				minbi = j;
			}
		da[minai] = mina;
		fa[i] = mina;
		db[minbi] = minb;
		fb[i] = minb;
	}
	cout << mina << ' ';
	mina = fa[0] + fb[n - 1];
	for (i = 1;i < n;i++)
		if (mina < fa[i] + fb[n - i - 1])
			mina = fa[i] + fb[n - i - 1];
	cout << mina << endl;
}

