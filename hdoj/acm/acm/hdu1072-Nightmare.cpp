#include <cstdio>
#include <string.h>
using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int T,n,m;
int v[10][10],startx,starty,lasttime[10][10];
struct{
	int x,y,timeleft,step;
}q[50000];
int bfs(){
	int head = 0,tail = 1;
	q[head].x = startx;
	q[head].y = starty;
	q[head].step = 0;
	q[head].timeleft = 6;
	lasttime[startx][starty] = 6;
	while (head != tail){
		for (int i = 0;i < 4;i++){
			int tx = dx[i] + q[head].x;
			int ty = dy[i] + q[head].y;
			if (tx >= 0 && ty >= 0 && tx < n && ty < m && v[tx][ty] > 0 && lasttime[tx][ty] < q[head].timeleft - 1){
				q[tail].x = tx;
				q[tail].y = ty;
				q[tail].step = q[head].step + 1;
				q[tail].timeleft = q[head].timeleft - 1;
				if (q[tail].timeleft == 0)
					continue;
				if (v[tx][ty] == 4)
					q[tail].timeleft = 6;
				if (v[tx][ty] == 3)
					return q[tail].step;
				lasttime[tx][ty] = q[tail].timeleft;
				tail = (tail + 1) % 50000;
			}
		}
		head = (head + 1) % 50000;
	}
	return -1;
}
int main(){
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		memset(lasttime,0,sizeof lasttime);
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++){
				scanf("%d",&v[i][j]);
				if (v[i][j] == 2){
					startx = i;
					starty = j;
				}
			}
		printf("%d\n",bfs());
	}
}