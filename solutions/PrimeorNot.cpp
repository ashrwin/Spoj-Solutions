/**/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>

using namespace std;
typedef unsigned long long ull;

ull modMultiply( ull a , ull b ,ull c)
{
	ull ret = 0;
	a %= c;
	while ( b )
	{
		if ( b & 1 )
			ret = ( ret + a ) % c;
		a = ( a <<1 ) % c;
		b >>= 1;
	}
	return ret%c;
}

ull modExp( ull base , ull exp , ull mod )
{
	ull ret = 1;
	while ( exp )
	{
		if ( exp & 1 )
			ret = modMultiply( ret , base , mod );
		base = modMultiply( base , base , mod );
		exp >>= 1;
	}
	return ret;
}


ull getRandom( const ull &a )
{
	return ( (double)rand() / ( RAND_MAX + 1 ) ) * ( a - 1 - 1 + 1 ) + 1;
}

string fprime( ull p ,int k)
{
	if ( p == 1 || (p>2 && p%2==0)    ) return "NO";
	while ( k-- )
	{
		ull x = getRandom( p );
		if ( modExp( x , p - 1 , p ) != 1 )
			return "NO";
	}
	return "YES";
}





int main()
{
	int t;
	scanf( "%d" , &t );
	ull p;
	while ( t-- )
	{
		scanf( "%llu" , &p );
		printf( "\n%s" , fprime( p , 2 ).c_str() );
	}
	return 0;
}




