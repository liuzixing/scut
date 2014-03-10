#include<iostream>
#include<algorithm>

using namespace std;
 
typedef long long LL;
 
const int MD = 1000000007;

int numbers[60];
 
int main(){
	//freopen ("numbers.in", "r",stdin);
    //freopen ("numbers.out", "w", stdout);
	int n;
	cin>>n;
	while(n--)
	{
		int i,m;
		cin>>m;
		for(i=1;i<=m;i++)
			cin>>numbers[i];
		sort(numbers+1,numbers+m+1);
		long long res = 1;
		for(i = 1; i <= m; ++i)
		{
			if(numbers[i] < i) { res= 0;break;}
			res = (res * (numbers[i] - i + 1)) % MD;
		}
		cout<<res<<endl;
    }
	return 0;
}
