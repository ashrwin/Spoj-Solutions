#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define mp make_pair
using namespace std;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef pair<int , ii> iii;
const int dx[ 4 ] = { -1 , 0 , 1 , 0 };
const int dy[ 4 ] = { 0 , 1 , 0 , -1 };
int dijkstra( const ii &s , const ii &d , const int h , const int w , char maze[ 30 ][ 30 ] )
{
	int dist[ 30 ][ 30 ];
	for ( int i = 0; i < 30; ++i )
		for ( int j = 0; j < 30; ++j )
			dist[ i ][ j ] = ( 1 << 30 );
	set<iii> pq;
	dist[ s.first ][ s.second ] = 0;
	pq.insert( mp( dist[ s.first ][ s.second ] , s ) );
	while ( !pq.empty() )
	{
		ii u = pq.begin()->second;
		pq.erase( mp( dist[ u.first ][ u.second ] , u ) );
		//adj
		for ( int i = 0 ; i < 4; ++i )
		{
			int i1 = u.first + dy[ i ];
			int j1 = u.second + dx[ i ];
			if ( j1 >= w || i1 >= h || j1 < 0 || i1 < 0 || maze[ i1 ][ j1 ] == 'X' )
				continue;
			ii v = mp( i1 , j1 );
			if ( dist[ v.first ][ v.second ]> dist[ u.first ][ u.second ] + ( maze[ v.first ][ v.second ] - '0' ) )
			{
				if ( pq.find( mp( dist[ v.first ][ v.second ] , v ) ) != pq.end() )
					pq.erase( mp( dist[ v.first ][ v.second ] , v ) );
				dist[ v.first ][ v.second ] = dist[ u.first ][ u.second ] + maze[ v.first ][ v.second ] - '0';
				pq.insert( mp( dist[ v.first ][ v.second ] , v ) );
			}
		}
	}
	return dist[ d.first ][ d.second ];
}

int main()
{
	ios::sync_with_stdio( false );
	int w , h;
	while ( 1 )
	{
		char maze[ 30 ][ 30 ];
		for ( int i = 0; i < 30; ++i )
			for ( int j = 0; j < 30; ++j )
				maze[ i ][ j ] = 'X';
		cin >> w >> h;
		ii s , d;
		if ( !w && !h ) return 0;
		for ( int i = 0; i < h; ++i )
			for ( int j = 0; j < w; ++j )
			{
			cin >> maze[ i ][ j ];
			if ( maze[ i ][ j ] == 'S' )
			{
				maze[ i ][ j ] = '0';
				s = mp( i , j );
			}
			else if ( maze[ i ][ j ] == 'D' )
			{
				maze[ i ][ j ] = '0';
				d = mp( i , j );
			}
			}
		cout << "\n" << dijkstra( s , d , h , w , maze );
	}
	return 0;
}