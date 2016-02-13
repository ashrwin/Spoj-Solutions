#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long ull;
ull lastDigit( int a , ull b )
{
	if ( !a && !b ) return 0;
	ull ret = 1;
	while ( b > 0 )
	{
		if ( b % 2 )
			ret = ( ret*a ) % 10;
		b >>= 1;
		a = ( a*a ) % 10;
	}
	return ret;
}

int main()
{
	int t;
	ull b;
	int a;
	string s;
	cin >> t;
	for ( int i = 0; i < t; ++i )
	{
		cin >> s >> b;
		a = s[ s.size() - 1 ] - '0';
		cout << "\n" << lastDigit( a , b );
	}
	return 0;
}
