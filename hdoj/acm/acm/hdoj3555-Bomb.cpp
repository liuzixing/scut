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
		//�������49,����ǰ���������0-9 ����Ҫ��ȥdp[i-1][1] ��Ϊ4���9����49
		dp[i][1] = dp[i - 1][0];
		// ���ֱ���ڲ���49���������9������
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
		// include 49  �Ѿ�����49����������0-9������9��ͷ����4
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
			//ͳ�Ƶ�ĳһλ��ʱ�򣬼��� dp[i-1][2] * digit[i] ����Ȼ�Ե�,
			//��Ϊ��һλ������ 0 - (digit[i]-1)
			ans += dp[i - 1][2] * digit[i];
			//����һλ֮ǰ����49����ô���� dp[i-1][0] * digit[i]��
			if (flag)
				ans += dp[i - 1][0] * digit[i];
			//����һλ֮ǰû�а���49������digit[i]��4��
			//��ô����һλ��4��ʱ�򣬾͵ü���dp[i-1][1]
			if (!flag && digit[i] > 4)
				ans += dp[i - 1][1];
			if (digit[i + 1] == 4 && digit[i] == 9)
				flag = true;
		}
		cout << ans << endl;
	}
}