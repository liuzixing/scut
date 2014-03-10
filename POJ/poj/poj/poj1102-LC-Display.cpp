#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

int b[10][5][3] ={0,1,0,2,0,2,0,0,0,2,0,2,0,1,0,
	              0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,
                  0,1,0,0,0,2,0,1,0,2,0,0,0,1,0,
                  0,1,0,0,0,2,0,1,0,0,0,2,0,1,0,
                  0,0,0,2,0,2,0,1,0,0,0,2,0,0,0,
                  0,1,0,2,0,0,0,1,0,0,0,2,0,1,0,
                  0,1,0,2,0,0,0,1,0,2,0,2,0,1,0,
				  0,1,0,0,0,2,0,0,0,0,0,2,0,0,0,
				  0,1,0,2,0,2,0,1,0,2,0,2,0,1,0,
				  0,1,0,2,0,2,0,1,0,0,0,2,0,1,0},s;
char change(int x)
{
	switch(x)
	{
	case 0:return ' ';
	case 1:return '-';
	case 2:return '|';
	default:return '0';
	}
}
void print(int n,int j)
{
	int i;
	printf("%c",change(b[n][j][0]));
	for (i = 1;i <= s;i++)
	{
		printf("%c",change(b[n][j][1]));
	}
	printf("%c",change(b[n][j][2]));
}
int main()
{
	int n,t,ans[20],i,k,j;
	while (cin >> s >> n && (n || s))
	{

		if (n == 0)
		{
			ans[0] = 1;
			ans[1] = 0;
		}
		else
		{
			ans[0] = 0;
			while(n)
			{
				ans[0]++;
				ans[ans[0]] = n % 10;
				n /= 10;
			}
		}
		
		for (j = 0;j < 5;j++)
		{
			if (j == 1 || j == 3)
			{
				t = s;
			}
			else 
			{
				t = 1;
			}
			for(k = 1;k <= t;k++)
			{
				for (i = ans[0];i > 1;i--)
				{
					print(ans[i],j);
					printf(" ");
				}
				print(ans[1],j);
				printf("\n");
			}
		}
		printf("\n");
	}
}