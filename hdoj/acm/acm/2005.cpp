#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
void init (int &year,int & month,int & day,char s[20])
{
	    int len,i;
	    len = strlen(s);
		i = 0;
		year = 0;
		month = 0;
		day = 0;
		while (i < len && s[i] != '/')
		{
			year = year * 10 + s[i] - '0';
			i++;
		}
		i++;
		while (i < len && s[i] != '/')
		{
			month = month * 10 + s[i] - '0';
			i++;
		}
		i++;
		while (i < len && s[i] != '/')
		{
			day = day * 10 + s[i] - '0';
			i++;
		}
}
int main()
{
	int year,month,day,ans,len,i;
	char s[20];
	while (cin >> s)
	{
		init(year,month,day,s);
		ans = day;
		for (i = 1; i < month;i++)
		{
			switch(i)
		    {
		    case 1:
		    case 3:
	    	case 5:
		    case 7:
	    	case 8:
	    	case 10:ans +=31;break;
	    	case 4:
		    case 6:
		    case 9:
		    case 11:ans +=30;break;
			case 2: if (year % 400 == 0 || (year % 100 != 0 && year % 4 ==0))
					{
						ans +=29;break;
					}
					else
					{
						ans +=28;break;
					}
		    }
			
		}
        printf("%d\n",ans);
	}
	
}