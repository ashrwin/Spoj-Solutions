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
	int pos , time;
	bool operator<( const node &c ) const
	{
		return c.time < time;
	}
	node( int p , int t )
	{
		pos = p; time = t;
	}
};

int n , m;

vvi g;
int dijkstra()
{
	node src( 1 , 0 );
	bool vis[ 60000 ] = { false };
	priority_queue<node> pq;
	pq.push( src );
	while ( !pq.empty() )
	{
		node aux = pq.top();
		pq.pop();

		if ( vis[ aux.pos ] )continue;
		if ( aux.pos == n )return aux.time;
		vis[ aux.pos ] = true;
		int tim = aux.time;
		for ( int v : g[ aux.pos ] )
		{
			int mul = abs( v - aux.pos ) * 5;
			if ( v > aux.pos )
			{
				int mt = abs( aux.pos - v ) * 5;
				int K = ceil( double(tim) / mt );
				if ( K % 2 )++K;
				pq.push( node( v , K*mt + mul ) );

			}
			else
			{
				int mt = abs( aux.pos - v ) * 5;
				int K = ceil( double(tim) / mt );
				if ( K % 2 ==0)++K;
				pq.push( node( v , K*mt + mul ) );
			}

		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio( false );
	cin >> n >> m;
	g = vvi( n + 1 );
	rep( i , 0 , m )
	{
		int x , y;
		cin >> x >> y;
		g[ x ].push_back( y );
		g[ y ].push_back( x );
	}
	cout << dijkstra() << "\n";
	return 0;
}
