#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	int dpoff[105],dpon[105];
	char data[105];
	int i,t,len;
	cin >> t;
	getchar();
	while (t--)
	{
		gets(data);
		len = strlen(data);
		if (islower(data[0]))
		{
			dpoff[0] = 1;dpon[0] = 2;
		}
		else
		{
			dpoff[0] = 2;dpon[0] =2;
		}
		for (i = 1;i < len;i++)
		{
			if (islower(data[i]))
			{
				dpoff[i] = min(dpoff[i - 1] + 1,dpon[i - 1] + 2);
				dpon[i] = min(dpoff[i - 1] + 2,dpon[i - 1] + 2);
			}
			else
			{
				dpoff[i] = min(dpon[i - 1] + 2,dpoff[i - 1] + 2);
				dpon[i] = min(dpon[i - 1] + 1,dpoff[i - 1] + 2);
			}
		}
		cout << min(dpoff[len -1],dpon[len - 1] + 1)<< endl;
	}
}