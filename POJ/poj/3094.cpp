#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c[1000];
	int i;
	while (gets(c))
	{
		if (!strcmp(c,"#"))
		{
			break;
		}
		int ans = 0;
		int len = strlen(c);
		for (i = 0;i < len;i++)
		{
			if (c[i] <= 'Z' && c[i] >= 'A')
			{
				ans += (c[i] - 'A' + 1) * (i + 1);
			}
		}
		printf("%d\n",ans);
	}
}