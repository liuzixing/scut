#include <iostream>
#include <cstdio>
using namespace std;
int s,S,sum1,n,sum2;
int u,d;
int main(){
	while (~scanf("%d",&n)){
		sum1 = n * (n + 1) / 2;
		sum2 = n * (n - 1) / 2;
		s = sum2 * sum2;
		S = sum1 * sum1;
		u = (s + S) * 2 - n * n * n * n;
		d = 4;
		if (u % 2 == 0){
		    d = 2;
			u /= 2;
		}
		if (u % 2 == 0){
		    d = 1;
			u /= 2;
		}
		if (u == 0)
			d = 0;
		printf("%d/%d\n",u,d);
	}
}
