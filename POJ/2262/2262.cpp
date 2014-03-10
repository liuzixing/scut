#include <iostream>
#include <cmath>
using namespace std;
/*int k = 0;*/
int primenumber[1000001];
void createprimenumber()
{
	int i,j;
	for (i = 2;i < 1000;i++)
	{
		if (primenumber[i])
		for (j = 2 * i ;j <= 1000000;j+=i)
		{
			primenumber[j] = 0;	
		}
	}

}
/*int find(int primenumber[] ,int n)
{
	int l = 0, r = k,mid;
	while(l < r -1)
	{
		mid = (l + r) / 2;
		if (primenumber[mid] == n)
		{
			return mid;
		}
		if (n <= primenumber[mid])
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	return l;
}*/
int main()
{
	int n;
	memset(primenumber, 1, sizeof(primenumber));
	createprimenumber();
	cin >> n;
	while (n)
	{
		/*int l,r;
		l = 0;
		r = find(primenumber,n);
		while (l < r)
		{
			if (primenumber[l]+primenumber[r] == n)
			{
				cout << n << " = " << primenumber[l] << " + " << primenumber[r] <<endl;
				break;
			}
			if (primenumber[l]+primenumber[r] > n)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		if (l==r)
		{
			cout << "Goldbach's conjecture is wrong."  << endl;
		}*/
		int i;
		for(i = 3; i <= n/2; i+=2)
			if(primenumber[i] && primenumber[n-i])
			{
				cout << n << " = " << i << " + " << n - i <<endl;
				break;
			}
		if(i == n/2+1)
			cout << "Goldbach's conjecture is wrong." << endl;
		cin >> n;
	}
}