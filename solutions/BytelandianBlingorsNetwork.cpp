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
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int prim( vvii &g , int s )
{
	int ret = 0;
	int n = sz( g );
	set<ii> pq;
	vi dist( g.size() , 1000000 );
	vector<bool> vis( g.size() , false );
	for ( int i = 1; i < n; ++i )
		if ( i != s )
			pq.insert( mp( dist[ i ] , i ) );
	dist[ s ] = 0;
	pq.insert( mp( dist[ s ] , s ) );
	while ( !pq.empty() )
	{
		int u = pq.begin()->second;
		ret += pq.begin()->first;
		pq.erase( pq.begin() );
		vis[ u ] = true;
		for ( vii::iterator it = g[ u ].begin(); it != g[ u ].end(); ++it )
		{
			int v = it->first;
			int cost = it->second;
			if ( !vis[ v ] && cost < dist[ v ] )
			{
				pq.erase( pq.find( mp( dist[ v ] , v ) ) );
				dist[ v ] = cost;
				pq.insert( mp( dist[ v ] , v ) );
			}
		}
	}
	return ret;
}





int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		map<string , int> m;
		int n;
		cin >> n;
		vvii g( n + 1 );
		rep( i , 0 , n )
		{
			string name;
			cin >> name;
			m[ name ] = i + 1;
			int p;
			cin >> p;
			till( p )
			{
				int ne , cost;
				cin >> ne >> cost;
				g[ i + 1 ].push_back( mp( ne , cost ) );
				g[ ne ].push_back( mp( i + 1 , cost ) );
			}
		}
		cout << "\n" << prim( g , 1 );
	}

	return 0;

}