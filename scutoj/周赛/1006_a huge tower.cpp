#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[700010];
int l,r,m,n,d,i,w;
long long ans;

int main(){
	while (~scanf("%d%d",&n,&d)){
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		sort(a + 1,a + 1 + n);
		ans = 1;
		for (int i = 2;i <= n;i++){
			l = 1;
			r = i - 1;
			w = a[i] - d;
			while (l <= r)
			{
				m = (l + r) >> 1;
				if (a[m] >= w)r = m - 1;
				else
					l = m + 1;
			}
			w = i - l;
			ans = (ans + ans * w)%1000000009;
		}
		printf("%d\n",ans);
	}
}