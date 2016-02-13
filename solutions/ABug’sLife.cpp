#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<memory>
#include<stdlib.h>
#include<stack>
#define INF 1000009
#define red true
#define black false
using namespace std;
typedef vector< vector<int> > vvi;
vvi v;
bool visited[ 2002 ];
bool color[ 2002 ];
int t , n , s;
bool dfs()
{
	for ( int i = 1; i <= n; ++i )
	{
		if ( !visited[ i ] )
		{
			stack<int> st;
			st.push( i );
			while ( !st.empty() )
			{
				int cur = st.top();
				st.pop();
				visited[ cur ] = true;
				for ( vector<int>::iterator it = v[ cur ].begin() ; it != v[ cur ].end() ; ++it )
					if ( !visited[ *it ] )
					{
					color[ *it ] = !color[ cur ];
					st.push( *it );
					}
					else if ( color[ *it ] == color[ cur ] )
							return false;
					
			}
		}
	}
	
	return true;

}



int main()
{
	
	//ios::sync_with_stdio( false );
	scanf( "%d" , &t );
	for ( int z = 0; z < t;++z )
	{
		scanf( "%d%d" , &n , &s );
		v = vvi( n+1 );
		for ( int i = 0; i < s; ++i )
		{
			int x , y;
			scanf("%d%d",&x,& y);
			v[ x ].push_back( y );
			v[ y ].push_back( x );
		}
		memset( visited , 0 , 2002 );
		memset( color , 0 , 2002 );
		printf( "\nScenario #%d:\n" ,z+1);
		if ( dfs() )
			printf("No suspicious bugs found!");
		else printf("Suspicious bugs found!");
		
	}
	
	return 0;
}




