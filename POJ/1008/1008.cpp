#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int main()
{
	int n, i ,j, year, totaldays, Tzolkinday, Tzolkinyear, day;
	char monthofHaab[19][20]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
	char Haabmonth[20];
	char Tzolkinmonth[20][20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac","ahau"};
	cin >> n;
	cout << n <<endl;
	for (i = 1; i <= n; i++)
	{
            totaldays = 0;
	    scanf("%d.%s%d",&day,Haabmonth,&year);
	    for (j = 0; j <= 18; j++)
	    {
		if (!strcmp(monthofHaab[j] , Haabmonth))
		   break;
	    } 
	    totaldays += year * 365 + j * 20 + day;
            Tzolkinyear = totaldays / 260 ;
	    Tzolkinday = totaldays % 13 + 1;
	    cout << Tzolkinday << " " << Tzolkinmonth[totaldays % 20] << " " << Tzolkinyear << endl;
	}
}