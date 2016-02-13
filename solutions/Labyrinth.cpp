/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int l1[ 1005 ][ 1005 ];
int l2[ 1005 ][ 1005 ];

pair< int , pair<int,int> >  dfs(int lab[1005][1005], pair<int , int> start , int r , int c )
{
	int dx[] = { -1 , 0 , 1 , 0 };
	int dy[] = { 0 , 1 , 0 , -1 };
	int ret = 0,mx=start.first,my=start.second;
	pair< int , pair<int , int> > retp = make_pair( ret , start );
	stack< pair<int , int> > s;
	lab[ start.first ][ start.second ] = 0;
	s.push( start );
	while ( !s.empty() )
	{
		pair<int , int > cur = s.top();
		s.pop();
		//adj
		for ( int i = 0; i < 4; ++i )
			for ( int j = 0; j < 4; ++j )
			{
			int x = cur.first + dx[ i ];
			int y = cur.second + dy[ i ];
			if ( x >= r || y >= c || x < 0 || y < 0 )
				continue;
			if ( lab[ x ][ y ] == -1 )
			{
				s.push( make_pair( x , y ) );
				lab[ x ][ y ] = lab[ cur.first ][ cur.second ] + 1;
				if ( lab[ x ][ y ] > ret ){

					ret = lab[ x ][ y ] ;
					mx = x ;
					my= y ;
				}
			}
			}
	}
	return make_pair( ret , make_pair( mx , my ) );
}




int main()
{
	ios::sync_with_stdio( false );
	int t , c , r;
	pair<int , int> start;
	cin >> t;
	bool found ;
	while ( t-- )
	{
		found = false;
		cin >> c >> r;
		for ( int i = 0; i < r; ++i )
			for ( int j = 0; j < c; ++j )
			{
			char c;
			cin >> c;
			if ( c == '#' )
				l1[ i ][ j ] = -2;
			else {
				if ( !found ){
					found = true;
					start = make_pair( i , j );
				}
				l1[ i ][ j ] = -1;
			}
				l2[ i ][ j ] = l1[ i ][ j ];
			}
			pair<int,int > sstart=dfs( l1 , start , r , c ).second;
			cout << "\nMaximum rope length is "<< dfs( l2, sstart,    r,c).first<<".";
		
	}

	return 0;
}





