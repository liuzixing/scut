#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	int s,e,i,node,flag,sum,t,j;
	char str[110];
	while (gets(str))
	{
		for (i = 0;str[i] == ' ';i++);
		s = i;
		for (i = strlen(str) - 1;str[i] == ' ';i--);
		e = i;
		flag = 1;
		//长度15以内；头尾不为点。
		if (e - s + 1 > 15 || str[s] == '.' || str[e] == '.')
		{
			printf("NO\n");
			continue;
		}
		//点个数等于3；且不含其他符号
		node = 0;
		for (i = s;i <= e;i++)
		{
			if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			{
				flag = 0;
				break;
			}
			if (str[i] == '.')
			{
				node++;
			}
		}
		if (node != 3)
		{
			printf("NO\n");
			continue;
		}
		//数不大于255
		i = s;
		
		while (i <= e && flag)
		{
			j = i;
			sum = 0;
			while (str[j] != '.' && e >= j)
			{
				j++;
			}
			for (int k = i;k < j;k++)
			{
				sum = sum * 10 + str[k] - '0';
			}
			//cout << sum << endl;
			if (sum > 255 || j - i > 3 || j == i)
			{
				flag = 0;
				break;
			}
			i = j + 1;
		}
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}