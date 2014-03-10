#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main()
{
	int n;
	char c;
	scanf("%d%*c",&n);
	while (n)
	{
		n--;
		int a[5] = {0};
		while ((c = getchar()) != '\n')
		{
			switch(tolower(c))
			{
			case 'a':a[0]++;break;
			case 'e':a[1]++;break;
			case 'i':a[2]++;break;
			case 'o':a[3]++;break;
			case 'u':a[4]++;break;
			default:break;
			}
		}
		printf("a:%d\n", a[0]);
        printf("e:%d\n", a[1]);
        printf("i:%d\n", a[2]);
        printf("o:%d\n", a[3]);
        printf("u:%d\n", a[4]);
        if (n) putchar('\n');
	}
}