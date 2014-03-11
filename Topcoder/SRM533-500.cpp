#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class CasketOfStarEasy{
public:
	int ret;
	int maxEnergy(vector <int> weight){
		ret = 0;
		dfs(weight,0);
		return ret;
	}
	void dfs(vector<int> w,int sum){
		if (w.size() == 2){
			if (sum > ret)
				ret = sum;
		}
		vector <int> s = w;
		for (int i = 1;i < w.size() - 1;i++){
			for (int j = i;j < w.size() - 1;j++)
				s[j] = s[j + 1];
			s.pop_back();
			dfs(s,sum + s[i] * s[i - 1]);
			s = w;
		}
	}
};