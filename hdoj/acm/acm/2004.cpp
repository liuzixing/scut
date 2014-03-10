#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
	int x;
	while (cin >> x)
	{
		if (x > 100 || x < 0)
		{
			printf("Score is error!\n");
			continue;
		}
		switch(x / 10)
		{
		case 9:
		case 10:printf("A\n");break;
		case 8:printf("B\n");break;
		case 7:printf("C\n");break;
		case 6:printf("D\n");break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 0:printf("E\n");break;
		}
	}
}