#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	char a[51],ta;
	int i,t;
	cin >> t;
	while (t--)
	{
		scanf("%s",&a);
		int len = strlen(a);
		for (i = 0;i < len;i += 2)
		{
			ta = a[i];
			a[i] = a[i + 1];
			a[i + 1] = ta;
		}
		puts(a);
	}
}