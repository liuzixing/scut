#include<iostream>
using namespace std;

int main()
{
	int t, n, p[21], i, j, k, len, s[10000];
	cin >> t;
	while (cin >> n)
	{
		p[0] = 0;
		len = 0;
		//输入数据，并转化为s序列。
		for (i = 1;i <= n; i++)
		{
			cin >> p[i];
			j = p[i] - p[i - 1];
			for  (k = 0;k < j; k++)
			{
				len++;
				s[len] = 0;
			}
			len++;
			s[len] = 1;
		}
		i = 1;
		while (i <= len)
		{
			if (s[i] == 1)
			{
				k = i;
				j = 0;
				while (s[k] != 0 && k > 0)
				{
					if (s[k] == 1)
						j++;
					k--;
				}
				s[k] = 3;
				cout << j << " ";
			}
			
			i++;
		}
		cout << endl;
	}
}