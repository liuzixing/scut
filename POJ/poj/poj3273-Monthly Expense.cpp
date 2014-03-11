#include <cstdio>
#include <iostream>
using namespace std;

int n,m,mid,l,r;
int a[100001];
bool check(int x){
	int j = 0,sum = x,now = 0;
	while (j < n){
		if (sum < a[j]) return false;
		while (sum - a[j] >= 0 && j < n){
			sum -= a[j];
			j++;
		}
		if (j > 0)
			now++;
		if (now > m) return false;
		sum = x;
	}
	return true;
}
int main(){
	while (~scanf("%d%d",&n,&m)){
		l = 100000000,r = 0;
		for (int i = 0;i < n;i++){
			scanf("%d",&a[i]);
			r += a[i];
			if (l > a[i]) l = a[i];
		}

		while (l <= r){
			mid = (l + r) >> 1;
			if (check(mid))
				r = mid - 1;
			else l = mid + 1;

		}
		printf("%d\n",l);
	}
}