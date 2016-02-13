#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stdio.h>
#include<memory>
using namespace std;
typedef vector< vector<int> > vvi;
vvi adj;
bool visited[ 15001 ] ;
int parent[ 15001 ];
string isTree( int n )
{
	queue<int> q;
	q.push( 1 );
	memset( visited , 0 , 15001 );
	memset( parent , 0 , 15001 );
	int nodesvisited = 0;
	while ( !q.empty() )
	{
		int c = q.front();
		q.pop();
		visited[ c ] = true;
		nodesvisited++;
		for ( vector<int>::iterator it = adj[ c ].begin(); it != adj[c].end() ; ++it )
		{
			if ( !visited[ *it ] )
			{
				parent[ *it ] = c;
				q.push( *it );
			}
			else if ( *it != parent[ c ] ) return "NO";
		}
		
	}
	if ( nodesvisited != n )
		return "NO";
	return "YES";

}


int main()
{
	std::ios::sync_with_stdio( false );
	int n , m,u,v;
	cin >> n >> m;
	adj= vvi( n+1 );
	for ( int i = 0; i < m; ++i )
	{
		cin >> u >> v;
		adj[ u ].push_back( v );
		adj[ v ].push_back( u );
	}
	cout << "\n" << isTree(n);
	return 0;
}