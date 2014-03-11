#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[26] = {0},b[26] = {0},i;
	char ch[101];
	cin >> ch;
	i = strlen(ch);
	while (i)
	{
		i--;
		a[ch[i]-'A'] ++; 
	}
	sort(a,a+26);	
	cin >> ch;
	i = strlen(ch);
	while (i)
	{
		i--;
		b[ch[i]-'A'] ++; 
	}
	sort(b,b+26);
	bool flag = true;
	for (i=0;i < 26;i++)
	{
		if (a[i] != b[i])
		{
			cout << "NO" << endl;
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "YES" << endl;
	}

}