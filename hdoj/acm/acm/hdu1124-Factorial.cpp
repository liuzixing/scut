#include <iostream>
#include <cstdio>
using namespace std;
 
int five,ans,t,n;
int main(){
	cin >> t;
	while (t--){
		cin >> n;
		ans = 0;
		five = 5;
		while (n / 5){
			ans += n / 5;
			n /= 5;
		}
		printf("%d\n",ans);
	}
}