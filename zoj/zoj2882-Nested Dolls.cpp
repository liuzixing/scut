#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
	int w,h;
}a[20005];
int t,n;
int b[20005];
bool cmp(node x,node y){
	if (x.w == y.w)
		return x.h > y.h;
	return x.w < y.w;
}
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
			scanf("%d%d",&a[i].w,&a[i].h);
		sort(a, a + n,cmp);
		b[1] = a[0].h;
		int l,r,mid,len = 1;
		for (int i = 1;i < n;i++){
			l = 1;r = len;
			while (l <= r){
				mid = (l + r) >> 1;
				if (a[i].h <= b[mid])
					l = mid + 1;
				else r = mid - 1;
			}
			b[l] = a[i].h;
			if (l > len)
				len++;
		}
		printf("%d\n",len);
	}
}