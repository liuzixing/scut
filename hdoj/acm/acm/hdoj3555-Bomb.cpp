#include <iostream>
#include <cstdio>

using namespace std;

int t,len;
unsigned long long n,dp[20][3],ans;
bool flag;
int digit[20];
int main()
{
	int i;
	scanf("%d",&t);
	dp[0][0] = 1;
	for (i = 1;i < 20;i++)
	{
		dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];
		//如果不含49,且在前面可以填上0-9 但是要减去dp[i-1][1] 因为4会和9构成49
		dp[i][1] = dp[i - 1][0];
		// 这个直接在不含49的数上填个9就行了
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
		// include 49  已经含有49的数可以填0-9，或者9开头的填4
	}
	while (t--)
	{
		cin >> n;
		memset(digit,0,sizeof(digit));
		len = flag = ans = 0;
		n++;
		while (n)
		{
			digit[++len] = n % 10;
			n /= 10;
		}
		digit[len + 1] = 0;
		for (i = len;i > 0;i--)
		{
			//统计到某一位的时候，加上 dp[i-1][2] * digit[i] 是显然对的,
			//因为这一位可以填 0 - (digit[i]-1)
			ans += dp[i - 1][2] * digit[i];
			//若这一位之前挨着49，那么加上 dp[i-1][0] * digit[i]。
			if (flag)
				ans += dp[i - 1][0] * digit[i];
			//若这一位之前没有挨着49，但是digit[i]比4大，
			//那么当这一位填4的时候，就得加上dp[i-1][1]
			if (!flag && digit[i] > 4)
				ans += dp[i - 1][1];
			if (digit[i + 1] == 4 && digit[i] == 9)
				flag = true;
		}
		cout << ans << endl;
	}
}