#include<iostream>
#include<algorithm>
#define INF 1000009
using namespace std;
int a[ 100005 ][ 3 ];
int dp[ 100005 ][ 3 ];

int main()
{
		ios::sync_with_stdio( false );
	int r,c=3;
	int t = 0;
	while ( 1 )
	{
		cin >> r;
		if ( !r ) return 0;
		for ( int i = 0; i < r; ++i )
			for ( int j = 0; j < c; ++j )
				cin >> a[ i ][ j ];
		dp[ 0 ][ 0 ] = INF;
		dp[ 0 ][ 1 ] = a[ 0 ][ 1 ];
		dp[ 0 ][ 2 ] = dp[ 0 ][ 1 ] + a[ 0 ][ 2 ];
		for ( int i = 1; i < r; ++i )
		{
			dp[ i ][ 0 ] = dp[ i ][ 1 ] = dp[ i ][ 2 ] = INF;

			dp[ i ][ 0 ] = min( dp[ i ][ 0 ] ,
				min( dp[ i - 1 ][ 0 ] + a[ i ][ 0 ] , dp[ i - 1 ][ 1 ] + a[ i ][ 0 ] ) );
			dp[ i ][ 1 ] = min( dp[ i ][ 1 ] ,
				min( dp[ i - 1 ][ 1 ] + a[ i ][ 1 ] ,
				min( dp[ i - 1 ][ 0 ] + a[ i ][ 1 ] ,
				min( dp[ i - 1 ][ 2 ] + a[ i ][ 1 ] , dp[ i ][ 0 ] + a[ i ][ 1 ] ) ) ) );

			dp[ i ][ 2 ] = min( dp[ i ][ 2 ] ,
				min( dp[ i - 1 ][ 2 ] + a[ i ][ 2 ] ,
				min( dp[ i - 1 ][ 1 ] + a[ i ][ 2 ] , dp[ i ][ 1 ] + a[ i ][ 2 ] ) ) );
		}

		cout << "\n"<<++t<<". "<< dp[ r - 1 ][ 1 ];
	}
	
	return 0;
}




