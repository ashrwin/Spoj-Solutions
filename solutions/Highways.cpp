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
#include <ctime>
#include<string.h>
#include<list>
#include<map>
#include<queue>
#include<set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
#define gc getchar
#define MAX 10000000
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
int dijk( const vvii &g , const int &s , const int &d )
{
	const int n = sz( g );
	vi dist( n , MAX );
	set<ii> pq;
	rep( i , 1 , n  )
		if ( i != s )
			pq.insert( mp( dist[ i ] , i ) );
	dist[ s ] = 0;
	pq.insert( mp( dist[ s ] ,s  ) );
	while ( !pq.empty() )
	{
		int u = pq.begin()->second;
		pq.erase(pq.begin());
		for ( vii::const_iterator it = g[ u ].begin(); it != g[ u ].end(); ++it )
		{
			int v = it->first;
			int cost = it->second;
			if ( dist[ u ] + cost < dist[ v ] )
			{
				pq.erase( mp( dist[ v ] , v ) );
				dist[ v ] = dist[ u ] + cost;
				pq.insert( mp( dist[ v ] , v ) );
			}
		}
	}
	return dist[ d ];
}
int main()
{
	int t;
	sf( t );
	till( t )
	{
		int v , e , s , d;
		scanf( "%d%d%d%d" , &v , &e , &s , &d );
		vvii g( v + 1 );
		rep( i , 0 , e )
		{
			int u , v , c;
			sf( u ); sf( v ); sf( c );
			g[ u ].push_back( mp( v , c ) );
			g[ v ].push_back( mp( u , c ) );
		}
		int ans = dijk( g , s , d );
		if (ans!=MAX )
			printf( "\n%d" , ans );
		else printf( "\nNONE" );
	}
	return 0;
}