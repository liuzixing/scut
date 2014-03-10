#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main(){
	int a,b,n;
	scanf("%d",&n);
	while (n--){
		cin >> a >> b;
		if (b > a || (a + b) % 2 == 1 ){
			printf("impossible\n");
			continue;
		}
		printf("%d %d\n",(a + b) / 2,(a - b) / 2);
	}
}