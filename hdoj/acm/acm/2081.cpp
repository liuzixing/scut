#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char c[15];
	int n,i;
	cin >> n;
	while (n--)
	{
		cin >> c;
		printf("6");
		for (i = 6;i < 11;i++)
		{
			printf("%c",c[i]);
		}
		cout << endl;
	}
}