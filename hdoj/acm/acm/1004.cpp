#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int main()
{
	int n,i,j,total,num[1001];
	char ch[1001][20],ct[20],ansball[20];
	while (cin >> n)
	{
		if (!n) break;
		total = 0;
		memset(num,0,sizeof(num));
		int ans = 1;
		for (i = 0;i < n;i++)
		{
			bool flag = true;
			scanf("%s",&ct);
			for (j = 0;j < total;j++)
			{
				if (!strcmp(ct,ch[j]))
				{
					num[j]++;
					if (ans < num[j])
					{
						ans = num[j];
						strcpy(ansball,ct);
					}
					flag = false;
					break;
				}
			}
			if (flag)
			{
				num[total]++;
				strcpy(ch[total],ct);
				total++;
			}
		}
		if (total == 1)
		{
			strcpy(ansball,ch[0]);
		}
		printf("%s\n",ansball);
	}
}