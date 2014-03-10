#include <iostream>
#include <cstring>

using namespace std;

#ifndef HUGEINTEGER
#define HUGEINTEGER

class hugeInteger
{
public:
	hugeInteger( char* );
	
	void output();
	hugeInteger add( hugeInteger );
	hugeInteger substract( hugeInteger );

private:
	int num[42];
	int len;
};

#endif

hugeInteger::hugeInteger( char *s )
{
	len = strlen(s);
	memset( num, 0, sizeof(num) );

	for ( int j = 0, i = len - 1; i >= 0; --i )
		num[j++] = s[i] - '0';
}

void hugeInteger::output()
{
	for ( int i = len - 1; i >= 0; --i )
		cout << num[i];

	cout << endl;
}

hugeInteger hugeInteger::add( hugeInteger a )
{
	if ( len < a.len )
		return a.add( *this );
	else
	{
		hugeInteger ans = *this;
		for ( int i = 0; i < len; ++i )
		{
			ans.num[i] += a.num[i];
			ans.num[i + 1] += ans.num[i]/10;
			ans.num[i] %= 10;
		}

		if ( ans.num[len + 1] )
			len++;

		return ans;
	}
}

hugeInteger hugeInteger::substract( hugeInteger a )
{
	if ( len < a.len )
		return a.add( *this );
	else
	{
		hugeInteger ans = *this;
		for ( int i = 0; i < len; ++i )
			ans.num[i] -= a.num[i];
		
		for ( int i = 0; i < len; ++ i )
		{
			if ( ans.num[i] < 0 )
			{
				ans.num[i] += 10;
				ans.num[i + 1]--;
			}
		}

		return ans;
	}
}

int main()
{
	char a[42], b[42], c[42], d[42];

	cin >> a >> b >> c >> d;
	hugeInteger n1(a);
	hugeInteger n2(b);
	hugeInteger n3(c);
	hugeInteger n4(d);

	hugeInteger result1 = n1.add(n2);
	hugeInteger result2 = n3.substract(n4);

	result1.output();
	result2.output();

	return 0;
}



