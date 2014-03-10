#include<iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
const int dy[4] = {1,0,-1,0};
const int dx[4] = {0,1,0,-1};
struct robotcondition
{
	int x, y, direction;
};
int main()
{
	int i, j, k, n, m, a, b, ri, times;
	int robot1, robot2;
	char chr;
	cin >> k;
	while (k)
	{
		k--;
		int warehouse[100][100] = {0};
		robotcondition  robot[100] = {0};
		bool ok = true;
		cin >> a >> b;
		cin >> n >> m;
		for (i = 0; i < n ; i++)
		{
			cin >> robot[i].x >> robot[i].y >> chr;
			switch (chr)
			{
			case 'N':robot[i].direction = 0;break;
			case 'E':robot[i].direction = 1;break;
			case 'S':robot[i].direction = 2;break;
			case 'W':robot[i].direction = 3;break;
			}
			warehouse[robot[i].y - 1][robot[i].x - 1] = i + 1;
		}
		for (i = 0; i < m; i++)
		{
			cin >> ri >> chr >> times;
			ri--;
			if (ok)
			{
				if (chr == 'F')
				{
					warehouse[robot[ri].y - 1][robot[ri].x - 1] = 0;
					for (j = 0; j < times && ok ; j++)
					{
						robot[ri].x += dx[robot[ri].direction];
						robot[ri].y += dy[robot[ri].direction];
						if (robot[ri].x < 1 || robot[ri].x > a || robot[ri].y < 1 || robot[ri].y > b)
						{
							ok =false;
							robot1 = ri + 1;
							robot2 =0;
						}
						else
							if (warehouse[robot[ri].y - 1][robot[ri].x - 1] != 0)
							{
								ok = false;
								robot1 = ri + 1;
								robot2 = warehouse[robot[ri].y - 1][robot[ri].x - 1];
							}
					}
					if (ok)
						warehouse[robot[ri].y - 1][robot[ri].x - 1] = ri + 1;
				}
				else
				{
					int dtem = robot[ri].direction;
					dtem =  (chr == 'L') ? (dtem - times) : (dtem + times);
					dtem %= 4;
					dtem = (dtem < 0) ? (dtem + 4) : dtem;
					robot[ri].direction = dtem;
				}
			}
		}
		if (ok)
		{
			printf("OK\n");
		}
		else
		{
			if (robot2 != 0)
			{
				printf("Robot %d crashes into robot %d\n", robot1, robot2);       	
			}
			else
			{
			  printf("Robot %d crashes into the wall\n", robot1);
			}
		}
	}

}