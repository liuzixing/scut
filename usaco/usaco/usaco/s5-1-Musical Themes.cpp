/*
ID: benbenq1
PROG: theme
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
#include <memory>
#include <cstdio>
#include <cctype>
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

FILE *fin = fopen("theme.in","r");
FILE *fout = fopen("theme.out","w");

const int N = 5001;
int a[N];
int n,ans;
int main()
{
	fscanf(fin,"%d",&n);
	for (int i = 0;i < n;i++)
		fscanf(fin,"%d",&a[i]);
	for (int i = 5; i < n;i++)
	{
		int len = 0,dis = 89;
		for (int j = 0; j + i <=n;j++)
			if (a[j] - a[j + i] == dis)
			{
				if (len == i)
					break;
				len++;
				if (len >= 5)
					ans = max(ans,len);
			}
			else
			{
				len = 1;
				dis = a[j] - a[i + j];
			}
	}
	fprintf(fout,"%d\n",ans);
	fclose(fin);
	fclose(fout);
}