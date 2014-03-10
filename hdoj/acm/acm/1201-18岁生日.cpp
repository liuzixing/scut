#include <iostream>
#include <cstdio>
using namespace std;

bool check(int i){
	if ((i % 100 != 0 && i % 4 == 0) || (i % 400 == 0))
		return true;
	return false;
}
int month(int y,int x){
	if (x  == 1|| x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
		return 31;
	if (x == 2){
		if (check(y))
			return 29;
		else
			 return 28;
	}
	return 30;
}
int main(){
	int t,y,m,d;
	cin >> t;
	while (t--){
		int ans = 0;
		scanf("%d-%d-%d",&y,&m,&d);
		int y2 = y + 18;
		if (m == 2 && d == 29){
			printf("-1\n");
			continue;
		}
		for (int i = y + 1 ;i < y + 18;i++){
			if (check(i))
				ans += 366;
			else ans += 365;
		}
		if (m < 3)
			ans += 365 + check(y);
		else 
			ans += 365 + check(y2);
		printf("%d\n",ans);
	}
}