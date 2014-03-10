#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int n1,n2;
	int i,alevel,ar,al,blevel,bl,br,steps;
	while (cin >> n1 >> n2)
	{
		alevel = 1;
		blevel = 1;
		for (i = 1;;i += 2)
		{
			if (n1 - i <= 0)
			{
				ar = (i - n1) / 2 + 1;
				al = (n1 + 1) / 2;
				break;
			}
			alevel++;
			n1 -= i;
		}
		for (i = 1;;i += 2)
		{
			if (n2 - i <= 0)
			{
				br = (i - n2) / 2 + 1;
				bl = (n2 + 1) / 2;
				break;
			}
			blevel++;
			n2 -= i;
		}
		steps = abs(alevel - blevel) + abs(al - bl) + abs(ar - br);
		printf("%d\n",steps);
	}
}