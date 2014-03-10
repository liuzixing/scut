#include <iostream> 
#include <cstdlib> 
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  int i,j,k,v[50],m[50],n;
  bool f[500000];

  while (cin >> n && n >= 0)
  {
	  int Min = 1000000,sum = 0;
	  memset(f,0,sizeof(f));
	  f[0] = 1;
	  for (i = 0;i < n;i++)
	  {
		  scanf("%d %d",&v[i],&m[i]);
		  sum += v[i] * m[i];
	  }
	  for (i = 0;i < n;i++)
		  for (k = 1;k <= m[i];k++)
			  for (j = sum;j >= v[i];j--)
			  {
				  if (f[j - v[i]])
					  f[j] = 1;
			  }
	  for (i = 0;i <= sum;i++)
	  {
		  if (sum - i * 2 < 0)
			  break;
		  if (f[i] && Min > sum - i * 2)
			  Min = sum - i * 2;
	  }
	  printf("%d %d\n",(sum + Min) / 2,(sum - Min) / 2);
  }
}
 
