#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("test.in");
	char op[20], web[100][100];
	int back[100], forward[100], now = 0, btop = 0, ftop = 0;
	int i = 1;
	fin >> op;
	strcpy(web[0],"http://www.acm.org/");
	while (strcmp(op,"QUIT"))
	{
		if (!strcmp(op,"VISIT"))
		{
			fin >> web[i];
			ftop = 0;
			btop++;
			back[btop - 1] = now;
			now = i;
			i++;
		}
		else
		{
			if (!strcmp(op,"BACK"))
			{
				if (btop == 0)
				{
					cout << "Ignored" << endl;
					fin >> op;
					continue;
				}
				ftop++;
				forward[ftop - 1] = now;
				now = back[btop - 1];
				btop--;
			}
			if (!strcmp(op,"FORWARD"))
			{
				if (ftop == 0)
				{
					cout << "Ignored" << endl;
					fin >> op;
					continue;
				}
				btop++;
				back[btop - 1] = now;
				now = forward[ftop - 1];
				ftop--;
			}
		}
		cout << web[now] << endl;
		fin >> op;
	}
}