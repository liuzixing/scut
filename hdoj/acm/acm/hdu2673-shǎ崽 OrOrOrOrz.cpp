#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
int a[10005],b[10005];
int main(){
	while (~scanf("%d",&n)){
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		sort(a,a + n);
		int l = 0,r = n - 1,fence = 0;
		while (fence < n){
			if (r > 0){
				b[fence++] = a[r];
				r--;
				r = -r;
			}else{
				b[fence++] = a[l];
				l++;
				r = -r;
			}
		}
		for (int i = 0;i < n - 1;i++)
			printf("%d ",b[i]);
		printf("%d\n",b[n - 1]);
	}
}