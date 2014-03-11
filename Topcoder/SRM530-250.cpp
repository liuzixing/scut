
#include <vector>
#include <cstdio>
using namespace std;
class GogoXBallsAndBinsEasy{
public:
	int solve(vector <int>T){
		int n = T.size(),ans = 0;
		for (int i = 0;i < n / 2;i++)
			ans += T[n - i - 1] - T[i];
		return ans;
	}
};
int main(){
	vector<int> T;
	T.clear();
	int a;
	for (int i = 0;i < 4;i++)
	{
		scanf("%d",&a);
		T.push_back(a);
	}
	GogoXBallsAndBinsEasy b;
	printf("%d\n",b.solve(T));
}