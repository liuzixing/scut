/*���⣺��P(n,m)ĩβ����λ�����֡�
�������������2��5�ĸ�����
�����´��룺
int get(int n,int x) { if(n==0)return 0; return n/x+get(n/x,x); }
����˵50��
5������50/5+50/25=12����2Ҳ��һ����
��ȥ����2��5��Ӱ��ĩλ������ֻ����3��7��9��
����Ҫͳ�Ƹ�λΪ3��7��9�ĸ��������磺3��13��223��37��29��������λΪ3��7��9�Ķ�Ҫ�����ڡ�
�ֱ����ͳ�ƣ����Է��֣�2��4��6��8��10�еĸ���Ҳ����1 2 3 4 5�еĸ�����Ҳ����˵�����ְ�������⻮�ֳ���һ��ԭ������������⡣ 
f(n) = f(n/2) + g(n),g(n)��ʾ�������е���Ŀ������������Ҫ���g(n)�ٴι۲�g(n)

ʵ�����ֳַ���������1 3 7 9 11 13 17 19 21�������Լ�5���汶��5��15��25������˵���ֳ�����������,���Ҫͳ�����������ĩβΪx��1��3��7��9���ĸ�����������д��g(n,x) = n/10+(n >= x)+g(n/5,x) 

int g(int n,int x) { if(n==0)return 0; return n/10+(n%10>=x)+g(n/5,x); }  
int getx(int n,int x) { if(n==0)return 0; return g(n,x)+getx(n/2,x); }
��󽫸���������У���Ҫע����ǣ���Щ����ÿ��4�θ�λ��һ��ѭ����
���磺3�Ĵη��� �� 1  2  3   4   5   6�õ��ĸ�λ����3  9  7   1   3   9
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