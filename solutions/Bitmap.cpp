#include<iostream>
#include<vector>
#include<stdlib.h>
#include<queue>
using namespace std;

typedef vector< vector<int> > vvi;
int n , m;
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0 , 1 , 0 , -1 };

void shortestPaths( int ans[][300] , queue< pair<int,int> > &q)
{
	pair<int , int> current;
	bool visited[ 300 ][ 300 ] = { false };
	while ( !q.empty() )
	{
		current = q.front();
		q.pop();
		visited[current.first][current.second] = true;
		for ( int i = 0; i < 4; ++i )
		{
			int x = current.first + dx[ i ];
			int y = current.second + dy[ i ];
			if ( x>=0 && x < n && y>=0 && y < m )
			{
				if ( ans[ x ][ y ]!=0 && !visited[ x ][ y ]  && ans[current.first][current.second] +1 < ans[x][y]     ) 
				{
					ans[ x ][ y ] = ans[ current.first ][ current.second ] + 1;
					q.push( make_pair( x , y ) );
				}
			}
		}

	}
	
	for ( int i = 0; i < n; i++ )
	{
		cout << "\n";
		for ( int j = 0; j < m; ++j )
			cout << ans[ i ][ j ] << " ";
	}


}

int main()
{
	int t;
	char c;
	cin >> t;

	for ( int i = 0; i < t; ++i )
	{
		cin >> n >> m;
		int ans[300][300]; 
		queue< pair<int , int> > q;
		for ( int j = 0; j < n; j++ )
			for ( int k = 0; k < m; ++k )
			{
				cin >> c;
				if ( c - '0' == 1 )
				{
					ans[ j ][ k ] = 0;
					q.push( make_pair(j,k) );
				}
				else ans[ j ][ k ] = 100000;
			}
		
		shortestPaths( ans,q );
	}
	return 0;
}

