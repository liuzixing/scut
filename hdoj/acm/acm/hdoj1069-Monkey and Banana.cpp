#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

class block
{
     public:
        int h,w,l,area;
        void set(int x,int y,int z)//设置长宽高，面积
        {
			h = x,w = y,l = z;
			area = l * w;
		}
} ;
bool cmp(block a,block b)
{
	return a.area < b.area;
}
int main()
{
    block b[90];
    int f[90];
    int len=0,i,j,cas=0;
    int x,y,z,n,max;
    while(cin>>n && n)
    {
        cas++;
        len=0;
        for(i=0;i<n;i++)
        {
          cin>>x>>y>>z;
          b[len++].set(x,y,z);
          b[len++].set(y,z,x);
          b[len++].set(z,x,y);
        }
        n = n * 3;
		sort(b,b + n,cmp);
        for(i=0;i<n;i++)
        f[i]=b[i].h;
        for(i=1;i<n;i++)
        {
           max=0;
           for(j=0;j<i;j++)
           {
              if((b[i].l > b[j].l&&b[i].w > b[j].w || b[i].l > b[j].w && b[i].w > b[j].l) && max < f[j])
              max = f[j];
           }
           f[i] += max;
        }
        for(i = max = 0;i < n;i++)
        if(max < f[i])
        max = f[i];
        cout << "Case " << cas << ": maximum height = " << max << endl;
    }
    return 0;
}
 
