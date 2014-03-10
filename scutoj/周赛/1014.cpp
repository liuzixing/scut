#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//dp存着达到这个状态alan需要的最小步数，而且向奇数贪心
int dp[10001],size0,size1;
int T;
vector<int> steps;
void gd(){
	dp[0] = 0;
	int ans,s = max(size0,size1);
	for (int i = 1;i <= s;i++){
		steps.clear();
		for (int j = 1;j * j <= i;j++)
			steps.push_back(1 + dp[i - j * j]);
		sort(steps.begin(),steps.end());
		for (int j = 0;j < steps.size();j++)
			if (steps[j] % 2 == 1){
				dp[i] = steps[j];
				break;
			}
			if (!dp[i]) dp[i] = steps.back();
	}
	ans = min(dp[size0],dp[size1]);
	if ( ans % 2 == 0)
		cout << "Bob will win after " << ans << " moves" << endl;
	else
		cout << "Alan will win after " << ans << " moves" << endl;


}
int main(){
	while (~scanf("%d%d",&size0,&size1)){
		gd();
	}
}