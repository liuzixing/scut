#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

class BinaryPolynomialDivTwo{
public:
	int countRoots(vector <int> a){
		int c = 0,ans = 0;
		if (!a[0])
			ans = 1;
		for (int i = 0;i < a.size();i++)
			c += a[i];
		if (c % 2 == 0)
			ans++;
		return ans;
	}
};