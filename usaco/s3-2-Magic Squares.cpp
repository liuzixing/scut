/*
ID: benbenq1
PROG: msquare
LANG: C++
*/
#include <functional>
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
const int hash_num = 170537;
const int op[3][8] = {{4,5,6,7,0,1,2,3},{3,0,1,2,7,4,5,6},{0,5,1,3,4,6,2,7}};
struct node
{
	int last,deep,oprator,x;
}q[100000];
bool used[hash_num];
int _hash(int a)
{
	return a % hash_num;
}
int main()
{
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	int i,j,now[8],l = 1,r = 2,goal = 0;
	for (i = 0;i <= 3;i++)
		cin >> now[i];
	for (i = 7;i > 3;i--)
		cin >> now[i];
	for (i = 0;i < 8;i++)
		goal = goal * 10 + now[i];
	q[1].deep = 0;
	q[1].oprator = -1;
	q[1].x = 12348765;
	used[_hash(12348765)] = 1;
	q[1].last = 0;
	if (q[1].x == goal)
	{
		cout << 0 << endl;
		cout <<endl;
		return 0;
	}
	while (l < r)
	{
		int tem[8],x = q[l].x;
		for (int i = 7;i >= 0;i--)
		{
			tem[i] = x % 10;
			x /= 10;
		}
		for (i = 0;i < 3;i++)
		{
			int nn[8];
			for (j = 0;j < 8;j++)
				nn[j] = tem[op[i][j]];
			x = 0;
			for (j = 0;j < 8;j++)
				x = x * 10 + nn[j];
			if (!used[_hash(x)])
			{
				q[r].deep = q[l].deep + 1;
				q[r].x = x;
				q[r].last = l;
				q[r].oprator = i;
				used[_hash(x)] = true;
				if (x == goal)
					break;
				r++;
			}
		}
		l ++;
		if (x == goal)
			break;
	}
	cout << q[r].deep << endl;
	int len = 0,ans[60];
	while (q[r].oprator >= 0)
	{
		len++;
		ans[len] = q[r].oprator;
		r = q[r].last;
	}
	for (i = len;i >= 1;i--)
		cout << (char)('A' + ans[i]);
	cout << endl;
}