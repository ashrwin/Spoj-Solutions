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
typedef unsigned long long ull;


ull gcd( ull a , ull b )
{
	if ( !b ) return a;
	return gcd( b , a%b );
}

inline ull lcm( ull a , ull b )
{
	return 	( a*b ) / gcd( a , b );
}


ull smin( ull &a, ull &b)
{
	ull l = lcm( a , b );
	return ( l / a )*( l/b );
}





int main()
{
	ios::sync_with_stdio( false );
	ull h , w;
	while ( true )
	{
		cin >> h >> w;
		if ( !h&& !w ) return 0;
		cout << "\n" << smin( h , w );
	}
	return 0;
}