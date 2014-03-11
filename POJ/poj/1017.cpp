#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int ans,a[6];
	scanf("%d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
	while (a[0]+a[1]+a[2]+a[3]+a[4]+a[5])
	{
		int one = 0,two = 0;
		ans = a[5] + a[4] + a[3] + a[2] / 4;
		one +=a[4] * 11;
		two +=a[3] * 5;
		switch(a[2] % 4)
		{
		case 0:break;
		case 1:one += 7;two += 5;ans++;break;
		case 2:one += 6;two += 3;ans++;break;
		case 3:one += 5;two += 1;ans++;break;
		}
		if (a[1] < two)
		{
			one += (two - a[1]) * 4;
		}
		a[1] = (a[1] - two > 0) ? a[1] - two:0;
		ans += a[1] / 9;
		if (a[1] % 9)
		{
			one += (36 - a[1] % 9 * 4);
			ans++;
		}
		a[0] = (a[0] -one > 0) ? a[0]-one:0;
		ans += (a[0] + 35) / 36;
		cout << ans << endl;
		scanf("%d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
	}
}