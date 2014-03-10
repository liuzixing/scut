#include <iostream>
using namespace std;
int dx[] = {1,-1,0,0};//坐标
int dy[] = {0,0,-1,1};
int g[101][101];//高度
int f[101][101];//最大值
int r,c;

bool able(int x, int y)
{
	return (x < r && x >= 0 && y < c && y >= 0);
}

int dp_distance(int x,int y)
{
	int k, temp;
	if (f[x][y] > 0)
	{
		return f[x][y];
	}
	for (k = 0; k < 4; k++)
	{
		if (able(x + dx[k],y + dy[k]))
		{
			if (g[x][y] > g[ x + dx[k] ][ y + dy[k] ])
			{
				temp = dp_distance(x + dx[k],y + dy[k]);
				f[x][y] = f[x][y] > temp ? f[x][y] : temp + 1;
			}
		}
	}
	return f[x][y];
}
int main()
{
	int i ,j ,max = 0,temp;
	cin >> r >> c;
	for (i = 0; i < r; i++)
	{
		for (j = 0;j < c; j++)
		{
			cin >> g[i][j];
			f[i][j] = 0;
		}
	}
	for (i = 0; i < r; i++)
	{
		for (j = 0;j < c; j++)
		{
			temp = dp_distance(i,j);
			if (temp > max) 
			{
				max = temp;
			}
		}
	}
	cout << max + 1 <<endl; 
}