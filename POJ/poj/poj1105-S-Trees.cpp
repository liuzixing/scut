#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

char tn[200],parameters[20],values[3];
int n,m,p,t;
int order[20];

int main()
{
	t = 1;
	while (cin >> n && n)
	{
		printf("S-Tree #%d:\n",t);
		t++;
		for (int i = 0;i < n;i++)
		{
			cin >> values;
			order[values[1] - '1'] = n - 1 - i;
		}
		cin >> tn;
		cin >> m;
		for (int i = 0;i < m;i++)
		{
			cin >> parameters;
			p = 0;
			for (int j = 0;j < n;j++)
			{
				if (parameters[j] == '1')
					p += (1 << order[j]);
			}
			cout << tn[p];
		}
		cout << endl << endl;
	}
}