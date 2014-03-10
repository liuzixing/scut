#include <iostream>
#include <string>
using namespace std;
const int K[2][2] = {0,0,0,1},A[2][2] = {0,1,1,1},C[2][2] = {1,1,0,1},
	      N[2] = {1,0},E[2][2] = {1,0,0,1};
int p,q,r,s,t,now;
string s1;
bool  check()
{
	now++;
	switch(s1[now])
	{
	case (int)'K' :return K[check()][check()];
	case (int)'A' :return A[check()][check()];
	case (int)'C' :return C[check()][check()];
	case (int)'N' :return N[check()];
	case (int)'E' :return E[check()][check()];
	case (int)'p' :return p;	
	case (int)'q' :return q;
	case (int)'r' :return r;
	case (int)'s' :return s;
	case (int)'t' :return t;
	}
}
int main()
{
	while (cin >> s1 && s1 != "0")
	{
		int flag = false;
		for (p = 0;p < 2 && !flag;p++)
		{
			for (q = 0;q < 2 && !flag;q++)
			{
				for (r = 0;r < 2 && !flag;r++)
				{
					for (s = 0;s < 2 && !flag;s++)
					{
						for (t = 0;t < 2 && !flag;t++)
						{
							now = -1;
							if (!check())
							{
								flag = true;
							}
						}
					}
			    }
		 	 }
	      }
		  if (flag)
		  {
			  cout << "not\n";
		  }
		  else
		  {
			  cout << "tautology\n";
		  }
	 }
}
