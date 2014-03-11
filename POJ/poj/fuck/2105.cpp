#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
const int b[8] = {128,64,32,16,8,4,2,1};
using namespace std;

int main()
{
	int n,i,j;
	ifstream fin ("test.in");
	cin >> n;
	while (n)
	{
		char str1[40];
		int ans[4] = {0};
		n--;
		cin >> str1;
		for (i = 0;i < 4;i++)
		{
			for (j = i * 8;j < i * 8 + 8;j++)
			{
				ans[i] += b[j - i * 8] * (str1[j] - '0');
			}
		}
		printf("%d.%d.%d.%d\n",ans[0],ans[1],ans[2],ans[3]);
	}
	
}