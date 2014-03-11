#include <iostream>
#include  <cstring>
#include <fstream>
using namespace std;
struct condition
{
	char l[12],r[12],op[5];
};
bool check(condition judge[],int k,int horl)
{
	int a[13] = {0},i,j;
	a[k] = horl;
	int pd = 0;
	bool flag = true;
	for (i = 0; i < 3; i++)
	{
		int suml = 0,sumr = 0;
		int len = strlen(judge[i].l);
		for (j = 0; j < len;j++)
		{
			suml += a[judge[i].l[j] - 'A' + 1];
			sumr += a[judge[i].r[j] - 'A' + 1];
			if (judge[i].l[j] - 'A' + 1 == k)
			{
				pd++;
			}
			if (judge[i].r[j] - 'A' + 1 == k)
			{
				pd++;
			}
		}
		switch (judge[i].op[0])
		{
		    case 'e': if (suml == sumr) 
				  {
					  continue;
				  }
				  else
				  {
					  flag =  false;
				  };break;
			case 'u': if (suml > sumr) 
				  {
					  continue;
				  }
				  else
				  {
					  flag =  false;
				  };break;
			case 'd': if (suml < sumr) 
				  {
					  continue;
				  }
				  else
				  {
					  flag =  false;
				  };break;
		}
	}
	if (!pd)
	{
		flag = false;
	}
	return (flag);
	 
}
int main()
{
	int n,i;
	ifstream fin ("test.in");
	cin >> n;
	while (n)
	{
		n--;
        condition judge[4];
		cin >> judge[0].l >> judge[0].r >> judge[0].op;
		cin >> judge[1].l >> judge[1].r >> judge[1].op;
		cin >> judge[2].l >> judge[2].r >> judge[2].op;
		for (i = 1; i < 13;i++)
		{
			if (check(judge,i,-1))
			{
				cout << char ('A' + i - 1) <<" is the counterfeit coin and it is light." << endl;
				break;
			}
			if (check(judge,i,1))
			{
				cout << char ('A' + i - 1) <<" is the counterfeit coin and it is heavy." << endl;
				break;
			}
		}
	}
}
