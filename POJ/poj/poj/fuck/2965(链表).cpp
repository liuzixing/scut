#include <iostream>
using namespace std;
int f[16];
int turn[16]= {0};
int start;
const int size = 65536;
int  visit[size] = {0};
int step[size];

struct node
{
	int x,y;
	node *last;
};
struct condition
{
	int location;
	node *path;
	
};
condition q[size];
void init()
{
	char ch;
	int i, j, k, t = 0;
	f[0] = 1;
	start  = 0;
	for (i = 1; i < 16;i++)
	{
		f[i] = f[i - 1] * 2;
	}
	for(i = 0; i < 4;i++)
	{
		for(j = 0; j < 4;j++)
		{
			cin >> ch;
			if (ch == '+')
			{
				start +=  f[i * 4 + j];
			}
			for (k = 0; k < 4;k++)
			{
				turn[t] += f[i * 4 + k] + f[k * 4 +j];
			}
			turn[t] -= f[i * 4 + j];
			t++;
		}
	}
}
void output(node *path1)
{
	if (path1->x == -1)
	return;
	output(path1->last);
	cout << path1->x + 1 << " " << path1->y + 1<< endl; 
	return;
}
void bfs()
{
	int head = 0, tail = 1, i, j, next, t;
	q[head].location = start; 
	q[head].path = new node;
	q[head].path->x = -1;
	q[head].path->y = -1;
	step[start] = 0;
	visit[start] = 1;
	while (head != tail)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				next = i * 4 + j;
				t = q[head].location ^ turn[next];
				if (visit[t] == 0)
				{
					q[tail].location = t;
					q[tail].path = new node;
					q[tail].path->x = i;
					q[tail].path->y = j;
					q[tail].path->last = q[head].path;
					step[q[tail].location] = step[q[head].location] + 1;
					visit[t] = 1;
					if (t == 0)
					{
						cout << step[q[tail].location] << endl;
						output (q[tail].path);
					}
					tail++;
				}
			}
		}
		head++;
	}
}
int main()
{
	init();
	bfs();
}