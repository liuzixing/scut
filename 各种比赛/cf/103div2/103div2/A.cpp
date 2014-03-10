#include <iostream>
#include <cstdio>
using namespace std;

int n,a[1001];
int main(){
	while (~scanf("%d",&n)){
		int l = 1000,r = 0,li,ri;
		for (int i = 0;i < n;i++){
			scanf("%d",&a[i]);
			if (l >= a[i]) 
			{
				l = a[i];
				li = i;
			}
			if (r < a[i]){
				r = a[i];
				ri = i;
			}
		}
		if (l < r){
			if (li < ri)
				printf("%d\n",ri + n - li - 2);
			else
				printf("%d\n",ri + n - li - 1);
		}
		else
			printf("0\n");
	}
}