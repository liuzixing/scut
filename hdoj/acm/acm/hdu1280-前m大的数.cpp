#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m,k;
int b[10005];
int a[10005];
int main(){
	
	while (~scanf("%d%d",&n,&m)){
		memset(b,0,sizeof b);
		k = 10000;
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		for (int i = 0;i < n - 1;i++)
			for (int j = i + 1;j < n;j++){
				b[a[i] + a[j]]++;
				k = max(a[i] + a[j],k);
			}
		while(m > 1){
			while (b[k] == 0)
				k--;
			int i;
			for (i = b[k];i > 0 && m > 1;i--){
				m--;
				printf("%d ",k);
			}
			b[k] = i;
		}
		while (b[k] == 0)
			k--;
		printf("%d\n",k);
	}
}