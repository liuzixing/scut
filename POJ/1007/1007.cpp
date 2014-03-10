#include <iostream>
#include <string>
using namespace std;

int main()
{
	string DNA[101];
	int i = 1, j, n, m, k, sorted[101], order[101], tem;
	cin >> n >> m;
	while (i <= m)
	{
		cin >> DNA[i];
		order[i] = i;
		sorted[i] = 0;
        for (j = 0; j < n - 1; j++)
		{
          for (k = j + 1; k < n; k++)
		  {
			  if (DNA[i][j]>DNA[i][k])
			  {
				  sorted[i]++; 
			  }
		  }
		}
		i++;
	}
	for (j = 1; j < m; j++)
		{
          for (k = j + 1; k <= m; k++)
		  {
			  if (sorted[k] < sorted[j])
			  {
				   tem = sorted[k];
				   sorted[k] = sorted[j];
				   sorted[j] = tem;
				   tem = order[k];
				   order[k] = order[j];
				   order[j] = tem;
  			  }
		  }
		}
	for (j = 1; j <= m; j++)
		cout << DNA[order[j]] << endl;
}