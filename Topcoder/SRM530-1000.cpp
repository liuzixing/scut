#include <iostream>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

class GogoXReimuHakurai{
public:
	int solve(vector <string> choices){
		int a[55][55],n = choices.size();
		memset(a,0,sizeof a);
		for (int i = 1;i < n;i++)
			for (int j = 0;j < n;j++)
				a[i][j] = choices[i][j] == 'Y';
		a[0][0] = a[n - 1][n  - 1] = 1;
		for (int k = 0;k < n;k++)
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
					a[i][j] |= (a[i][k] & a[k][j]);
		if (!a[0][n - 1]) return 0;
		int e = 0,v = 0;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				e += (choices[i][j] == 'Y' && a[0][i] && a[j][n - 1]);
		for (int i = 0;i < n;i++)
			v += (a[0][i] && a[i][n - 1]);
		return e - v + 2;
	}
};