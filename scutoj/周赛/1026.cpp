#include <iostream> 
#include <stdio.h> 
#include <string.h> 
#include <algorithm> 

using namespace std; 

int main() 
{ 
	int d,h,m,ans; 
	while (cin >> d >> h >> m){ 
		ans = 0; 
		if (m - 11 >= 0) 
			ans += m - 11; 
		else
		{ 
			h -= 1;
			ans += m + 49; 
		} 
		if (h - 11 >= 0) 
		{ 
			ans += 60 * (h - 11); 
		}else{ 
			d -= 1;
			ans += (h + 13) *60; 
		} 
		if (d < 11) 
			ans = -1; 
		else
			ans += (d - 11) * 1440; 
		printf("%d\n",ans); 
	} 
	return 0; 
} 
