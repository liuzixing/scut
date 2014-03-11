#include <cstdio>
#include <algorithm>
using namespace std;

int a[100001],b;
int n,m;
int bs(){
	int l = 0,r = n - 1,mid;
	if (a[n - 1] <= b || a[0] > b) return -1;
	while (l < r - 1){
		mid = (l + r) >> 1;
		if (a[mid] > b)
			r = mid;
		else l = mid;
	}
	return l;
}
int main(){
	while (~scanf("%d%d",&n,&m)){
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		sort(a,a + n);
		while (m--){
			scanf("%d",&b);
			int tem = bs();
			if (tem < 0)
				printf("no such interval\n");
			else printf("[%d,%d)\n",a[tem],a[tem + 1]);
		}
		puts("");
	}
}