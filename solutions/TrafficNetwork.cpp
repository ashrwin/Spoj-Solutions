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

struct node
{
	int v , dist ;
	bool inc;
	node( int v = 0 , int dist = 0 , bool inc = 0 )
	{
		this->v = v; this->dist = dist; this->inc = inc;
	}
	bool operator<( const node &b )const
	{
		return b.dist < dist;
	}
};


node src , dest;
int n , m , k , sr , dt;
vvii g;
vvii kroads;
int dijkstra()
{
	priority_queue<node> pq;
	bool vis[ 12000 ][ 2 ] = { false };
	pq.push( src );
	while ( !pq.empty() )
	{
		node aux = pq.top();
		pq.pop();
		if ( vis[ aux.v ][ aux.inc ] )continue;
		if ( aux.v == dest.v )return aux.dist;
		vis[ aux.v ][ aux.inc ] = true;
		//adj
		for ( ii p : g[ aux.v ] )
		{
			int V = p.first , D = aux.dist + p.second;
			pq.push( node( V , D , aux.inc ) );
		}
		if ( !aux.inc )
			for ( ii p : kroads[ aux.v ] )
			{
			int V = p.first , D = aux.dist + p.second;
			pq.push( node( V , D , true ) );
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
		cin >> n >> m >> k >> sr >> dt;
		src = node( sr , 0 );
		dest = node( dt , 0 , 0 );
		g = vvii( n + 1 );
		kroads = vvii( n + 1 );
		rep( i , 0 , m )
		{
			int u , v , c;
			cin >> u >> v >> c;
			g[ u ].push_back( mp( v , c ) );
		}
		rep( i , 0 , k )
		{
			int u , v , c;
			cin >> u >> v >> c;
			kroads[ u ].push_back( mp( v , c ) );
			kroads[ v ].push_back( mp( u , c ) );
		}
		cout << dijkstra() << "\n";
	}
	return 0;
}
