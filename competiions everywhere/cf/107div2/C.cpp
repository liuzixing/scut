#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;

__int64 q;
__int64 ans = 1;
int tot = 0;
int main(){
	scanf("%I64d",&q);

	for (__int64 i = 2;i * i <= q;i++){
		while ( q % i == 0){
			tot++;
			if (tot <= 2)
				ans *= i;
			q/=i;
		}
		if (tot > 2)
			break;
	}
	if (q > 1)
	{
		tot++;
		if (tot <= 2)
			ans*=q;
	}
    if (tot <= 1)
	{
		cout << "1\n0\n";
		return 0;
	}
	if (tot == 2)
		cout << "2" << endl;
	else{
		cout << "1\n" << ans << endl;
	}
}
