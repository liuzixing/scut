#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
	int i;
	double ans,d,second,minute,hour;
	while (cin >> d)
	{
		if (d < 0)
		{
			break;
		}
		ans = 0;
		d = d * 120;
		second = 0;
		minute = 0;
		hour = 0;
		for (i = 1;i <= 43200;i++)
		{
			second = (second + 720 >= 43200) ? second + 720 - 43200: second + 720;
			minute = (minute + 12 >= 43200) ? minute + 12 -43200 : minute + 12;
			hour =  i;
			if (fabs(second - minute) >= d && fabs(second - hour)  >= d && fabs(hour - minute ) >= d && 
				fabs(second - minute) <= 43200.0000 - d && fabs(second - hour)  <= 43200.0000 - d && fabs(hour - minute ) <= 43200.0000 - d)
			{
				ans++;
			}
		}
		printf("%0.3lf\n",ans / 432);
	}

}