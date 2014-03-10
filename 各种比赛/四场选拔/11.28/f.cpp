#include <iostream>

using namespace std;
char c[200][200];
int x[250],y[250];
const int dx[4] ={-1,-1,1,1};
const int dy[4] = {-1,1,-1,1};

void output4()
{
	int i,j;
	for (i = 1;i <= 27;i++)
	{
		for (j = 1;j <= 27;j++)
		{
			cout << c[i][j];
		}
cout <<endl;
	}
}
void output5()
{
	int i,j;
	for (i = 1;i <= 81;i++)
	{
		for (j = 1;j <= 81;j++)
		{
			cout << c[i][j];
		}
        cout <<endl;
	}
}
int main()
{
	int d,i,j,k;

	x[1] = 2;
	x[2] = 2;
	x[3] = 5;
	x[4] = 8;
	x[5] = 8;
	y[1] = 2;
	y[2] = 8;
	y[3] = 5;
	y[4] = 2;
	y[5] = 8;
	k =6;
    for (i = 1;i <=5;i++)
	{
		x[k] = x[i] + 9;
		y[k] = y[i] + 9;	
		k++;
		x[k] = x[i] + 18;
	    y[k] = y[i];
		k++;
	    x[k] = x[i];
	    y[k] = y[i] + 18;
		k++;
	    x[k] = x[i] + 18;
	    y[k] = y[i] + 18;
		k++;
	}	
    for (i = 1;i <= 25;i++)
	{
		x[k] = x[i] + 27;
		y[k] = y[i] + 27;	
		k++;
		x[k] = x[i] + 54;
	    y[k] = y[i];
		k++;
	    x[k] = x[i];
	    y[k] = y[i] + 54;
		k++;
	    x[k] = x[i] + 54;
	    y[k] = y[i] + 54;
		k++;
	}	
	k--;
	for (i = 1;i <= 127;i++)
	{
		for (j = 1;j <=127;j++)
		{
			c[i][j] = ' ';
		}
	}
	for (i = 1;i <=125;i++)
	{

		c[x[i]][y[i]] = '#';
		for (j = 0;j <4;j++)
		{
			c[x[i]+dx[j]][y[i]+dy[j]] = '#';
		}
	}
	while (cin >> d)
	{
		if (d == -1)
		{
			break;
		}
	switch(d)
	{
	case 1:cout << "#\n";break;
	case 2:cout <<"# #\n # \n# #\n";break;
	case 3:cout <<"# #   # #\n #     # \n# #   # #\n   # #   \n    #    \n   # #   \n# #   # #\n #     # \n# #   # #\n";break;
	case 4:output4();break;
    case 5:output5();break;
	}
	}
}