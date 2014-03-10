#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
struct condition
{
	int step;
	char direct;
};
int change(char chr )
{
	switch (chr)
	{
	case 'N':return 0;
	case 'E':return 1;
	case 'S':return 2;
	case 'W': return 3;
	}
}
int main()
{
	int row, col, x = 1, y, i, j, xt, yt;
	char hc;
	while (1)
	{
		cin >> row >> col >> y;
		if (row + col + y == 0)
			break;
		condition g[11][11];
		bool judge = true;
		for (i = 1; i <= row;i++)
		{
			scanf("%c",&hc);
			for (j = 1; j <= col;j++)
			{
				scanf("%c",&g[i][j].direct);
				g[i][j].step = 0;
			}
		}
		g[x][y].step = 1;
		while (1)
	    {
			xt =x + dx[change(g[x][y].direct)] ;
			yt =y + dy[change(g[x][y].direct)] ;
			if (xt < 1 || xt > row || yt < 1 || yt > col)
			{
				cout << g[x][y].step <<" step(s) to exit" <<endl;
				break;
			}
			if (g[xt][yt].step > 0)
			{
				cout << g[xt][yt].step - 1 << " step(s) before a loop of "<< g[x][y].step - g[xt][yt].step + 1<<" step(s)" <<endl;
				break;
			}
			g[xt][yt].step = g[x][y].step + 1;
			x = xt;
			y = yt;
		}
	}    
}
