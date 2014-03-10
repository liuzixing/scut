#include <iostream>
using namespace std;

int main()
{
int n;
while (cin >> n)
{
	switch (n % 3)
	{
	case 0:cout <<"even"<< endl;break;
		case 1:cout <<"odd"<< endl;break;
			case 2:cout <<"odd"<< endl;break;
	}
}
}