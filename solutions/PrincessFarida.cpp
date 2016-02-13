#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
using namespace std;
long long a[ 10002 ];
long long dp[ 10002 ];
long long monster( int n )
{
	dp[ 0 ] = a[ 0 ];
	dp[ 1 ] = max( dp[ 0 ] , a[ 1 ] );
	for ( int i = 2; i < n; ++i )
		dp[ i ] = max( dp[ i - 1 ] , a[ i ] + dp[ i - 2 ] );
	return dp[ n - 1 ];
}


int main()
{
	int t;
	scanf( "%d" , &t );
	for ( int z = 1; z <= t;++z )
	{
		int m;
		scanf( "%d" , &m );
		for ( int i = 0; i < m; ++i )
			scanf( "%lld" , &a[i] );
		printf( "\nCase %d: %lld" ,z, monster( m ) );
	}
}