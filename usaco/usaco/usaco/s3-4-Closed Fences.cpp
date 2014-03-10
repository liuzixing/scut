/*
ID: benbenq1
PROG: fence4
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

const int MAXN = 210;

struct point
{
	double x,y;
};

struct edge
{
	point *v[2];
};
//观察点，顶点集
point watcher,*vertex[MAXN];
bool isinsight[MAXN];
int N;
edge *fence[MAXN];

//向量叉积
inline double crossproduct(double x1,double y1,double x2,double y2){return x1 * y2 - x2 * y1;}
// 检查a,b是否相交
inline bool iscross(edge *a,edge *b)
{
	point *s = a->v[0];
	if (crossproduct(a->v[1]->x - s->x,a->v[1]->y - s->y,b->v[0]->x - s->x,b->v[0]->y - s->y)
		* crossproduct(a->v[1]->x - s->x,a->v[1]->y - s->y,b->v[1]->x - s->x,b->v[1]->y - s->y) >= 0)
		return 0;
	s = b->v[0];
	if (crossproduct(b->v[1]->x - s->x,b->v[1]->y - s->y,a->v[0]->x - s->x,a->v[0]->y - s->y)
		* crossproduct(b->v[1]->x - s->x,b->v[1]->y - s->y,a->v[1]->x - s->x,a->v[1]->y - s->y) >= 0)
		return 0;
	return 1;
}

//创建边集
void createedge()
{
	N--;
	for (int i = 0;i < N;i++)
	{
		fence[i] = new edge();
		fence[i]->v[0] = vertex[i];
		fence[i]->v[1] = vertex[i + 1];
	}
	fence[N] = new edge();
	fence[N]->v[0] = vertex[0];
	fence[N]->v[1] = vertex[N];
	N++;
}
//检查能不能构成多边形
void checkcross()
{
	for (int i = 0;i < N;++i)
         for (int j = 0;j < N;++j)
         { 
             if (i == j) continue;
             if (!iscross(fence[i],fence[j]))
				 continue;
             cout << "NOFENCE\n";
             exit(0);
         }
     return;
}

/*
给定一个射线OA（向量OA与x轴正方向的夹角），算法将记录下边集中与射线OA有交点且交点离O点最近的线段。
*/
void checkline(double angle)
{
	double mind = 1e16;
	int firstcrash = -1;
	double lx = cos(angle),ly = sin(angle);
	double d,t;
	for (int i = 0;i < N;i++)
	{
		 double &x = watcher.x;
         double &y = watcher.y;
         double &x1 = fence[i]->v[0]->x;
         double &y1 = fence[i]->v[0]->y;
         double &x2 = fence[i]->v[1]->x;
         double &y2 = fence[i]->v[1]->y;
		 //不相交继续循环；
		 if (crossproduct(x1-x,y1-y,lx,ly) * crossproduct(x2-x,y2-y,lx,ly) >= 0)
			 continue;
		 if (x2 - x1==0)
         {
            d = (x1 - x) / lx;
         }
		 else
		 {
             t = (y2 - y1) / (x2 - x1);
             d = (t * (x1 - x) + y - y1) / (t * lx - ly);
         }
         if (d > 0 && d < mind)
         {
            mind = d;
            firstcrash = i;
         }
	}
	if (firstcrash != -1) 
        isinsight[firstcrash] = 1;    //记录可见边 
}

/*
枚举观察点到每个顶点的向量，然后把其与x轴的夹角(+-)1E-8 rad 后检查沿该方向能看到的fence 
*/

void calcsight()    
{
     for (int i = 0;i < N;i++)
		 isinsight[i] = 0;
     double tmpangle;
     for (int i = 0;i < N;++i)
     {
         tmpangle = atan2(vertex[i]->y - watcher.y,vertex[i]->x - watcher.x);
         checkline(tmpangle + 1E-8);
         checkline(tmpangle - 1E-8);
     }
     return;
}

int main()
{
	freopen("fence4.in","r",stdin);
	freopen("fence4.out","w",stdout);
	cin >> N;
	cin >> watcher.x >> watcher.y;
	for (int i = 0;i < N;i++) 
	{
		vertex[i] = new point();
		cin >> vertex[i]->x >> vertex[i]->y;
		
	}
	createedge();
	checkcross();
	calcsight();
	int counter = 0;
	for (int i = 0;i < N;++i) 
		counter += isinsight[i];
    cout << counter <<endl;
 
    for (int i = 0;i < N - 2;++i)
        if (isinsight[i]) cout <<fence[i]->v[0]->x <<" "
                               <<fence[i]->v[0]->y <<" "
                               <<fence[i]->v[1]->x <<" "
                               <<fence[i]->v[1]->y <<"\n";
    if (isinsight[N - 1]) cout <<fence[N - 1]->v[0]->x <<" "
                               <<fence[N - 1]->v[0]->y <<" "
                               <<fence[N - 1]->v[1]->x <<" "
                               <<fence[N - 1]->v[1]->y <<"\n";
    if (isinsight[N - 2]) cout <<fence[N - 2]->v[0]->x <<" "
                               <<fence[N - 2]->v[0]->y <<" "
                               <<fence[N - 2]->v[1]->x <<" "
                               <<fence[N - 2]->v[1]->y <<"\n";
}