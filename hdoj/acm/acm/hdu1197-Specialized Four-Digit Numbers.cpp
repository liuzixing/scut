#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int check(int b,int x){
	int now = 0;
	while (x){
		now += x % b;
		x /= b;
	}
	return now;
}
int main(){
	for (int i = 2992;i < 10000;i++){
		int tem = check(10,i); 
		if (tem == check(16,i) && tem == check(12,i))
			printf("%d\n",i);
	}
}