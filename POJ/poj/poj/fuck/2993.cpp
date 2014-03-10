#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct condition
{
	char what;
}g[8][8];
char dot[8][8];
int main()
{
	ifstream fin ("test.in");
	char edge[50] = "+---+---+---+---+---+---+---+---+";
	string s1;
	int i,j,len;
	for (i = 0;i < 8; i++)
	{
		for (j = 0;j < 8;j++)
		{
			if (i % 2 ==0)
			{
				if  (j % 2 ==0)
				{
					dot[i][j] = '.';
				}
				else
				{
					dot[i][j] = ':';
				}
			}
			else
			{
				if  (j % 2 !=0)
				{
					dot[i][j] = '.';
				}
				else
				{
					dot[i][j] = ':';
				}
			}

		}
	}
	cin >> s1 >> s1;
	len = s1.length();
	i = 0;
	while (i < len)
	{
	 switch (s1[i])
	 {
		case 'K':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'K';i += 3;break;
		case 'Q':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'WQ';i += 3;break;
		case 'R':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'WR';i += 3;break;
		case 'B':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'WB';i += 3;break;
		case 'N':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'WN';i += 3;break;
		case ',':i++;break;
		default:g[8 - s1[i + 1] + '0'][s1[i] - 'a'].what = 'WP';i += 2;break;
	 }
	}
	cin >> s1 >> s1;
	len = s1.length();
	i = 0;
	while (i < len)
	{
	 switch (s1[i])
	 {
		case 'K':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'k';i += 3;break;
		case 'Q':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'Wq';i += 3;break;
		case 'R':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'Wr';i += 3;break;
		case 'B':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'Wb';i += 3;break;
		case 'N':g[8 - s1[i + 2] + '0'][s1[i + 1] - 'a'].what = 'Wn';i += 3;break;
		case ',':i++;break;
		default:g[8 - s1[i + 1] + '0'][s1[i] - 'a'].what = 'Wp';i += 2;break;
	 }
	}
	cout << edge << endl;
	for(i = 0;i < 8;i++)
	{
		cout << '|';
		for(j = 0;j < 8;j++)
		{
			if (g[i][j].what == '\0')
			{
				cout << dot[i][j] << dot[i][j] << dot[i][j] <<'|';
			}
			else
			{
                cout << dot[i][j] << g[i][j].what << dot[i][j] <<'|';
			}
		}
		cout << endl;
		cout << edge << endl;
	}
}