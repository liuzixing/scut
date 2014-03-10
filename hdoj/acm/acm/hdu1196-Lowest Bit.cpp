#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int a,b;
	while (~scanf("%d",&a)){
		b = 1;
		while (b <= a){
			if (b & a){
				printf("%d\n",b);
				break;
			}
			b <<= 1;
		}
	}
}