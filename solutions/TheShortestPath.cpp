#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#define mp make_pair
#define pb push_back
#define MAX (1<<30)
using namespace std;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;


int dijkstra( const vvii &g , const int s , const int d )
{
	const int n = (int)g.size();
	vi dist( n , MAX );
	vi parent( n , -1);
	set<ii> pq;
	for ( int i = 1; i < g.size(); ++i )
		if ( i != s )
			pq.insert( mp( dist[ i ] , i ) );
	dist[ s ] = 0;
	parent[ s ] = -1;
	pq.insert( mp( dist[ s ] , s ) );
	while ( !pq.empty() )
	{
		int u = pq.begin()->second;
		pq.erase( pq.begin() );
		for ( vii::const_iterator it = g[ u ].begin(); it != g[u].end(); ++it )
		{
			int v = it->first;
			int cost = it->second;
			if ( dist[ v ]> dist[ u ] + cost )
			{
				pq.erase( pq.find( mp( dist[ v ] , v ) ) );
				dist[ v ] = dist[ u ] + cost ;
				parent[ v ] = u;
				pq.insert( mp( dist[ v ] , v ) );
			}
		}
	}
	return dist[ d ];
}



int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	while ( t-- )
	{
		int n;
		cin >> n;
		vvii g( n + 1 );
		map < string , int > m;
		for ( int i = 1; i <= n; ++i )
		{
			string s;
			cin >> s;
			m[ s ] = i;
			int p;
			cin >> p;
			while ( p-- )
			{
				int v , cost;
				cin >> v >> cost;
				g[ i ].pb( mp( v , cost ) );
			}
		}
		int x;
		cin >> x;
		while ( x-- )
		{
			string a , b;
			cin >> a >> b;
			cout << "\n" << dijkstra( g , m[ a ] , m[ b ] );
		}
	}
	return 0;
}