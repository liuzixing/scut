#include <iostream>
using namespace std;
int f[16];
int turn[16]= {0};
int start;
const int size = 65536;
int  visit[size] = {0};
int step[size];

struct condition
{
	int location;
	int last;
	int x,y;
};
condition q[size];
void init()
{
	char ch;
	start  = 0;
	int i, j, k, t = 0;
	f[0] = 1;
	
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
void output(int t)
{
	if (q[t].x == -1)
	return;
	output(q[t].last);
	cout << q[t].x + 1 << " " << q[t].y + 1<< endl; 
	return;
}
void bfs()
{
	int head = 0, tail = 1, i, j, next, t;
	q[head].location = start; 
	q[head].x = -1;
	q[head].y = -1;
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
					q[tail].x = i;
					q[tail].y = j;
					q[tail].last = head;
					step[q[tail].location] = step[q[head].location] + 1;
					visit[t] = 1;
					if (t == 0)
					{
						cout << step[q[tail].location] << endl;
						output (tail);
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