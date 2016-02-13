#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef long long ull;


ull gcd( ull a , ull b )
{
	if ( !b ) return a;
	return gcd( b , a%b );
}

ull lcm( ull a , ull b )
{
	return 	( a*b ) / gcd( a , b );

}


ull lmin( const string &s )
{
	ull ret=1;
	vector<int> check;
	if ( s[ 0 ] == 'N' ) return -1;
	for ( int i = 0; i < s.size(); ++i )
	{
		if ( s[ i ] == 'Y' )
		{
			int val = i + 1;
			ret = lcm( ret , val );
			int x;
		}
		else check.push_back( i + 1 );
	}
	
	if ( ret == 1 ) return (s[ 0 ] == 'Y') ? 1 : -1;
	
	for ( int i = 0; i < check.size(); ++i )
		if ( ret%check[ i ] == 0 )
			return -1;
	return ret;
}





int main()
{
	//ios::sync_with_stdio( false );
	string s;
	while ( true )
	{
		cin >> s;
		if ( s == "*" ) return 0;
		cout << "\n" << lmin( s );
	}
	return 1;
}