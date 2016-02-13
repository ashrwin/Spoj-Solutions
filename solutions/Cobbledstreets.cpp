#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define MAX (1<<30)
using namespace std;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int prim( const vvii &g , int source )
{
	int ret = 0;
	vector<bool> visited( g.size() , false );
	vi dist( g.size() ,MAX );
	set<ii> q;
	for ( int i = 1; i < g.size(); ++i )
		if (i!=source )
			q.insert( mp( dist[ i ] , i ) );
	dist[ source ] = 0;
	q.insert( mp( dist[ source ] , source ) );
		while ( !q.empty() )
	{
		int u = (*q.begin()).second;
		ret += ( *q.begin() ).first;
		q.erase( q.begin() );
		visited[ u ] = true;
		for ( vii::const_iterator it = g[u].begin(); it!=g[u].end();++it)
		{
			int v = it->first;
			int cost = it->second;
			if ( !visited[ v ] && cost < dist[ v ] )
			{
				q.erase( q.find( mp(dist[v],v) ) );
				dist[ v ] = cost;
				q.insert( mp( dist[ v ] , v ) );
			}
		}
	}


	return ret;
}

int main()
{
	int t,p,a,b,c,v,e;
	scanf( "%d" , &t);
	while ( t-- )
	{
		scanf( "%d%d%d" , &p , &v , &e );
		vvii G(v+1);
		while ( e-- )
		{
			scanf( "%d%d%d" , &a , &b , &c );
			G[ a ].pb( mp( b , c*p ) );
			G[ b ].pb( mp( a , c*p ) );
		}
		printf( "\n%d" , prim( G , 1 ) );

	}
	return 0;
}