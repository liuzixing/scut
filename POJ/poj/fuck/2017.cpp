#include <iostream>
using namespace std;
int main()
{
	int n, ans,i,s,t,t0;
	cin >> n;
	while (n != -1)
	{
		t0 = 0;
		ans = 0;
		for (i = 0;i < n;i++)
		{
			cin >> s >> t;
			ans += s * (t - t0);
			t0 = t;
		}
		cout << ans << " miles" <<endl;
		cin >> n;
	}

}