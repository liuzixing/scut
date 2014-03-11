/*
ID: benbenq1
PROG: ttwo
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
char g[11][11];
bool f1,f2;
int qx[10001],qy[10001],qd[10001],step[10001];
int qx2[10001],qy2[10001],qd2[10001],step2[10001];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
ifstream fin  ("ttwo.in");
ofstream fout ("ttwo.out");
void bfs()
{
	int head = 0,tail = 1,tx,ty,head2 = 0,tail2 = 1;
	while (head < tail && tail2 > head2)
	{
		//Farmer John move
		if (step[head] > 200 || step2[head2] > 200)
		{
			break;
		}
		tx = qx[head] + dx[qd[head]];
		ty = qy[head] + dy[qd[head]];
		if (tx >= 0 && tx< 10 && ty >= 0 && ty < 10 && g[tx][ty] != '*')
		{

			qx[tail] = tx;
			qy[tail] = ty;
			step[tail] = step[head] + 1;
			qd[tail] = qd[head];
			if (step2[tail2 - 1] == step[tail] && qx[tail] == qx2[tail2 - 1] && qy[tail] == qy2[tail2 - 1])
			{
				fout << step2[tail2 - 1] + 1<< endl;
				exit(0);
			}
			tail ++;
		}
		else
		{
			qx[tail] = qx[head];
			qy[tail] = qy[head];
			qd[tail] = (qd[head] + 1) % 4;
			step[tail] = step[head] + 1;
			if (step2[tail2 - 1] == step[tail] && qx[tail] == qx2[tail2 - 1] && qy[tail] == qy2[tail2 - 1])
			{
				fout << step2[tail2 - 1] + 1<< endl;
				exit(0);
			}
			tail ++;
		}
		head++;
		//Cows move
		tx = qx2[head2] + dx[qd2[head2]];
		ty = qy2[head2] + dy[qd2[head2]];
		if (tx >= 0 && tx< 10 && ty >= 0 && ty < 10  && g[tx][ty] != '*')
		{
			qx2[tail2] = tx;
			qy2[tail2] = ty;
			step2[tail2] = step2[head2] + 1;
			qd2[tail2] = qd2[head2];
			if (step2[tail2] == step[tail - 1] && qx[tail - 1] == qx2[tail2] && qy[tail - 1] == qy2[tail2])
			{
				fout << step[tail2 - 1] + 1<< endl;
				exit(0);
			}
			tail2 ++;
		}
		else
		{
			qx2[tail2] = qx2[head2];
			qy2[tail2] = qy2[head2];
			qd2[tail2] = (qd2[head2] + 1) % 4;
			step2[tail2] = step2[head2] + 1;
			if (step2[tail2] == step[tail - 1] && qx[tail - 1] == qx2[tail2] && qy[tail - 1] == qy2[tail2])
			{
				fout << step[tail2 - 1] + 1 << endl;
				exit(0);
			}
			tail2 ++;		
		}
		head2++;
		if (f1 && f2)
		{
			break;
		}
	}
}
int main()
{
	int i,j;
	char c;
	for (i = 0;i < 10;i++)
	{
		for (j = 0;j < 10;j++)
		{
			fin >> c;
			g[i][j] = c;
			if (c == 'C')
			{
				qx2[0] = i;
				qy2[0] = j;
				qd2[0] = 0;
				g[i][j] = '.';
			}
			if (c == 'F')
			{
				qx[0] = i;
				qy[0] = j;
				qd[0] = 0;
				g[i][j] = '.';
			}

		}
	}
	bfs();
	fout << 0 << endl;
}