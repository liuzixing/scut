#include <iostream>
#include <string>
using namespace std;
int f[32][32];
//f[i][j]表示计一棵高度为i的完全二叉树内二进制表示中恰好含有j个1
//的数的个数
//找到n 的左起第一位非0、1 的数位，将它变为1，并将右面所有数位
//设为1。
int change(int x,int b)
{
	string s;
	do {
		s = char('0' + x % b) + s;
		x /= b;
	} while (x > 0);
	for (int i = 0;i < s.size();++i)
		if (s[i] > '1') {
			for (int j = i;j < s.size();++j) s[j] = '1';
			break;
		}
		x = 0;
		for (int i = 0;i < s.size();++i)
			x = x | ((s[s.size() - i - 1] - '0') << i);
		return x;
}
void init()
{
	f[0][0] = 1;
	for (int i = 1;i <= 31;i++)
	{
		f[i][0] = f[i - 1][0];
		for (int j = 1;j <= i;j++)
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
	}
}
int calc(int x,int k)//统计[0..x]内二进制表示含k个1的数的个数
{
	int ones = 0,ans = 0;//ones记录当前路径上已有的1的数量，ans表示答案
	for (int i = 31;i > 0;i--)
	{
		if (x & (1 << i))
		{
			ones++;
			if (ones > k) break;
			x = x ^ (1 << i);
		}
		if ((1 << (i - 1) <= x))
			ans += f[i - 1][k - ones];
	}
	if (ones + x == k) ans++;
	return ans;
}

int main()
{
	int x,y,k,b;
	cin >> x >> y >> k >> b;
	x = change(x,b);y = change(y,b);
	init();
	cout << calc(y,k) - calc(x - 1,k) << endl;
	return 0;
}