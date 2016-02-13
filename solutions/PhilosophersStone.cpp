#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef vector< vector<int> > vvi;
typedef unsigned long long ull;
int r , c;

int max( int a , int b , int c , int d )
{
	int v[] = { a , b , c , d };
	return *max_element( v , v+4 );
}

ull dp_stone( const vvi &v )
{ 
    vvi dp( r , vector<int>( c , -1 ) );
	for ( int i = 0; i < c ; ++i )
		dp[0][i] =v[ 0 ][ i ] ;
	for ( int i = 1; i < r; ++i )
	{
		for ( int j = 0; j < c; ++j )
		{
			dp[ i ][ j ] = max(
				dp[ i ][ j ] ,
				v[ i ][ j ] + dp[ i - 1 ][ j ] ,
				v[ i ][ j ] + ( ( j > 0 ) ? dp[ i - 1 ][ j - 1 ] : 0 ),
				v[ i ][ j ] + ( ( j < c-1 ) ? dp[ i - 1 ][ j + 1 ] : 0 )
				);
		}
	}
	int ret = -1;
	for ( int i = 0; i < c; ++i )
		ret = std::max( ret , dp[ r - 1 ][ i ] );
	return ret;
}


int main()
{
	int t;
		cin >> t;
	for ( int i = 0; i < t; ++i )
	{
		cin >> r >> c;
		vvi v( r , vector<int>( c ) );
		for ( int j = 0; j < r; j++ )
			for ( int k = 0; k < c; ++k )
				cin >> v[ j ][ k ];
		cout << "\n" << dp_stone( v );
	}

	return 0;
}