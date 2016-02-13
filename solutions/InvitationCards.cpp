#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <ctime>
//#include<unordered_set>
//#include<unordered_map>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar
#define pc putchar
#define MAX 1000010
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;

int p , q;
int dijkstra( const vvii &g , const int s )
{
	const int n = (int)g.size();
	vi dist( n , MAX );
	set<ii> pq;
	for ( int i = 1; i < g.size(); ++i )
		if ( i != s )
			pq.insert( mp( dist[ i ] , i ) );
	dist[ s ] = 0;
	pq.insert( mp( dist[ s ] , s ) );
	while ( !pq.empty() )
	{
		int u = pq.begin()->second;
		pq.erase( pq.begin() );
		for ( vii::const_iterator it = g[ u ].begin(); it != g[ u ].end(); ++it )
		{
			int v = it->first;
			int cost = it->second;
			if ( dist[ v ]> dist[ u ] + cost )
			{
				pq.erase( pq.find( mp( dist[ v ] , v ) ) );
				dist[ v ] = dist[ u ] + cost ;
				pq.insert( mp( dist[ v ] , v ) );
			}
		}
	}
	int ret = 0;
	rep( i , 1 , n ) if ( i != s )ret += dist[ i ];		
	return ret;
}


int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		cin >> p >> q;
		vvii g( p + 1 ) , gt( p + 1 );
		rep( i , 0 , q )
		{
			int u , v , c;
			cin >> u >> v >> c;
			g[ u ].push_back( mp( v , c ) );
			gt[ v ].push_back( mp( u , c ) );
		}

		cout << dijkstra( g , 1 ) + dijkstra( gt , 1 )<<"\n";
	}
	return 0;
}
