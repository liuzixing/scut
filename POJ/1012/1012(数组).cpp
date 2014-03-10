#include<iostream>
using namespace std;

int memory[14];

bool Joseph(int k,int m)
{
	int i = 0;
	int len = k * 2;
	while (len > k)
	{
		i = (i + m - 1) % len;
		if (i < k)
			return false;
		len --;
	}
	return true;
}
int getnum(int k)
{
	int i = k + 1;
    while (1)
    {
        if(Joseph(k,i))
        {
            return i;
        }
        if(Joseph(k,i + 1))
        {
            return i + 1;
        }
        i += ( k + 1 );
    }
}
void memory1()
{
    for (int i = 1 ;i < 14;i++)
    {
        memory[i] = getnum(i);
    }
}
int main()
{
	int k = 1;
	memory1();
	while (k > 0)
	{
		cin >> k;
		if (k > 0)
		{
		
			cout << memory[k] << endl;
		}
	}

}