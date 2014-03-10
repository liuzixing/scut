#include<iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	int t,i,j,len;
	char a[100];
	while( scanf("%d%*c",&t) !=EOF )
	{
		int sum = 0;
		while( t-- )
		{
			int n = 10;
			int s = 0;
			gets(a);
			len = strlen(a);
			i = 0;
			while (a[i] != '(')
			{
				i++;
			}
			s = 1;
			if (a[len - 3] == '(')
			{
				n = a[len - 2] - '0';
			}
			for (j = i - 1;j >= 0;j--)
			{
				sum += (a[j] - '0') * s;
				s *= n;
			}
		}
		cout << sum << endl;
	}
}