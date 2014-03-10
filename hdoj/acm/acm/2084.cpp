#include<iostream>
#include <iostream>
using namespace std;

int main()
{
	int N; 
	cin >> N;
	while( N-- )
	{
		int f[100][100];
		int n; 
		cin >> n;
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j <= i; j++ ) 
			{
                cin >> f[i][j];
			}
		}
		for( int i = n - 1; i > 0; i-- )
		{
			for( int j = 0; j < i; j++ )
			{
				if( f[i][j] >= f[i][j + 1] ) 
				{
					f[i - 1][j] += f[i][j];
				}
				else
				{
					f[i - 1][j] += f[i][j + 1];
				}
			}
		}
		cout << f[0][0] << endl;
	}
}