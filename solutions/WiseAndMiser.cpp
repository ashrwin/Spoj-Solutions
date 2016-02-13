#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
typedef unsigned long long int ll;

int a[ 102 ][ 102 ] , dp[ 102 ][ 102 ];

int main()
{
	//ios::sync_with_stdio( false );
	
	int n , m , k;
	cin >> n >> m;
	for ( int i = 0; i < n; ++i )
		for ( int j = 0; j < m; ++j )
		{
			cin >> a[ i ][ j ];
			dp[ i ][ j ] = 1 << 30;
		}
	for ( int i = 0; i < m; ++i )
		dp[ 0 ][ i ] = a[ 0 ][ i ];

	for ( int i = 1; i < n; ++i )
		for ( int j = 0; j < m; ++j )
		{
			int x = ( j>0 ) ? ( dp[ i - 1 ][ j - 1 ] + a[ i ][ j ] ) : 1<<30;
			int y = ( j < m - 1 ) ? ( dp[ i - 1 ][ j + 1 ] + a[ i ][ j ] ) : 1<<30;
			int z = dp[ i - 1 ][ j ] + a[ i ][ j ];
			dp[ i ][ j ] = min( dp[ i ][ j ] , min( x , min( y , z ) ) );
		}
	int ret = 1 << 30;
	for ( int i = 0; i < m; ++i )
		ret = min( ret , dp[ n - 1 ][ i ] );
	cout << "\n" << ret;
	return 0;
}