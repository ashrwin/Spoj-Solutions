#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#define mp make_pair
#define pb push_back
#define MAX 1000000
#define INF 0.0
using namespace std;
typedef vector<double> vd;
typedef vector<vd> vvd;

int main()
{
	while ( true ){
		int n , m;
		scanf( "%d" , &n );
		if ( n == 0 )
			break;
		scanf( "%d" , &m );
		vvd dp( n , vd( n ,0) );
		
		while ( m-- ){
			int x , y , v;
			scanf( "%d%d%d" , &x , &y , &v );
			dp[ x - 1 ][ y - 1 ] = v / 100.0;
			dp[ y - 1 ][ x - 1 ] = v / 100.0;
		}
		vvd ans( n , vd( n , 0 ) );
		for ( int i = 0; i<n; i++ ){
			for ( int j = 0; j<n; j++ ){
				ans[ i ][ j ] = dp[ i ][ j ];
			}
		}
		
		cout<<endl;
		
		for ( int k = 0; k<n; k++ ){
			for ( int i = 0; i<n; i++ ){
				for ( int j = 0; j<n; j++ ){
					if ( ans[ i ][ k ] * ans[ k ][ j ] > ans[ i ][ j ] ){
						ans[ i ][ j ] = ans[ i ][ k ] * ans[ k ][ j ];
					}
				}
			}
		}
		
		printf( "%.6lf percent\n" , ans[ 0 ][ n - 1 ] * 100.0 );
	}
}
