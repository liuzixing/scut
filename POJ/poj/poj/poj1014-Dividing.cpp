#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

bool f[60001];
int a[60000];
int marble[6],cases;
bool flag;
int b[20];
int main()
{
	int i,j,n,sum;
	b[0] = 1;
	for (i = 1;i < 15;i++)
		b[i] = b[i - 1] * 2;
	while (cin >> marble[0] >> marble[1] >> marble[2] >> marble[3] >> marble[4] >> marble[5])
	{
		n = sum = 0;
		for (i = 0;i < 6;i++)
		{
			sum += marble[i] * (i + 1);
		}
		if (flag)
			printf("\n");
		flag = 1;
		memset(f,0,sizeof(f));
		if (!sum)
			break;

		if (sum % 2)
			printf("Collection #%d:\nCan't be divided.\n",++cases);
		else
		{
			for (i = 0;i < 6;i++)
			{
				j = 0;
				while(marble[i] - b[j] >= 0)
				{
					a[++n] = b[j] * (i + 1);
					marble[i] -= b[j];
					j++;
				}
				if (marble[i])
					a[++n] = marble[i] * (i + 1);
			}

			f[0] = 1;
			for (i = 1;i <= n && !f[sum / 2];i++)
			{
				for (j = sum / 2;j >= a[i] && !f[sum / 2];j--)
				{
					if (f[j - a[i]])
						f[j] = 1;
				}
			}
			if (!f[sum / 2])
				printf("Collection #%d:\nCan't be divided.\n",++cases);
			else
				printf("Collection #%d:\nCan be divided.\n",++cases);
		}

	}
}