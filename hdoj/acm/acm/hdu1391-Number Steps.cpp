#include <cstdio>
#include <iostream>
using namespace std;
int t,n,m;
int main(){
	cin >> t;
	while (t--){
		cin >> n >> m;
		if (abs(n - m) > 2){
			printf("No Number\n");
			continue;
		}
		if (n % 2 && m  % 2)
			cout << n + m - 1<< endl;
		else if (n % 2  == 0 && m  % 2 == 0)
			cout << m + n<< endl;
		else
			printf("No Number\n");
	}
}