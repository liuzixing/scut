#include <cstdio>
using namespace std;

int n,s,t;
int sum[100005];
bool check(int x){
	int max = -1;
	for (int i = x;i <= n;i++)
		if (max < sum[i] - sum[i - x])
			max = sum[i] - sum[i - x];
	if (max >= s)
		return true;
	else return false;
}
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&s);
		for (int i = 1;i <= n;i++){
			scanf("%d",&sum[i]);
			sum[i] += sum[i - 1];
		}
		int l = 1,r = n;
		while (l <= r){
			int mid = (l + r) >> 1;
			if (check(mid))
				r = mid - 1;
			else l = mid + 1;
		}
		if (check(l)) printf("%d\n",l);
		else printf("0\n");
	}
}