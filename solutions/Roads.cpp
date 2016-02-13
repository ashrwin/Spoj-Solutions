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

struct node
{
	int pos , len , cost;
	bool operator<( const node &a )const
	{
		if ( a.len == len && a.cost == cost )return pos < a.pos;
		if ( a.len == len )return cost < a.cost;
		return len < a.len;
	}
	node( int pos , int len , int cost )
	{
		this->pos = pos; this->len = len; this->cost = cost;
	}
};

int k , n , r;
vector< vector< pair <int , ii > > > g;
int dijkstra()
{
	bool vis[ 101 ][ 10001 ] = { false };
	set<node> pq;
	memset( vis , 0 , sizeof( vis ) );
	pq.insert( node( 1 , 0 , 0 ) );
	while ( !pq.empty() )
	{
		node aux = *pq.begin();
		pq.erase( pq.begin() );
		if ( aux.pos == n )return aux.len;
		if ( vis[ aux.pos ][ aux.cost ] )continue;
		vis[ aux.pos ][ aux.cost] = true; 
		//adj
		for ( int i = 0; i < sz( g[ aux.pos ] );++i )
		{ 
			pair<int , ii> p = g[ aux.pos ][ i ];		
			int pos2 = p.first;
			int len2 = p.second.first+aux.len;
			int cost2 = p.second.second+aux.cost;
			if ( cost2 <= k )
				pq.insert( node( pos2 , len2 , cost2 ) );
		}
	}
	return -1;
}


int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		cin >> k >> n >> r;
		g = vector< vector <pair <int , ii > > >( n + 1 );
		rep( i , 0 , r )
		{
			int s , d , l , toll;
			cin >> s >> d >> l >> toll;
			g[ s ].push_back( mp( d , mp( l , toll ) ) );
		}
		cout << dijkstra() << "\n";
	}

	return 0;
}