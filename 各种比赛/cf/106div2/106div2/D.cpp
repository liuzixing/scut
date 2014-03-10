#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

int rb[701],f[701][701][3][3];
#define mod 1000000007
vector <int> b;
string s;
int dp(int l,int r,int cl,int cr){
	if (l > r) return 1;
	if (f[l][r][cl][cr] > 0) return f[l][r][cl][cr];
	int &ret = f[l][r][cl][cr];
	for (int i = 1;i < 3;i++){
		//两种情况，对于2种颜色，要么放在括号左边，要么在在右边。
		if (rb[l] < r || i != cr)
			ret = (ret + (long long )dp(l + 1,rb[l] - 1,0,i) * dp(rb[l] + 1,r,i,cr)) % mod;
		if  (i != cl)
			ret = (ret + (long long )dp(l + 1,rb[l] - 1,i,0) * dp(rb[l] + 1,r,0,cr)) % mod;
	}
	return ret;
}
int main(){
	cin >> s;
	for (int i = 0;i < s.size();i++){
		if (s[i] == '(') b.push_back(i);
		else rb[b.back()] = i,b.pop_back();
	}
	printf("%d\n",dp(0,s.size() - 1,0,0));
	return 0;
}