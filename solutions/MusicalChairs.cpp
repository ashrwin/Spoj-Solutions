/**/
#include<iostream>
using namespace std;
inline int musicdp( int n , int d )
{
	int ret = 0;
	for ( int i = 2; i <= n; ++i )
		ret= ( ret + d ) % i;
	return ret+1 ;
}

int main()
{
	int n , d;
	while ( true )
	{
		scanf( "%d%d" , &n , &d );
		if ( !n && !d ) return 0;
		printf( "\n%d %d %d" , n , d , musicdp( n , d ) );
	}
	return 1;
}


