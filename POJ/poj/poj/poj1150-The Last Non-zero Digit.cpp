/*题意：求P(n,m)末尾非零位的数字。
首先现求出因子2和5的个数。
有如下代码：
int get(int n,int x) { if(n==0)return 0; return n/x+get(n/x,x); }
比如说50！
5个数是50/5+50/25=12个，2也是一样。
除去因子2，5。影响末位非零数只能是3，7，9。
所以要统计个位为3，7，9的个数，例如：3，13，223，37，29。这样个位为3，7，9的都要算在内。
分别进行统计，可以发现，2，4，6，8，10中的个数也就是1 2 3 4 5中的个数，也就是说我们又把这个问题划分成了一个原来问题的子问题。 
f(n) = f(n/2) + g(n),g(n)表示奇数列中的数目，所以我们需要解决g(n)再次观察g(n)

实际上又分成了两部分1 3 7 9 11 13 17 19 21。。。以及5的奇倍数5，15，25。。。说明又出现了子问题,如果要统计这个数列中末尾为x（1，3，7，9）的个数可以这样写：g(n,x) = n/10+(n >= x)+g(n/5,x) 

int g(int n,int x) { if(n==0)return 0; return n/10+(n%10>=x)+g(n/5,x); }  
int getx(int n,int x) { if(n==0)return 0; return g(n,x)+getx(n/2,x); }
最后将各个因子相承；但要注意的是：这些数字每成4次个位数一次循环。
例如：3的次方数 ： 1  2  3   4   5   6得到的个位数：3  9  7   1   3   9
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int get (int n,int x)
{
	if (n == 0) return 0;
	return n / x + get(n /x, x);
}
int g(int n,int x)
{
	if (n == 0) return 0;
	return n / 10 + (n % 10 >= x) + g(n / 5,x);
}
int getx(int n,int x)
{
	if (n == 0) return 0;
	return g(n,x) + getx(n / 2,x);
}
int getnum(int x,int n)
{
	int i;
	if (n == 0) return 1;
	n = (n - 1) % 4;
	int ans = 1;
	for (i = 0;i <= n;i++)
		ans = ans * x % 10;
	return ans;
}
int main()
{
	int n,m,a2,a3,a5,a7,a9,ans;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		a2 = get(n ,2) - get(n - m,2);
		a5 = get(n ,5) - get(n - m ,5);
		a3 = getx(n ,3) - getx(n - m,3);
		a7 = getx(n ,7) - getx(n - m,7);
		a9 = getx(n ,9) - getx(n - m,9);
		if (a2 < a5)
		{
			printf("5\n");
			continue;
		}
		a2 = a2 - a5;
		ans = getnum(2,a2) * getnum(3,a3) * getnum(7,a7) * getnum(9,a9) % 10;
		printf("%d\n",ans);
	}
}