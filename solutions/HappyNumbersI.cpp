#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
typedef unsigned long long ull;
using namespace std;
set<ull> s;

ull getSquareSum( ull n )
{
	ull ret = 0;
	while ( n )
	{
		ret += ( ( n % 10 )*( n % 10 ) );
		n /= 10;
	}
	return ret;
}

int happy(ull n)
{
	ull k=n;
	for ( int i = 1; ; ++i )
	{
		k = getSquareSum( k );
		if ( s.find( k ) != s.end() )
			return -1;
		s.insert( k );
		if ( k == 1 )
			return i;
	}
	return -1;
}
int main()
{
	ull n;
	cin >> n;
	cout << "\n" <<happy( n );
	return 0;
}