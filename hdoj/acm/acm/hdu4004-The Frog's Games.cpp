#include <cstdio>
#include <algorithm>
using namespace std;

int L,m,n,l = 1,mid,r;
int a[500002];
bool check(int x){
	int step = 0,now = 0,last = 0;;
	while (now < n){
		while  (a[now] - last <= x && now <= n)
			now++;
		now--;
		if (a[now] - last == 0)
			return false;
		step++;
		last = a[now];
		if (step > m)
			return false;
	}
	return true;
}
int main(){
	while (~scanf("%d%d%d",&L,&n,&m)){
		r = L+1;l = 1;
		if (n == 0){
			printf("%d\n",L);
			continue;
		}
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		sort(a,a + n);
		a[n] = L;
		while (l <= r){
			mid = (l + r) / 2;
			if (check(mid))
				r = mid - 1;
			else l = mid + 1;
		}

		printf("%d\n",l);
	}
	
}