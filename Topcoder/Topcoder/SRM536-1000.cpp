#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

class MergersDivTwo{
public:
	int v[51],kk,ans;
	double findMaximum(vector <int> revenues, int k){
		sort(revenues.begin(),revenues.end());kk = k;
		memset(v,0,sizeof v);
		ans = -10000000;
		dfs(revenues,revenues.size(),0);
		return ans;
	}
	void dfs(vector <int> revenues,int rest,int sum){
		if (rest < kk){
			if (rest == 0 && sum > ans)
				ans = sum;
			return ;
		}
		int x[51],now = -1000000;
		
		for (int i = kk;i <= rest;i++){
			int y = 0;
			memset(x,0,sizeof x);
			vector<int > r;
			for (int j = 0;j < revenues.size();j++)
				r.push_back(revenues[j]);
			r.push_back(sum);
			sort(r.begin(),r.end());
			for (int j = 0;j < r.size();j++)
				if (!v[j]){
					x[j] = 1;
					y += r[j];
					v[j] = 1;
				}
			
			dfs(r,rest - i,sum + y);
			for (int j = 0;j < r.size();j++)
				v[j] = !(x[j] && v[j]);
		}
	}
};