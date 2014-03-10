#include <stdio.h>
#include <string.h>

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int y)
{
	if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return 1;
	return 0;
}

void work(int n, int f[])
{
	int i, j, s = 1;
	for(i = 0; i < n; ++i)
	{
		for(j = 1; j <= 12; ++j)
		{
			s += 12;
			++f[s % 7];
			if(j == 2 && is_leap_year(1900 + i))
				s += 29 - 12;
			else
				s += month[j] - 12;
		}
	}
}

int main()
{
	int n, f[7], i;
	while (~scanf("%d", &n))
	{
	    memset(f, 0, sizeof(f));
        work(n, f);
        printf("%d\n%d\n", f[6], f[0]);
        for (int i = 1;i < 6;i++)
            printf("%d\n",f[i]);
	}
	return 0;
}
