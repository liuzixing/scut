#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
	double i,j,ans,d,second,minute,hour,k;
	while (cin >> d)
	{
		if (d < 0)
		{
			break;
		}
		ans = 0;
		second = 0;
		minute = 0;
		hour = 0;
		for (i = 0;i < 12;i++)
		{
			for (j = 0;j < 60;j++)
			{
				for (k = 0;k < 60;k += 0.1)
				{
					hour = 30 * i + j / 2 + k / 120; 
					second = 6 * k ;
					minute = 6 * j + k / 10;
					if ((fabs(second - minute) >= d) && (fabs(second - hour)  >= d) && (fabs(hour - minute ) >= d) &&
						(fabs(second - hour)  < 360.0 - d ) && (fabs(second - minute) < 360.0 - d) && (fabs(hour - minute ) <= 360.0 - d))
					{
						ans++;
					}
				}
			}
		}
		printf("%0.3lf\n",(ans / 4320));
	}

}