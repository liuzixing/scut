#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int x,y,z,num;
	
	while (cin >> num)
	{
		bool flag = true;
		for (x = 1;x <= 100 && flag;x++)
		{
			for (y = x ;y <= 100 && flag;y++)
			{
				for (z = y;z <= 100 && flag;z++)
				{	
					if (num == x * x + y * y + z * z)
					{
						printf("%d %d %d\n",x,y,z);
						flag = false;
					}
				}
			}
		}
	}

}