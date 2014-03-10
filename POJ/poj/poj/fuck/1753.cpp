#include <iostream>
#include <stdio.h>
using namespace std;
int f[16] = {0};
int flip[16] = {51200,58368,29184,12544,35968,20032,10016,4880,2248,1252,626,305,140,78,39,19};
int ans = 16;
const int size = 65536;
const int dx[5] = {0,-1,0,1,0};
const int dy[5] = {0,0,1,0,-1};
void init(int &g)
{
	char c;
	int i, j/*, t, t1, k*/;
	f[0] = 1;
	for (i = 1; i < 16; i++)
	{
		f[i] = f[i - 1] * 2;
	}
	for (i = 0;i < 4;i++)
	{
		for (j = 0; j < 4;j++)
		{
			cin >> c;
			if (c == 'b')
			{
				g += f[i * 4 + j];
			}
		}
	}
	/*for (i = 0; i < 4;i++)
	{
		for (j = 0; j < 4;j++)
		{
			for (k = 0; k < 5; k++)
			{
			  t = i * 4 + j;
			  t1 = (i + dx[k]) * 4 + j+ dy[k];
			  if (i + dx[k] >= 0 && i + dx[k] < 4 && j+ dy[k] < 4 && j+ dy[k] >= 0)
			  {
				  flip[t] += f[t1];
			  }
			}
		}
	}*/
}
void bfs(int g)
{
	int rear, front, visit[size] = {0}, step[size], q[size], i;
	rear = 1;
	front = 0;
	visit[g] = 1;
	step[g] = 0;
	q[front] = g;
	if (q[front] == 0 || q[front] == 65535)
	{
	    ans = step[q[front]];
		return;
	}
	while (rear != front)
	{
		for (i = 0; i < 16;i++)
		{ 
			if (visit[q[front] ^ flip[i]] == 0)
			{
				q[rear] = q[front] ^ flip[i];
				step[q[rear]] = step[q[front]] + 1;
				if (q[rear] == 0 || q[rear] == 65535)
	            {
		            ans = step[q[rear]];
			        return;
	            }
				visit[q[rear]] = 1;
			    rear++;
			}
		}
		front++;
	}
	return;
}
int main()
{
	
	int g = 0;
	init(g);
	bfs(g);
	if (ans == 16)
	{
		cout << "Impossible" << endl;
	}
	else
	{	
		cout << ans << endl;
	}
}