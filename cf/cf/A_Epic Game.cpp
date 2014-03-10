#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a,int b){
	if (b == 0) return a;
	return (a % b ==0)?b:gcd(b,a % b);
}

int main(){
	int a,b,n;
	while (~scanf("%d%d%d",&a,&b,&n)){
		int k = 1;
		while (n >= 0){
			if (k % 2){
				n -= gcd(a,n);
				if (n < 0)
					printf("1\n");
			}
			else{
				n -= gcd(b,n);
				if (n < 0)
					printf("0\n");
			}
			k++;
		}
	}
}