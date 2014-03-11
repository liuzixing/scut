#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <string.h>
#include <stack>

using namespace std;

int m = -1,n = 100000,k,ans,a;
int main(){
	scanf("%d",&k);
	for (int i = 0;i < k;i++){
		scanf("%d",&a);
		if (m < a){
			m = a;
			if (i != 0)
				ans++;
		}
		if (n > a){
			n = a;
			if (i != 0)
				ans++;
		}
	}
	printf("%d\n",ans);
}