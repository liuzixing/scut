#include <iostream>
using namespace std;
int a[7];	
void doit (int n)
{
	int i;
	int b[7];
	while (n)
	{
	n--;
	cout << endl;
	b[0]=(a[1]+a[2]) %1000;
    b[1]=a[2];
    b[2]=(a[0]+1) % 1000;
    b[3]=a[0]*a[1];
    b[4]=a[0] & a[1] & a[2] ;
    b[5]=a[1]-a[0]+a[2];
    b[6]=(a[0]*a[1]*a[2])% 1000;
	for (i = 0;i < 7;i++)
	{
		a[i] = b[i];
	}
	}
}
int main()
{
	int i,n,t;
	cin >>t;
	while (t)
	{
		t--;
		cin >>n;
		for (i = 0;i < 7;i++)
		{
			cin >> a[i];
		}
		doit(n);
		for (i = 0;i < 6;i++)
	    {
		  cout << a[i] << " ";
	    }
		cout << a[6] <<endl;
	}

}

