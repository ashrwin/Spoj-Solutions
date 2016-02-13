/**/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;

int map[ 'm'+2 ];
char rmap[ 1001 ];
void init()
{
	map[ 'm' ] = 1000;
	map[ 'c' ] = 100;
	map[ 'x' ] = 10;
	map[ 'i' ] = 1;
	rmap[ 1000 ] = 'm';
	rmap[ 100 ] = 'c';
	rmap[ 10 ] = 'x';
	rmap[ 1 ] = 'i';

}
int mcx2int( const string &s )
{
	int ret = 0 , temp = 1;
	for ( int i = 0; i < s.size(); ++i )
	{
		if ( isdigit( s[ i ] ) )
		{
			temp += ( s[ i ] - '0' - 1 );
		}
		else
		{
			temp *= map[ s[ i ] ];
			ret += temp;
			temp = 1;
		}
	}
	return ret;
}

string int2mcx( int a )
{
	stringstream ss;
	int x = 1000 , m;
	while ( x )
	{
		if ( ( m = a / x ) )
		{
			if ( m > 1 )
				ss << m << rmap[ x ];
			else ss << rmap[ x ];
		}
		a %= x;
		x /= 10;
	}
	return ss.str();
}

int main()
{
	ios::sync_with_stdio( false );
	init();
	int t;
	cin >> t;
	string a , b;
	while ( t-- )
	{
		cin >> a >> b;
		cout << "\n" << int2mcx( mcx2int( a ) + mcx2int( b ) );
	}
	return 0;
}


