#include<iostream> 
#include<cstdio>
#include<vector> 
using namespace std; 

double theRed(vector <int> red, vector <int> green) 
{ 
	long long ret[1001]; 
	long long num[1001]; 
	memset(ret , 0 , sizeof(ret)); 
	memset(num , 0 , sizeof(num)); 

    num[0] = 1; 
    ret[0] = 0; 

	int i , j; 
	for(i = 0;i < red.size();i++) 
	{ 
		int x = red[i] + green[i]; 
		for(j = 1000;j >= x;j--) 
		{ 
			if(num[j - x] != 0) 
			{ 
				num[j] += num[j - x]; 
				ret[j] += ret[j - x] + red[i] * num[j - x]; 
			} 
		} 
	} 
	double aaa = 0; 
	long long lll = 0; 
	for(i = 1;i <= 1000;i++) 
	{ 
		if(num[i] != 0) 
		{ 
			lll += num[i]; 
			aaa += double(ret[i]) / i;; 
		} 
	} 
	return aaa / lll; 
} 

int main()
{
	int n;
	while(scanf("%d" , &n) != EOF)
	{
		int i;
		vector<int> red , green;
		for(i = 0;i < n;i++)
		{
			int x;
			scanf("%d" , &x);
			red.push_back(x);
		}
		for(i = 0;i < n;i++)
		{
			int x;
			scanf("%d" , &x);
			green.push_back(x);
		}
		printf("%.4lf\n" , theRed(red , green));
	}
	return 0;
}