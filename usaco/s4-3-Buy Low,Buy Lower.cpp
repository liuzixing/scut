/*
ID: benbenq1
PROG: buylow
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
ofstream fout ("buylow.out",ios::out);
ifstream fin ("buylow.in",ios::in);
const int MAX = 5010;
struct elect
{
	int ele[MAX],len;
	int MAXN(){return ele[len];}
	int refresh (int VAL){ele[++len] = VAL;return len;}
	int change(int VAL)
	{
		int l = 1,r = len,mid = (l + r) >> 1;
		while (l < r)
			if (VAL > ele[mid])
			{
				l = mid + 1;mid = (l + r) >> 1;
			}
			else
			{
				r = mid;mid = (l + r) >> 1;
			}
		ele[l] = VAL;
		return l;
	}
}num;
class Plus
{
	int num[80],len;
public:
	Plus()
	{
		memset(num,0,sizeof(num));
		len = 0;
	}
	void refresh(){num[++len] = 1;}
	friend Plus operator + (const Plus &A,const Plus &B)
	{
		Plus C;
		int LEN = max(A.len,B.len);
		for (int i = 1;i <= LEN;i++)
		{
			C.num[i] += A.num[i] + B.num[i];
			C.num[i + 1] += (C.num[i]) / 10;
			C.num[i] %= 10;
		}
		if (C.num[LEN + 1] != 0) C.len = ++LEN;
		else C.len = LEN;
		return C;
	}
	void operator = (const Plus & A)
	{
		for (int i = 1;i <= A.len;i++) num[i] = A.num[i];
		len = A.len;
	}
	void print()
	{
		for (int i = len;i >= 1;i--)
			fout << num[i];
		fout << endl;
	}
}sum[MAX];
int val[MAX][2],n;
bool Find[MAX],flag;
Plus ans;
int main()
{
	int i,j;
	fin >> n;
	for (i = 1;i <= n;i++)
		fin >> val[i][0];
	for (i = n;i >= 1;i--)
		if (val[i][0] > num.MAXN()) val[i][1] = num.refresh(val[i][0]);
		else 
		{
			if (val[i][0] < num.MAXN())
				val[i][1] = num.change(val[i][0]);
			else
				val[i][1] = num.len;
		}
	for (i = n;i >= 1;i--)
	{
		flag = false;
		for (j = n;j >= i + 1;j--)
		{
			if (!Find[j] && val[i][0] > val[j][0] && val[i][1] == val[j][1] + 1)
			{
				sum[i] = sum[i] + sum[j];
				flag = true;
			}
			else if (val[i][0] == val[j][0]) Find[j] = true;
		}
		if (!flag)sum[i].refresh();
	}
	for (i = n;i >= 1;i--)
		if (!Find[i] && val[i][1] == num.len)
			ans = ans + sum[i];
	fout << num.len << ' ';
	ans.print();
	return 0;
}