#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

vector < pair<int,int> > ans;
vector<int> stack;

int main(){
	int n;
	cin >> n;
	vector<int> a(n + 2,0);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 0;i <= n;i++){
		for (int j = 0;j < a[i + 1] - a[i];j++)
			stack.push_back(i + 1);
		for (int j = 0;j < a[i] - a[i + 1];j++){
			ans.push_back(make_pair(stack.back(),i));
			stack.pop_back();
		}
	}
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i].first << " " << ans[i].second << endl;
}